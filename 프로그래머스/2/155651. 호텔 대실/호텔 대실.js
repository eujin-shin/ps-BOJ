function solution(book_time) {
    const count = Array.from({length: 24 * 60}, () => 0);
    const getMinute = (str) => {
        const [hour, minute] = str.split(":").map(Number);
        return hour * 60 + minute;
    }
    
    let max = 0;
    book_time.forEach(([x, y]) => {
        const start = getMinute(x);
        const end = getMinute(y) + 10;
        
        for(let i = start; i < end; i++) {
            max = ++count[i] > max ? count[i] : max;
        }
    })
    return max;
}