const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
for (let i = 0; i < input.length - 1; i++) {
  const [a, b, c] = input[i].split(" ").map(Number);
  const answer = (c - a) % b === 0 ? 1 + (c - a) / b : 0;
  console.log(answer < 1 ? "X" : answer);
}
