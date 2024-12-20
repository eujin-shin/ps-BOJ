function solution(names) {
    const GROUP_SIZE = 5;
    return names.filter((_, index) => index % GROUP_SIZE === 0);
}