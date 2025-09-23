const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const numbers = input
  .split(" ")
  .map(Number)
  .sort((a, b) => a - b);
let answer = 0;
for (let a = 0; a < 5; a++) {
  for (let b = a + 1; b < 5; b++) {
    for (let c = b + 1; c < 5; c++) {
      if (numbers[a] + numbers[b] > numbers[c]) answer++;
    }
  }
}
console.log(answer);
