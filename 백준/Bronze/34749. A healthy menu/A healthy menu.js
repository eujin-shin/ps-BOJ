const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...survey] = input.map((str) => str.split(" ").map(Number));
const students = survey[0].reduce(
  (prev, _, index) => prev + Math.max(...survey.map((arr) => arr[index])),
  0
);
console.log(students);
