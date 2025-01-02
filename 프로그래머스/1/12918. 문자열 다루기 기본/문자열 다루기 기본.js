function solution(s) {
    return s.match(/[A-Z]/ig) === null && (s.length === 4 || s.length === 6);
}