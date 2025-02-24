function solution(k, score) {
    const list = [];
    
    const binarySearch = (v) => {
        let l = 0;
        let r = Math.min(k - 1, list.length - 1);
        let ans = r;
        while(l <= r) {
            const mid = Math.floor((l + r) / 2);
            if(list[mid] < v) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    
    return score.map((v) => {
        if(list.length === 0 || list[Math.min(k - 1, list.length - 1)] > v) {
            list[list.length] = v;
        } else {
            const idx = binarySearch(v);
            list.splice(idx, 0, v);
        }
        return list[Math.min(k - 1, list.length - 1)];
    });
}