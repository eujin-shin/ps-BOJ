const fs = require("fs");
const [, arr] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [count] = arr
  .split(" ")
  .map(Number)
  .reduce(
    ([count, prev], v) => (prev < v ? [count + 1, v] : [count, prev]),
    [0, 0]
  );
console.log(count);
