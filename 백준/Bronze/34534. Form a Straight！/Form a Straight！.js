const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const cards = input.split(" ").map(Number);
const match = Array.from({ length: 5 }, (_, idx) => idx);
let max = 0;
for (let i = 1; i < 9; i++) {
  const count = match.filter((v) =>
    cards.some((card) => card === v + i)
  ).length;
  max = max < count ? count : max;
}
console.log(5 - max);
