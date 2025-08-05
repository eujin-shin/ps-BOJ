const fs = require("fs");
const [, ...input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const count = new Map();
let answer = 0;
input.forEach((name, sum) => {
  const cur = count.get(name) || 0;
  answer += cur > sum - cur ? 1 : 0;
  count.set(name, cur + 1);
});
console.log(answer);
