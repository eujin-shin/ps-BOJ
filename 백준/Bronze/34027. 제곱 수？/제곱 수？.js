const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [, ...numbers] = input.split("\n");
numbers.forEach((v) =>
  console.log(Number.isInteger(Math.sqrt(Number(v))) ? 1 : 0)
);
