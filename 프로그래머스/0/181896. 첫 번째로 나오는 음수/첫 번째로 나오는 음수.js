function solution(num_list) {
    const negative_list = num_list.filter((num) => num < 0);
    return negative_list.length < 1 ? -1 : num_list.indexOf(negative_list[0]);
}