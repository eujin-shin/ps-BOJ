function solution(cards1, cards2, goal) {
    return goal.reduce(([result, x, y], word) => {
        if(!result) {
            return [result, x, y];
        } else if(cards1[x] === word) {
            return [result, ++x, y];
        } else if(cards2[y] === word) {
            return [result, x, ++y];
        }
        return [false, -1, -1];
    }, [true, 0, 0])[0] ? "Yes" : "No";
}