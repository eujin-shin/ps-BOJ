const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const rule = new Map();
input.slice(1, -1).forEach((str) => {
  const [x, , ...y] = str.split(" ");
  rule.set(x, new Set(y));
});
const answer = input[input.length - 1]
  .split("")
  .reduce(
    ([acc, prev], cur) => [
      acc && (!rule.has(prev) || rule.get(prev).has(cur)),
      cur,
    ],
    [true]
  )[0];
console.log(answer ? "yes" : "no");
