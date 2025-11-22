const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, students] = input.map((str) => str.split(" ").map(Number));
const [total] = students
  .sort((a, b) => a - b)
  .reduce(
    ([total, cur], v) => (cur === 0 ? [total + 1, v - 1] : [total, cur - 1]),
    [0, 0]
  );
console.log(total);
