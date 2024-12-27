const getGcd = (a, b) => a % b === 0 ? b : (a % b > b ? getGcd(a % b, b) : getGcd(b, a % b));

function solution(n) {
    const PIECES = 6;
    const gcd = n > PIECES ? getGcd(n, PIECES) : getGcd(PIECES, n);
    return n / gcd;
}