function solution(my_string) {
    return Array.from(my_string)
        .reduce((acc, cur) => [cur, ...acc], [])
        .join('');
}