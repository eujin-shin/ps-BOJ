const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const weights = input.split(" ").map(Number);

function solution(weights) {
  const sum = weights.reduce((sum, v) => sum + v, 0);
  const check = Array.from({ length: sum }, () => 0);

  const backtrack = (r, values) => {
    if (weights.length < r) {
      return;
    }
    const next = [];
    for (let i = 0; i < values.length; i++) {
      const v = values[i];
      if (0 < v && v <= sum) {
        check[v - 1]++;
      }
      next.push(v + weights[r], v - weights[r], v);
    }
    backtrack(r + 1, next);
  };
  backtrack(0, [0]);
  return check.filter((v) => v === 0).length;
}

console.log(solution(weights));
