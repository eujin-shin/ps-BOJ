const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let index = 0;
while (1) {
  const n = Number(input[index++]);
  if (n === 0) break;
  const odd = input[index++]
    .split(" ")
    .map(Number)
    .reduce((prev, v) => prev + (v % 2 === 1 ? 1 : 0), 0);
  const even = input[index++]
    .split(" ")
    .map(Number)
    .reduce((prev, v) => prev + (v % 2 === 0 ? 1 : 0), 0);
  console.log(Math.abs(odd - even));
}
