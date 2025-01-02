function solution(s){
    const [p, y] = Array
        .from(s.toLowerCase())
        .reduce(([p, y], cur) => [cur === 'p' ? p + 1 : p, cur === 'y' ? y + 1 : y], [0, 0]);
    return p === y;
}