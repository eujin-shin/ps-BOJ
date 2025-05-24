const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(input) {
  if (input.length < 26) {
    return input;
  }
  const front = input.slice(0, 11);
  const mid = input.slice(11, -11);
  const back = input.slice(-11);
  if ([...mid].slice(0, -1).includes(".")) {
    return input.slice(0, 9) + "......" + input.slice(-10);
  }
  return front + "..." + back;
}

console.log(solution(input));
