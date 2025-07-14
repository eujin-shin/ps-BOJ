const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const cases = input.map((str) => str.split(" ").map(Number));
function solution(n, m, l, scores) {
  const min = Math.min(...scores.filter((v) => 0 <= v));
  return l < m - min ? m - min : l;
}
for (let i = 1; i < cases.length; i += 2) {
  const x = solution(...cases[i], cases[i + 1]);
  console.log(
    `The scoreboard has been frozen with ${x} minute${
      x === 1 ? "" : "s"
    } remaining.`
  );
}
