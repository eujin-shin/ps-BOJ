const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const cases = input.slice(0, -1).map((str) =>
  str
    .split(" ")
    .map(Number)
    .sort((a, b) => a - b)
);
const solution = (a, b) => a * 2 - b;

for (let i = 0; i < cases.length; i++) console.log(solution(...cases[i]));
