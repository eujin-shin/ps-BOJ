const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

function solution(n, m, a, k) {
  const leftPerson = a - k;
  const maxLeftTeam = Math.min(n - 1, leftPerson);
  const minLeftTeam = Math.ceil(leftPerson / m);
  return `${maxLeftTeam + 1} ${minLeftTeam + 1}`;
}

console.log(solution(...input.split(" ").map(Number)));
