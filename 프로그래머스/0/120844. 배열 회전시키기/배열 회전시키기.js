function solution(numbers, direction) {
    if(direction === 'right') {
        const cut = numbers.splice(-1, 1);
        return cut.concat(numbers);
    }
    const cut = numbers.splice(0, 1);
    return numbers.concat(cut);
}