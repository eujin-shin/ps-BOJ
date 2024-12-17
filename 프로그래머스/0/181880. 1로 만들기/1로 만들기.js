function solution(num_list) {
    const count = (num) => Math.floor(Math.log2(num));
    return num_list.reduce((acc, current) => acc + count(current), 0);
}