const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, count, ...problems] = input.map((str) => str.split(" ").map(Number));
const level = Array.from({ length: 5 }, () => new Array());
problems.forEach(([l, t]) => level[l - 1].push(t));
const answer = level
  .map((problem, idx) =>
    problem
      .sort((a, b) => a - b)
      .slice(0, count[idx])
      .reduce(
        (sum, cur, idx, arr) =>
          idx === 0 ? cur : sum + cur + cur - arr[idx - 1],
        0
      )
  )
  .reduce((sum, cur, idx) => (idx === 0 ? cur : sum + cur + 60), 0);
console.log(answer);
