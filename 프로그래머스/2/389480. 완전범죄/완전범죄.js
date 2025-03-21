function solution(info, n, m) {
    const sorted = info.map(([a, b]) => [a, b, a / b]).sort((x, y) => y[2] - x[2] || y[1] - x[1]);
    
    let b = 0;
    for(let i = 0; i < info.length; i++) {
        if(b + sorted[i][1] < m) {
            b += sorted[i][1];
            sorted[i][0] = 0;
        }
    }
    
    let a = 0;
    for(let i = 0; i < info.length; i++) {
        a += sorted[i][0];
    }
    return n <= a ? -1 : a;
}