const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const numbers = input.split(" ").map(Number);

function solution(numbers) {
  let gap = 0;
  let min = Infinity;
  return numbers
    .map((v) => {
      min = v < min ? v : min;
      return (gap = gap < v - min ? v - min : gap);
    })
    .join(" ");
}

console.log(solution(numbers));
