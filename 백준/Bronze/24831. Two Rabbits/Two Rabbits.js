const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.slice(1).forEach((str) => {
  const [x, y, a, b] = str.split(" ").map(Number);
  const dist = y - x;
  const move = a + b;
  console.log(dist % move === 0 ? dist / move : -1);
});
