function numEnclaves(grid: number[][]): number {
    const queue: number[][] = [];
    const rows = grid.length;
    const cols = grid[0].length;
    let total1s = 0, traversed1s = 0;;
    let visited: number[][] = Array.from({ length: rows }, () => {
        return Array.from({ length: cols }, () => 0)
    });

    // add 1s to edge in queue & count total number of 1s
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 1) {
                total1s++;
            }
            if ((i === 0 
                || i === rows - 1 
                || j === 0 
                || j === cols - 1) &&
                grid[i][j] === 1
            ) {
                queue.push([i,j]);
                visited[i][j] = 1;
                traversed1s++;
            }
        }
    }

    // Traverse & count all edge connected 1s
    const dx = [-1, 0, 0, 1];
    const dy = [0, -1, 1, 0];
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
                && grid[newX][newY] === 1
                && visited[newX][newY] !== 1
            ) {
                visited[newX][newY] = 1;
                traversed1s++;
                queue.push([newX, newY]);
            }
        }
    }

    return total1s - traversed1s;
};
