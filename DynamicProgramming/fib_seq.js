// recursive approach
const fib_recur = function(n) {
    // first two numbers of the sequence are 1 and 1 
    if (n <= 2) {
        return 1;
    }
    return fib_recur(n-1) + fib_recur(n - 2);
}

// top down
fib_results = []
const fib_top_down = (n) => {
    if (n <=2) return 1;

    if (fib_results[n] == undefined) {
        fib_results[n] = fib_top_down(n-1) + fib_top_down(n-2)
    }
    return fib_results[n];
}

// bottom up
const fib_bottom_up = (n) => {
    fib_results[0] = 1;
    fib_results[1] = 1;
    fib_results[2] = 1;
    for (let i = 3; i <= n; i++) {
        fib_results[i] = fib_results[i-1] + fib_results[i-2];
    }
    return fib_results[n]
}

const fib_constant_space = (n) => {
    let prev1 = 0;
    let prev2 = 1;
    let cur = 1;
    for (let i = 3; i <= n; i++) {
        prev1 = prev2
        prev2 = cur
        cur = prev1 + prev2
    }
    return cur;

}

console.log(fib_constant_space(6))
console.log(fib_constant_space(7))
console.log(fib_constant_space(8))