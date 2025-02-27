function solution(n, m, section) {
    return section.reduce(([count, max], x) => x <= max ? [count, max] : [count + 1, Math.min(n, x + m - 1)], [0, 0])[0];
}