const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(n, list) {
  let x = 0;
  for (let i = 0; i < n; i++) {
    x += list[i] === x + 1 ? 2 : 1;
  }
  return x;
}

for (let i = 1; i < input.length; i += 2) {
  console.log(solution(Number(input[i]), input[i + 1].split(" ").map(Number)));
}
