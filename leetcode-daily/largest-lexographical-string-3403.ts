function answerString(word: string, numFriends: number): string {
    if (numFriends === 1) return word;

    let n = word.length;
    let maxPossibleLen = n - numFriends + 1; /* The main catch is this line. 
    for largest possible string we are considering we have to assign atleast one character to all fand last friend will get remaining charcters.
    Sp, to that last friend we have this many length of substring remaining.
    n - (numFriends - 1) = n - nF + 1
    */
    let res = "";
    for (let i = 0; i < n; i++) {
        const subStr = word.slice(i, i + maxPossibleLen);
        if (subStr > res)
            res = subStr;
    }

    return res;
};
