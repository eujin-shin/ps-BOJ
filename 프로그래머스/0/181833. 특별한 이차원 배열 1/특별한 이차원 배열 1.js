function solution(n) {
    const answer = Array.from({length: n}, () => Array(n).fill(0));
    return answer.map((row, i) => row.map((v, j) => i === j ? 1 : 0));
}