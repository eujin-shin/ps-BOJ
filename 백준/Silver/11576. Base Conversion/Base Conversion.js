const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[a, b], , digits] = input.map((str) => str.split(" ").map(Number));

function solution(a, b, digits) {
  const base10 = digits
    .reverse()
    .reduce(([x, sum], v) => [x * a, sum + x * v], [1, 0])[1];
  const answer = [];
  for (let i = 0, x = 1; i < base10; x *= b) {
    const k = (base10 - i) % (x * b);
    answer.push(k / x);
    i += k;
  }
  return answer.reverse().join(" ");
}

console.log(solution(a, b, digits));
