const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], minus, plus] = input.map((str) => str.split(" ").map(Number));
const arr = Array.from({ length: n }, () => 1);
plus.forEach((v) => arr[v - 1]++);
minus.forEach((v) => arr[v - 1]--);
let count = 0;
arr.forEach((v, index) => {
  if (0 < v) arr[index]--;
  else if (0 < (arr[index - 1] || 0)) arr[index - 1]--;
  else if (1 < (arr[index + 1] || 0)) arr[index + 1]--;
  else count++;
});
console.log(count);
