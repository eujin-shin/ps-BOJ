const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, starts, ends] = input.map((str) => str.split(" ").map(Number));
const startsMap = new Map(starts.map((v, idx) => [v, idx]));
let max = 0;
let answer = [];
ends.forEach((v, idx) => {
  const increase = (startsMap.get(v) || idx) - idx;
  if (max < increase) answer = [v];
  else if (max === increase) answer.push(v);
  max = max < increase ? increase : max;
});
console.log(answer.join(" "));
