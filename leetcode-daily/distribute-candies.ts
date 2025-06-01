function distributeCandies(n: number, limit: number): number {
    let result = 0;
    for (let i = 0; i <= Math.min(limit, n); i++) {
        let remaining = n - i;

        if (remaining > 2*limit) continue;

        const maxForSecond = Math.max(0, remaining-limit); // remainig-limit can be negative in case of remaining < limit
        const maxForThird = Math.min(remaining, limit); // in case of remaining < limit max possible value is remaining only

        result += maxForThird - maxForSecond + 1;
    }

    return result;
};
