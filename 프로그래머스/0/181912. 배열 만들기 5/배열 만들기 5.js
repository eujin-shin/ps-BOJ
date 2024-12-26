function solution(intStrs, k, s, l) {
    return intStrs.map((intStr) => parseInt(intStr.slice(s, s + l)))
        .filter((int) => int > k);
}