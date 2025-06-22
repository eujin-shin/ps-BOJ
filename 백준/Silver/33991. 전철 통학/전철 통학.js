const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [positions, [q], ...cases] = input.map((str) =>
  str.split(" ").map(Number)
);
function solution(x, y, ...times) {
  return times.reduce((min, t, idx) => {
    const distance =
      Math.abs(x - positions[idx * 2]) + Math.abs(y - positions[idx * 2 + 1]);
    const count = Math.ceil(distance / t);
    const result = t * count;
    return min < result ? min : result;
  }, Infinity);
}
for (let i = 0; i < q; i++) console.log(solution(...cases[i]));
