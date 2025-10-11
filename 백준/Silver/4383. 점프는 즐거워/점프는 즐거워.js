const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
for (let i = 0; i < input.length; i++) {
  const [n, ...arr] = input[i]
    .split(" ")
    .filter((v) => v !== "")
    .map(Number);
  if (n === undefined) continue;
  const diff = new Set();
  for (let x = 1; x < n; x++) diff.add(Math.abs(arr[x] - arr[x - 1]));
  const isJolly =
    [...diff].sort((a, b) => a - b).every((v, i) => v === i + 1) &&
    diff.size === n - 1;
  console.log(isJolly ? "Jolly" : "Not jolly");
}
