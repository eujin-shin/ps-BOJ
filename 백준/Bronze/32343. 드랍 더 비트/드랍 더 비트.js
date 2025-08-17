const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], [a, b]] = input.map((str) => str.split(" ").map(Number));
let answer = 0;
const zeroBound = a + b < n ? n - (a + b) : a + b - n;
for (let x = 1, i = 0; i < n; i++, x *= 2) {
  answer += zeroBound <= i ? x : 0;
}
console.log(answer);
