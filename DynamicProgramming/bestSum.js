const bestSumRecursive = (target, numbers) => {
    if (target === 0) return [];
    if (target < 0) return null;

    let shortestCombination = null;

    for (let num of numbers) {
        const remainder = target - num
        const remainderCombination = bestSumRecursive(remainder, numbers)
        if (remainderCombination !== null) {
            const combination = [...remainderCombination, num]
            if (shortestCombination === null || combination.length < shortestCombination.length) {
                shortestCombination = combination
            }
        }
    }
    return shortestCombination
}

const bestSumMem = (target, numbers, cache = {}) => {
    if (target in cache) return cache[target]
    
    if (target === 0) return [];
    if (target < 0) return null;

    let shortestCombination = null;

    for (let num of numbers) {
        const remainder = target - num
        const remainderCombination = bestSumMem(remainder, numbers, cache)
        if (remainderCombination !== null) {
            remainderCombination.push(num)
            if (shortestCombination === null || remainderCombination.length < shortestCombination.length) {
                shortestCombination = remainderCombination
            }
        }
    }
    cache[target] = shortestCombination
    return shortestCombination
}

const bestSumTab = (target, numbers) => {
    let genArr = Array(target + 1).fill(null)
    genArr[0] = []
    for (let i = 0; i <= target; i++) {
        if (genArr[i] !== null) {
            for (let num of numbers) {
                if (i + num <= target) {
                    if (genArr[i+num] === null) {
                        genArr[i+num] = [...genArr[i]]
                        genArr[i+num].push(num)
                    } else {
                        const curLength = genArr[i+num].length
                        const newLength = genArr[i].length + 1
                        if (curLength > newLength) {
                            genArr[i+num] = [...genArr[i]]
                            genArr[i+num].push(num)
                        }
                    }
                }
            }
        }
    }
    return genArr[target]
}
console.log(bestSumMem(7, [5, 3, 4, 7]))
console.log(bestSumMem(8, [2, 3, 5]))
console.log(bestSumMem(8, [1, 4, 5]))
console.log(bestSumMem(100, [1, 2, 5, 25]))

console.log(bestSumTab(7, [5, 3, 4, 7]))
console.log(bestSumTab(8, [2, 3, 5]))
console.log(bestSumTab(8, [1, 4, 5]))
console.log(bestSumTab(100, [1, 2, 5, 25]))