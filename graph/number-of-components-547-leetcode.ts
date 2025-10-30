/*
* This is a num of provinence problem only
*/
const traverse = (
    node: number,
    adj: number[][],
    visited: number[],
    n: number
) => {
    const queue = [];
    queue.push(node);
    visited[node] = 1;
    let traversalVisited: number[][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => 0)
    );

    // bfs
    while (queue.length) {
        const rear: number = queue.shift() as number;

        for (let i = 0; i < n; i++) {
            if (adj[rear][i] && !traversalVisited[rear][i] && !traversalVisited[rear][i] && !visited[i]) {
                queue.push(i);
                traversalVisited[rear][i] = 1;
                traversalVisited[i][rear] = 1;

                // problem specific changes
                visited[i] = 1;
            }
        }
    }
}


function findCircleNum(isConnected: number[][]): number {
    const n = isConnected.length;
    let visited: number[] = Array.from({ length: n }, () => 0);

    let components = 0;
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            traverse(i, isConnected, visited, n);
        }
    }

    return components;
};
