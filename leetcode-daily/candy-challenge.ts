/** In this problrm seeing rank points to use DP 
    Apart from that neighbuor rank matters which is also big sign of DP.
*/
function candy(ratings: number[]): number {
    const n = ratings.length;
    let mapper = new Array(n).fill(1);

    for (let i = 1; i < n; i++) {
        if (ratings[i-1] < ratings[i]) {
            mapper[i] = mapper[i-1] + 1;
        }
    }

    for (let i = n-2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1] && mapper[i] <= mapper[i+1]) {
            mapper[i] = mapper[i+1] + 1;
        }
    }

    return mapper.reduce((ele, sum) => sum + ele, 0)
};
