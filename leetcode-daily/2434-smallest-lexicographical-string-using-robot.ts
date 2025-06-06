
function robotWithString(s: string): string {
    const countMapper: number[] = new Array(26).fill(0);
    let paper = "", str = s;
    const aCharCode = 'a'.charCodeAt(0);

    for (let i = 0; i < str.length; i++) {
        const index = str[i].charCodeAt(0) - aCharCode;
        countMapper[index]++;
    }

    let stack: string[] = [];
    let mapperIndex = 0, sIndex = 0;
    let smallestChar = String.fromCharCode(mapperIndex + aCharCode);

    while (sIndex < str.length) {

        while (countMapper[mapperIndex] === 0) {
            mapperIndex++;
        }

        smallestChar = String.fromCharCode(mapperIndex + aCharCode);

        while (stack.length) {
            const top = stack.at(-1) || ""
            
            if (top <= smallestChar) {
                paper += top;
                stack.pop();
            } else {
                break;
            }
        }

        const curr = str[sIndex++];

        stack.push(curr);

        countMapper[curr.charCodeAt(0) - aCharCode]--;
    }

    paper += stack.reverse().join("")

    return paper;
};

console.log("==========> res: ", robotWithString("bacadb"))
console.log("==========> res: ", robotWithString("zza"))
console.log("==========> res: ", robotWithString("bac"))
console.log("==========> res: ", robotWithString("cbaabc"))
