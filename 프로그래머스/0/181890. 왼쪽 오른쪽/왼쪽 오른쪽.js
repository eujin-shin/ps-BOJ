function solution(str_list) {
    const left = str_list.indexOf('l');
    const right = str_list.indexOf('r');
    return left === right ? [] : ((right < 0 || (left >= 0 && left < right)) ? str_list.slice(0, left) : str_list.slice(right + 1));
}