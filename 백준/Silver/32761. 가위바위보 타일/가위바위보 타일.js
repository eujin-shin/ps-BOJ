const fs = require("fs");
const [n, tiles] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
function solution(n, tiles) {
  const pattern = ["PRS", "RSP", "SPR"];
  const indexes = [0, 0, 0];
  const count = [0, 0, 0];
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < 3; j++) {
      if (tiles[i] === pattern[j][indexes[j]]) {
        indexes[j] = (indexes[j] + 1) % 3;
        count[j]++;
      }
    }
  }
  const max = Math.max(1, ...count.map((v) => v - (v % 3)));
  return n - max;
}
console.log(solution(Number(n), tiles));
