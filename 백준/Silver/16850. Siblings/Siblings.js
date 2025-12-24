const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const arr = input.map((str) => str.split(" ").map(Number)).flat();
let index = 0;
const k = arr[index++];
for (let i = 0; i < k; i++) {
  const n = arr[index++];
  const count = Array.from({ length: n }, () => 0);
  for (let x = 0; x < n; x++) {
    const mother = arr[index++];
    if (mother !== 0) count[mother]++;
  }
  console.log((i > 0 ? "\n" : "") + `Data Set ${i + 1}:`);
  console.log(count.reduce((sum, value) => sum + (value * (value - 1)) / 2, 0));
}
