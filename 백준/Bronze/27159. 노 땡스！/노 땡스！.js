const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, cards] = input.map((str) => str.split(" ").map(Number));
console.log(
  cards.reduce(
    ([prev, sum], value) => [value, sum + (prev + 1 === value ? 0 : value)],
    [0, 0]
  )[1]
);
