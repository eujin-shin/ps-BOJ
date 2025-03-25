function solution(players, m, k) {
    const removeTime = {};
    return players.reduce(([sum, server], player, time) => {
        const cur = server - (removeTime[time] || 0);
        const need = Math.floor(player / m);
        if(need <= cur) {
            return [sum, cur];
        }
        const add = need - cur;
        removeTime[time + k] = add;
        return [sum + add, need];
    }, [0, 0])[0];
}