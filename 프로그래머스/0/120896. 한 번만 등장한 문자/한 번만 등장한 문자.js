function solution(s) {
    return Array.from(s).filter((v, i) => s.indexOf(v) === s.lastIndexOf(v)).sort().join('');
}