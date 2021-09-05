function canConstructRecursive(target, wordBank) {
    // return true one target is empty
    if (target === '') return true;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length)
            if(canConstructRecursive(suffix, wordBank) === true) return true
        }
    }
    // only branch to child if prefix is present
    return false
}

function canConstructMem(target, wordBank, cache = {}) {
    if (target in cache ) return cache[target]
    // return true one target is empty
    if (target === '') return true;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length)
            if(canConstructMem(suffix, wordBank, cache) === true) {
                cache[target] = true
                return true
            }
        }
    }
    // only branch to child if prefix is present
    cache[target] = false;
    return false
}

function canConstructTab(target, wordBank) {
    let genArr = Array(target.length  + 1).fill(false)
    genArr[0] = true
    for (let i = 0; i <= target.length; i++) {
        if (genArr[i]) {
            for (let word of wordBank) {
                if (target.slice(i, i+word.length) === word) {
                    genArr[i+word.length] = true
                }
            }
        }
    }
    return genArr[target.length]
}


console.log(canConstructTab('skateboard', ['bo', 'rd', 'ate', 't', 'ska', 'sk', 'boar']))
console.log(canConstructTab('abcdef', ['ab','abc','cd','def','abcd']))
console.log(canConstructTab('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', ['e','ee','eee','eeee','eeeee']))
