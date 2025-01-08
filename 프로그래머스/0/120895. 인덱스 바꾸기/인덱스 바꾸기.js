function solution(my_string, num1, num2) {
    return Array.from(my_string).map((v, idx) => idx === num1 ? my_string[num2] : (idx === num2 ? my_string[num1] : v)).join('');
}