function updateMatrix(mat: number[][]): number[][] {
    const queue: number[][] = [];
    const rows = mat.length, cols = mat[0].length;
    const visited: number[][] = Array.from({ length: rows }, () => {
        return Array.from({ length: cols }, () => 0)
    });
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (mat[i][j] === 0) {
                queue.push([i, j]);
                visited[i][j] = 1;
            }
        }
    }

    while (queue.length) {
        const rear: number[] = queue.shift() as number[];
        const dx = [-1, 0, 0, 1];
        const dy = [0, -1, 1, 0];

        for (let j = 0; j < 4; j++) {
            let newX = rear[0] + dx[j];
            let newY = rear[1] + dy[j];
            if (
                newX >= 0
                && newX < rows
                && newY >= 0
                && newY < cols
                && mat[newX][newY] !== 0
                && visited[newX][newY] !== 1
            ) {
                visited[newX][newY] = 1;
                mat[newX][newY] = mat[rear[0]][rear[1]] + 1;
                queue.push([newX, newY]);
            }
        }

    }

    return mat;
};

const mat = [
    [0, 1, 0, 1],
    [1, 0, 0, 0],
    [1, 1, 1, 1],
    [1, 1, 1, 1]
];
const res = updateMatrix(mat);

console.log(JSON.stringify(res));
