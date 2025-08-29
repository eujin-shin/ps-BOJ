const fs = require("fs");
const [a, b, c] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(" ")
  .map(Number);
for (let x = 1; x <= 10; x++) {
  if (a === 0) {
    const v = (c - a * x) / b;
    console.log(Number.isInteger(v) ? v : 0);
  } else if (b === 0) {
    console.log(
      a * x === c
        ? Array.from({ length: 10 }, (_, index) => index + 1).join(" ")
        : 0
    );
  } else {
    const v = (c - a * x) / b;
    console.log(Number.isInteger(v) && 0 < v && v <= 10 ? v : 0);
  }
}
