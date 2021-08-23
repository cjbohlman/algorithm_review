function howSumRecursive(target, numbers) {
    if (target === 0) return []
    if (target < 0) return null;

    for (let num of numbers) {
        const remainder = target - num
        const remainderResult = howSumRecursive(remainder, numbers)
        if (remainderResult !== null) {
            return [...remainderResult, num]
        }
    }

    return null
}

function howSumMemoization(target, numbers, cache = {}) {
    if (target in cache) return cache[target]
    if (target === 0) return []
    if (target < 0) return null;

    if (cache[target] !== undefined) {
        return cache[target]
    }

    for (let num of numbers) {
        const remainder = target - num
        const remainderResult = howSumMemoization(remainder, numbers, cache)
        if (remainderResult !== null) {
            remainderResult.push(num)
            cache[target] = remainderResult
            return remainderResult
        }
    }
    cache[target] = null
    return null
}

function howSumTab(target, numbers) {
    let genArr = Array(target + 1).fill(null)
    genArr[0] = []
    for (let i = 0; i <= target; i++) {
        if (genArr[i] !== null) {
            for (let num of numbers) {
                if (i + num <= target) {
                    if (genArr[i+num] === null) {
                        genArr[i+num] = [...genArr[i]]
                        genArr[i+num].push(num)
                    }
                }
            }
        }
    }
    return genArr[target]
}


console.log(howSumTab(7, [5, 3, 4, 7]))
console.log(howSumTab(8, [2, 5, 3, 4, 7]))
console.log(howSumTab(300, [7, 14]))