const { table } = require("console")

function allConstructRecursive(target, wordbank) {
    if (target === '') return [[]]
    const arr = []
    for (let word of wordbank) {
        if (target.indexOf(word) === 0) {
            const subArr = allConstructRecursive(target.slice(word.length), wordbank)
            const targetWays = subArr.map(way => word, ...way)
            arr.push(...targetWays)
        }
    }
    return arr
}

function allConstructMem(target, wordbank, cache = {}) {
    if (target in cache) return cache[target]
    if (target === '') return [[]]
    const arr = []
    for (let word of wordbank) {
        if (target.indexOf(word) === 0) {
            const subArr = allConstructMem(target.slice(word.length), wordbank, cache)
            const targetWays = subArr.map(way => [word, ...way])
            arr.push(...targetWays)
        }
    }
    cache[target] = arr
    return arr
}


function allConstructTab(target, wordbank) {
    let constructArr = Array(target.length + 1).fill().map(() => [])
    constructArr[0] = [[]]
    for (let i = 0; i <= target.length; i++) {
        for (let word of wordbank) {
            if (target.slice(i, i + word.length) === word) {
                const newCombinations = constructArr[i].map(subarray => {
                    return [...subarray, word]
                })
                constructArr[i + word.length].push(...newCombinations)
            }
        }
    }
    return constructArr[target.length]
}

console.log(allConstructTab('purple', ['purp', 'p', 'ur', 'le', 'purpl']))
console.log(allConstructTab('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd', 'ef', 'c']))