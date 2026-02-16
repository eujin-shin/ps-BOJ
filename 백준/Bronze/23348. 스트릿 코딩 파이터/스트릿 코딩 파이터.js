const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [arr, [n], ...records] = input.map((str) => str.split(" ").map(Number));
let i = 0;
let max = 0;
for (let x = 0; x < n; x++) {
  const sum = records
    .slice(i, i + 3)
    .reduce(
      (sum, scores) =>
        sum + scores.reduce((prev, score, idx) => prev + score * arr[idx], 0),
      0
    );
  i += 3;
  max = max < sum ? sum : max;
}
console.log(max);
