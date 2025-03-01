const fs = require("fs");
const [x, y] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);

function solution(x, y) {
  const a = 100 - x;
  const b = 100 - y;
  const c = 100 - (a + b);
  const d = a * b;
  const r = d % 100;
  const q = (d - r) / 100;
  console.log(a, b, c, d, q, r);
  console.log(c + q, r);
  return;
}

solution(x, y);
