const fs = require("fs");
const [input, ...words] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const n = Number(input);
let same = true;
for (let i = 0; i < n && same; i++) {
  for (let j = 0; j < n && same; j++) same = words[i][j] === words[j][i];
}
console.log(same ? "YES" : "NO");
