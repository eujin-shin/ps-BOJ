function solution(n) {
    return Array.from({ length: (n % 2 === 0 ? n : n + 1) / 2}, (_, i) => i * 2 + 1)
}