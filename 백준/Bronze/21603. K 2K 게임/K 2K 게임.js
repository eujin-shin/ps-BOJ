const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [n, k] = input.split(" ").map(Number);
const a = k % 10;
const b = (k * 2) % 10;
const answer = Array.from({ length: n }, (_, i) => {
  const x = (i + 1) % 10;
  return x !== a && x !== b ? i + 1 : null;
}).filter((v) => v !== null);
console.log(answer.length);
console.log(answer.join(" "));
