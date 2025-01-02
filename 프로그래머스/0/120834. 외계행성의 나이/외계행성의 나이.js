function solution(age) {
    const zero_code = '0'.charCodeAt();
    const a_code = 'a'.charCodeAt();
    return Array.from(String(age))
                .map((num) => String.fromCharCode(a_code + num.charCodeAt() - zero_code))
                .join('');
}