function solution(array) {
    const count = Array(1001).fill(0);
    const [answer, max] = array.reduce(([num, max], cur) => {
        count[cur]++;
        if(count[cur] > max) {
            return [cur, count[cur]];
        } else if(count[cur] === max) {
            return [-1, max];
        }
        return [num, max];
    }, [-1, 0])
    return answer;
}