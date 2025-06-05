/* findMIn is DFS nothing else */
const findMin = (
    adj: Map<string, string[]>,
    c: string,
    visited: Map<string, boolean>
): string => {
    const adjList = adj.get(c) || [];
    let min = c;
    for (let i = 0; i < adjList.length; i++) {
        const adjNode = adjList[i];
        if (!visited.get(adjNode)) {
            visited.set(adjNode, true);
            const res = findMin(adj, adjNode, visited);
            if (res < min) min = res;
        }
    }

    return min;
}

function smallestEquivalentString(s1: string, s2: string, baseStr: string): string {
    const adj = new Map<string, string[]>();

    for (let i = 0; i < s1.length; i++) {
        const u = s1[i], v = s2[i];
        const adjU = adj.get(u) || [];
        const adjV = adj.get(v) || [];

        adjU.push(v)
        adjV.push(u)

        adj.set(u, adjU);
        adj.set(v, adjV);
    }

    let ans = "";
    for (let i = 0; i < baseStr.length; i++) {
        const c = baseStr[i];
        ans += findMin(adj, c, new Map());
    }

    return ans;
};
