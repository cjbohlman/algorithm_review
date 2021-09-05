
// O(2^(r+c)) time complexity, O(m+n) space complexity
const gridTravelerFib = (r, c) => {
    // 1x1 grid = 1 
    // 0xn or nx0 grid = 0
    if (r == 0 || c == 0) return 0;
    if (r == 1 || c == 1) return 1;
    const down = gridTravelerFib(r-1, c);
    const right = gridTravelerFib(r, c -1);
    return down + right;
}

// O(r + c) time complexity, O(r+c) space complexity
const gridTraveler = (r, c, memo = {}) => {
    // insight: rxc has the same amount of travels as cxr, order of arguments does not matter
    if (r == 0 || c == 0) return 0;
    if (r == 1 || c == 1) return 1;
    
    if (memo[`${r},${c}`] == undefined && memo[`${c},${r}`] == undefined) {
        const down = gridTraveler(r-1, c, memo);
        const right = gridTraveler(r, c -1, memo);
        memo[`${r},${c}`] = down + right;
        return down + right;
    } else {
        return memo[`${r},${c}`] == undefined ? memo[`${c},${r}`] : memo[`${r},${c}`]
    }
}

console.log(gridTraveler(18,18)) 

const gridTravelerTab = (r, c) => {
    const table = Array(r + 1)
    .fill()
    .map(() => Array(c + 1).fill(0))
    table[1][1] = 1
    for (let i = 0; i <= r; i++) {
        for (let j = 0; j <= c; j++) {
            const current = table[i][j]
            if (j +1 <= c) table[i][j+1] += current
            if (i + 1 <= r) table[i+1][j] += current
        }
    }
    return table[r][c]
}

console.log(gridTravelerTab(18,18)) 