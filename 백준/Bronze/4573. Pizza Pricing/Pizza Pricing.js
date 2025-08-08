const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const prices = input.map((str) => str.split(" ").map(Number));
let row = 0;
let x = 1;
while (1) {
  const [n] = prices[row++];
  if (n === 0) break;
  let min = Infinity;
  let answer = 0;
  for (let i = 0; i < n; i++) {
    const [r, p] = prices[row++];
    if (p / (r * r) < min) {
      min = p / (r * r);
      answer = r;
    }
  }
  console.log(`Menu ${x++}: ${answer}`);
}
