/** Approach
    // identify the number of components 

    // store node index for included in particular component

    // store the number of nodes in each component

    // check all the node's of each component. all the nodes should have 
            // adjustnodes = (total number of nodes for taht component - 1)
 */

const traverse = (
    node: number,
    adj: number[][],
    visited: number[],
    nodesOfComponent: number[][],
    n: number,
    currentComponent: number,
    adjNodes: number[]
) => {
    const queue = [];
    queue.push(node);
    visited[node] = 1;
    nodesOfComponent[currentComponent].push(node);
    let traversalVisited: number[][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => 0)
    );

    // bfs
    while (queue.length) {
        const rear: number = queue.shift() as number;

        for (let i = 0; i < n; i++) {
            if (adj[rear][i] && rear > i) {
                adjNodes[rear]++;
                adjNodes[i]++;
            }
            if (adj[rear][i] && !traversalVisited[rear][i] && !traversalVisited[rear][i] && !visited[i]) {
                queue.push(i);
                traversalVisited[rear][i] = 1;
                traversalVisited[i][rear] = 1;

                // problem specific changes
                visited[i] = 1;
                nodesOfComponent[currentComponent].push(i);
            }
        }
    }
}

function countCompleteComponents(n: number, edges: number[][]): number {
    // initialize adj matrix
    let adj: number[][] = Array.from({ length: n }, () =>
        Array.from({ length: n }, () => 0)
    );
    let visited: number[] = Array.from({ length: n }, () => 0);
    let adjNodes: number[] = Array.from({ length: n }, () => 0);

    // prepare adjcency matrix
    for (let i = 0; i < edges.length; i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }

    // store node index for included in particular component
    let nodesOfComponent: number[][] = [];
    let currentComponent = -1;
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            nodesOfComponent.push([]);
            currentComponent++;
            traverse(i, adj, visited, nodesOfComponent, n, currentComponent, adjNodes);
        }
    }
    
    // console.log({
    //     nodesOfComponent,
    //     visited,
    //     adjNodes
    // });

    /**
        check all the node's of each component. all the nodes should have 
            adjustnodes = (total number of nodes for taht component - 1)
     */
    let completeComponents = 0;
    for (let componentInd = 0; componentInd < nodesOfComponent.length; componentInd++) {
        const component = nodesOfComponent[componentInd];
        const expectedAdjNodes = component.length - 1;
        let isComplete = true;
        component.forEach(node => {
            if (adjNodes[node] !== expectedAdjNodes) {
                isComplete = false;
                return;
            }
        })

        if (isComplete) {
            completeComponents++;
        }
    }
    
    return completeComponents;
};

const n = 6;
const edges = [[0, 1], [0, 2], [1, 2], [3, 4]];
// const edges = [[0, 1], [0, 2], [1, 2], [3, 4], [3, 5]]

const result = countCompleteComponents(n, edges);
console.log({ result });


