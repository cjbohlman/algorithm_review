// recursive implementation
// m levels in the tree with n numbers in the array = O(n^m) time
// O(m) space complexity
function canSumRecursive(target, arr) {
    if (target === 0) return true;
    if (target < 0) return false;

    for (let num of arr) {
        const remainder = target - num
        if (canSumRecursive(remainder, arr)) {
            return true;
        }
    }
    return false;
}

// Memoizaiton implementation
// O(m*n) time complexity, o(m*n) space complexity
function canSumMemo(target, arr, cache = {}) {
    if (target === 0) return true;
    if (target < 0) return false;
    if (target in cache) {
        return cache[target]
    }
    for (let num of arr) {
        const remainder = target - num
        if (canSumMemo(remainder, arr, cache)) {
            cache[target] = true;
            return true;
        }
    }
    cache[target] = false
    return false;
}

function canSumTab(target, arr) {
    let genArr = Array(target + 1).fill(false)
    genArr[0] = true
    for (let i = 0; i <= target; i++) {
        if (genArr[i]) {
            for (let num of arr)
            if (i + num <= target) {
                genArr[i+num] = true
            }
        }
    }
    return genArr[target]
}

console.log(canSumTab(7, [5, 3, 4, 7]))
console.log(canSumTab(300, [7, 14]))
