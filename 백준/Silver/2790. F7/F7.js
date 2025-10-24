const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, ...scores] = input.map(Number);
console.log(
  scores
    .sort((a, b) => b - a)
    .reduce(
      ([sum, min], cur, idx) => [
        sum + (cur + n >= min ? 1 : 0),
        min < cur + idx + 1 ? cur + idx + 1 : min,
      ],
      [0, 0]
    )[0]
);
