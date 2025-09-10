const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [sum, min] = input
  .split(" ")
  .reduce(
    ([sum, min], v) => [sum + Number(v), Number(v) < min ? Number(v) : min],
    [0, Infinity]
  );
console.log(sum - min);
