const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], arr] = input.map((str) => str.split(" ").map(Number));
const [odd, even] = arr.reduce(
  ([odd, even], v, idx) => (idx % 2 === 0 ? [odd + v, even] : [odd, even + v]),
  [0, 0]
);
console.log(n === 3 && even < odd ? -1 : Math.abs(odd - even));
