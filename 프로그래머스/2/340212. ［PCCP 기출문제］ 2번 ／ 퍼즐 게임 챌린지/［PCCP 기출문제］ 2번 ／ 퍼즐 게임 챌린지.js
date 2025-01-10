function solution(diffs, times, limit) {
    const base = times.reduce((acc, cur) => acc + cur, 0);
    
    const isInLimit = (level) => {
        const total = diffs.reduce((acc, cur, index) => acc + (times[index] + (index > 0 ? times[index - 1] : 0)) * Math.max(0, cur - level), base);
        return total <= limit;
    };
    
    const max = [...diffs].sort((a, b) => b - a)[0];
    let left = 1, right = max, ans = max;
    while(left <= right) {
        const level = Math.floor((left + right) / 2);
        
        if(isInLimit(level)) {
            right = level - 1;
            ans = level;
        } else {
            left = level + 1;
        }
    }
    
    return ans;
}