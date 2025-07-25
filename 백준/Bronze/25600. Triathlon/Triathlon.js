const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...scores] = input.map((str) => str.split(" ").map(Number));
console.log(
  scores.reduce((max, [a, d, g]) => {
    const score = a * (d + g) * (d + g === a ? 2 : 1);
    return score < max ? max : score;
  }, 0)
);
