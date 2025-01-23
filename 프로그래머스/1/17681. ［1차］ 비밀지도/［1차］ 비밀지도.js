function solution(n, arr1, arr2) {
    const answer = [];
    
    for(let i = 0; i < n; i++) {
        const row = [];
        let a = arr1[i];
        let b = arr2[i];
        for(let x = 2 ** (n - 1); x >= 1; x /= 2) {
            row.push(a >= x || b >= x ? "#" : " ");
            a = a >= x ? a - x : a;
            b = b >= x ? b - x : b;
            
        }   
        answer.push(row.join(''));
    }
   
    return answer;
}