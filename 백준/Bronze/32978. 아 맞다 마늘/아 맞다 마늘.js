const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [, a, b] = input.map((str) => str.split(" "));

function solution(a, b) {
  const [answer] = a.filter((v) => b.indexOf(v) < 0);
  return answer;
}

console.log(solution(a, b));
