/** 
Main catch of the solution is timer.
that comes in to picture becuase it is possible that we have the key later than we should be able to visit the box.
so we are revisiting every box that can be reachable. but it can end up in infinity loop.
to avoid that infinity loop we used timer here.
*/

function maxCandies(
    status: number[],
    candies: number[],
    keys: number[][],
    containedBoxes: number[][],
    initialBoxes: number[]
): number {
    const n = status.length, queue = initialBoxes;
    let sum = 0, timer = 0;
    const keysMapper = new Map<number, boolean>();
    while (queue.length !== 0) {
        const currBox = queue.shift()!;

        if (status[currBox] || keysMapper.get(currBox)) {
            sum += candies[currBox];

            containedBoxes[currBox].forEach((containedBox) => {
                queue.push(containedBox);
            })

            keys[currBox].forEach(box => {
                keysMapper.set(box, true);
            });
            timer = 0;
        } else {
            queue.push(currBox);
            timer++;
        }

        if (timer > queue.length) break;
    }

    return sum;
};

console.log(
    "results: ", maxCandies(
        [1, 0, 1, 0],
        [7, 5, 4, 100],
        [[], [], [1], []],
        [[2], [3], [], []],
        [0]
    )
)
