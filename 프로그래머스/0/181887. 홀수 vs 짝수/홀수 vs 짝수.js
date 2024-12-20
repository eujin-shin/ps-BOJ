function solution(num_list) {
    const isEven = num => num % 2 === 0;
    const oddSum = num_list.reduce((acc, cur, index) => !isEven(index) ? acc + cur : acc, 0);
    const evenSum = num_list.reduce((acc, cur, index) => isEven(index) ? acc + cur : acc, 0);
    return oddSum > evenSum ? oddSum : evenSum;
}