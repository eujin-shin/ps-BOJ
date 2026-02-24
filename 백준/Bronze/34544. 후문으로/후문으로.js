const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const end = input.slice(1).reduce((prev, str) => {
  const [a, b] = str.split(" ").map(Number);
  const diff = b - a + (a < b ? -1 : 1) * (a * b <= 0 ? 1 : 0);
  return (
    prev + diff + (diff > 0 ? 1 : -1) * (prev * (prev + diff) <= 0 ? 1 : 0)
  );
}, 1);
console.log(end);
