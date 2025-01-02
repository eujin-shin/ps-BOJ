function solution(dot) {
    const find = ([x, y]) => {
        if(x > 0 && y > 0) {
            return 1;
        } else if(x > 0) {
            return 4;
        } else if(y > 0) {
            return 2;
        } else {
            return 3;
        }
    }
    return find(dot);
}