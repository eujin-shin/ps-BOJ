function solution(a, b) {
    if(a * b % 2) {
        return a ** 2 + b ** 2;
    } else if((a + b) % 2) {
        return 2 * (a + b);
    } else {
        return Math.abs(a - b);
    }
}