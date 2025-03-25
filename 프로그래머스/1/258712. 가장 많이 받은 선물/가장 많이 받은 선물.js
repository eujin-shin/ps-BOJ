function solution(friends, gifts) {
    const indexes = new Map(friends.map((name, idx) => [name, idx]));
    const records = Array.from({length: friends.length}, () => Array.from({length: friends.length}, () => 0));
    const counts = Array.from({length: friends.length}, () => 0);
    
    gifts.forEach((str) => {
        const [a, b] = str.split(' ');
        const give = indexes.get(a);
        const take = indexes.get(b);
        records[give][take]++;
        counts[give]++;
        counts[take]--;
    });
    
    return friends.reduce((max, _, x) => {
        const nextGift = friends.filter((_, y) => records[y][x] < records[x][y] || (records[y][x] === records[x][y] && counts[y] < counts[x])).length;
        return max < nextGift ? nextGift : max;
    }, 0);
}