const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const queries = input.map((str) => str.split(" ").map(Number));

function solution(queries) {
  const arr = [];
  queries.forEach(([q, x, t]) => {
    if (q === 1) {
      arr.sort((a, b) => (x === 1 ? a - b : b - a));
    } else {
      arr.splice(x, 0, t);
    }
  });
  return arr;
}

const result = solution(queries);
console.log(result.length);
console.log(result.join(" "));
