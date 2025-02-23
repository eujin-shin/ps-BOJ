const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(arr) {
  return arr.map((word) => [...word].reverse().join("")).join(" ");
}

input.forEach((string) => console.log(solution(string.split(" "))));
