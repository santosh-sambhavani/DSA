/** Approach
  * Problem : https://leetcode.com/problems/surrounded-regions/
  * Note all Os on edge & change it yo Y + all the Os which can connect with it.
  * Than simply change remaining Os connected to X in to X
 */
function solve(board: string[][]): void {
    const stack: number[][] = [];
    const queue: number[][] = [];
    const rows = board.length;
    const cols = board[0].length;
    let visitedStack: number[][] = Array.from({ length: rows }, () => {
        return Array.from({ length: cols }, () => 0)
    });
    let visitedQueue: number[][] = Array.from({ length: rows }, () => {
        return Array.from({ length: cols }, () => 0)
    });

    // add Os to edge in stack & Xs to queue
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (board[i][j] === 'X') {
                queue.push([i,j]);
                visitedQueue[i][j] = 1;
            }
            if (
                i > 0 
                && i < rows - 1 
                && j > 0 
                && j < cols - 1
            ) continue;
            else if (board[i][j] === 'O') {
                stack.push([i, j]);
                visitedStack[i][j] = 1;
                board[i][j] = 'Y'
            }
        }
    }
    const dx = [-1, 0, 0, 1];
    const dy = [0, -1, 1, 0];

    // change all edge connected Os to Y
    while(stack.length) {
        const top: number[] = stack.pop() as number[];

        for (let j = 0; j < 4; j++) {
            let newX = top[0] + dx[j];
            let newY = top[1] + dy[j];
            if (
                newX >= 0
                && newX < rows
                && newY >= 0
                && newY < cols
                && board[newX][newY] === 'O'
                && visitedStack[newX][newY] !== 1
            ) {
                visitedStack[newX][newY] = 1;
                board[newX][newY] = 'Y';
                stack.push([newX, newY]);
            }
        }
    }

    // change all connected Os to X
    while(queue.length) {
        const rear: number[] = queue.shift() as number[];

        for (let j = 0; j < 4; j++) {
            let newX = rear[0] + dx[j];
            let newY = rear[1] + dy[j];
            if (
                newX >= 0
                && newX < rows
                && newY >= 0
                && newY < cols
                && board[newX][newY] === 'O'
                && visitedQueue[newX][newY] !== 1
            ) {
                visitedQueue[newX][newY] = 1;
                board[newX][newY] = 'X';
                queue.push([newX, newY]);
            }
        }
    }

    // Change all Ys to Os againg
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (board[i][j] === 'Y') {
                board[i][j] = 'O'
            }
        }
    }
};

const board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
solve(board);

console.log(board);
