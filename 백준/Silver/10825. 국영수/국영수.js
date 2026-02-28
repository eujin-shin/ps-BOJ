const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const entries = input.slice(1).map((str) => {
  const [name, ...scores] = str.split(" ");
  return [name, ...scores.map(Number)];
});
const answer = entries.sort((a, b) => {
  if (a[1] !== b[1]) return b[1] - a[1];
  if (a[2] !== b[2]) return a[2] - b[2];
  if (a[3] !== b[3]) return b[3] - a[3];
  return a[0] > b[0] ? 1 : -1;
});
console.log(answer.map((v) => v[0]).join("\n"));
