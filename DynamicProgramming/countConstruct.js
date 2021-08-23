function countConstructRecursive(target, wordBank) {
    if (target == '') return 1;

    let count = 0;
    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            count += countConstructRecursive(target.slice(word.length), wordBank)
        }
    }

    return count;
}

function countConstructMem(target, wordBank, cache = {}) {
    if (target in cache) return cache[target]
    if (target == '') return 1;

    let count = 0;
    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            count += countConstructMem(target.slice(word.length), wordBank, cache)
        }
    }
    cache[target] = count
    return count;
}

function countConstructTab(target, wordBank) {
    let constructArr = Array(target.length + 1).fill(0)
    constructArr[0] = 1
    for (let i = 0; i < target.length; i++) {
        if (constructArr[i] > 0) {
            for (let word of wordBank) {
                if (target.slice(i, i + word.length) === word) {
                    constructArr[i+word.length] += constructArr[i]
                }
            }
        }
    }
    return constructArr[target.length]
}

console.log(countConstructTab('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd', 'ef']))
console.log(countConstructTab('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', ['e','ee','eee','eeee','eeeee']))

