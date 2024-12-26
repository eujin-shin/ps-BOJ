function solution(my_string) {
    const answer = Array.from({length: 52}, () => 0);
    const upper_string = my_string.toUpperCase();
    
    const a_upper = 'A'.charCodeAt();
    const a_lower = 'a'.charCodeAt();
    const getIndex = (charCode, isUpperCase) => isUpperCase ? charCode - a_upper : charCode - a_lower + 26;
    
    Array.from(my_string).forEach((letter, index) => {
        answer[getIndex(letter.charCodeAt(), upper_string[index] === letter)]++;
    })
    
    return answer;
}