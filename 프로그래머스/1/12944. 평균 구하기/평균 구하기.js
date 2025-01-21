function solution(arr) {
    return arr.reduce((sum, cur) => sum + cur, 0) / arr.length;
}