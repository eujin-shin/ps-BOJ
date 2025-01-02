function solution(num_list) {
    const isEven = num => num % 2 === 0;
    return num_list.reduce(([even, odd], cur) => isEven(cur) ? [even + 1, odd] : [even, odd + 1], [0, 0]);
}