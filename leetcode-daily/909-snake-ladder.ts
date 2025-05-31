const getCoordinates = (position: number, n: number): { row: number, col: number } => {
    let row: number, col: number = -1, floor = Math.floor(position / n);
    if (position % n == 0) {
        row = (n - 1) - (floor - 1);
    } else {
        row = (n - 1) - floor;
    }

    if (position % n === 0) {
        col = floor % 2 === 0 ? 0 : n - 1;
    } else if (floor % 2 == 0) {
        col = (position % n) - 1      // because they are left to right
    } else if (floor % 2 == 1) {
        col = (n - (position % n))    // because they are right to left
    }

    return { row, col }
}

function snakesAndLadders(board: number[][]): number {
    let minSteps = 0;
    const queue = [1], n = board.length;
    let visited = Array.from({ length: n }, () => Array(n).fill(0));
    visited[n - 1][0] = 1;
    while (queue.length > 0) {
        let size = queue.length;
        while (size > 0) {
            const currValue: number = queue.shift() as number;
            if (currValue === n * n) return minSteps;
            console.log("==========> currValue: ", currValue);
            for (let diceValue = 1; diceValue <= 6; diceValue++) {
                const newPosition = currValue + diceValue;
                if (newPosition > n * n) continue;
                const { row, col } = getCoordinates(newPosition, n);
                console.log({
                    newPosition,
                    row,
                    col,
                    // "visited": visited[row][col]
                })
                if (visited[row][col]) continue;

                visited[row][col] = 1;
                const newValue = board[row][col] === -1 ? newPosition : board[row][col];
                queue.push(newValue);
            }
            size--;
        }
        minSteps++;
    }

    return -1;
};

// const board = [
//     [-1, -1, -1, -1, -1, -1], 
//     [-1, -1, -1, -1, -1, -1], 
//     [-1, -1, -1, -1, -1, -1], 
//     [-1, 35, -1, -1, 13, -1], 
//     [-1, -1, -1, -1, -1, -1], 
//     [-1, 15, -1, -1, -1, -1]
// ]
const board = [
    [-1, -1],
    [-1,  3]
]
console.log("====> minSteps: ", snakesAndLadders(board))


// console.log(getCoordinates(4, 2))

