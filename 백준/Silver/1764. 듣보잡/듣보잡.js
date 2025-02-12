const fs = require("fs");
const [firstLine, ...names] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, m] = firstLine.split(" ").map(Number);
const a = names.splice(0, n);
const b = names.splice(0, m);

function solution(a, b) {
  const set = new Set(a);
  return b.filter((name) => set.has(name)).sort();
}

const answer = solution(a, b);

console.log(answer.length);
answer.forEach((name) => console.log(name));
