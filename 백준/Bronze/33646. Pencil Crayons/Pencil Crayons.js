const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...crayons] = input.map((str) => str.split(" "));
console.log(
  crayons.reduce((sum, crayon) => sum + crayon.length - new Set(crayon).size, 0)
);
