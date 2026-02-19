const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
console.log(
  input.slice(1).reduce((max, str) => {
    const [x, y] = str.split(" ").map(Number);
    const v = x * y;
    return max > v ? max : v;
  }, 0)
);
