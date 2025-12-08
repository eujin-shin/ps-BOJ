const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
input.forEach((v) => {
  const n = Number(v);
  let count = 0;
  for (let x = n; x > 1; ) {
    if (x % 2 !== 0) {
      count++;
      x -= (x - 1) / 2;
    } else {
      x /= 2;
    }
  }
  console.log(count);
});
