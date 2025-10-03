const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let row = 0;
const n = Number(input[row++]);
function solution(x) {
  const robots = new Set(Array.from({ length: x }, (_, idx) => idx + 1));
  for (let r = 0; r < input[row].length; r++) {
    const attend = new Set();
    for (let i = 0; i < x; i++) {
      if (!robots.has(i + 1)) continue;
      attend.add(input[row + i][r]);
    }
    if (attend.size !== 2) continue;
    const lose = !attend.has("R") ? "P" : !attend.has("S") ? "R" : "S";
    for (let i = 0; i < x; i++) {
      if (input[row + i][r] === lose) robots.delete(i + 1);
    }
    if (robots.size < 2) break;
  }
  row += x;
  return robots.size !== 1 ? 0 : [...robots.values()][0];
}

for (let t = 0; t < n; t++) {
  const x = Number(input[row++]);
  console.log(solution(x));
}
