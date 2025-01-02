function solution(n) {
    const isPrime = Array.from({length: n}, () => true);
    for(let i = 2; i <= n; i++) {
        for(let j = i + i; isPrime[i - 1] && j <= n; j += i) {
            isPrime[j - 1] = false;
        }
    }
    return isPrime.filter((v, i) => i !== 0 && v).length;
}