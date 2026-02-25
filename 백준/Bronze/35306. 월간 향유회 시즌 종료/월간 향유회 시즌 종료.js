const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...arr] = input.map((str) => str.split(" ").map(Number));
const record = new Map();
arr.forEach((v, i) =>
  v.forEach((n, j) => {
    if (record.has(j)) {
      const { max } = record.get(j);
      if (n > max) {
        record.set(j, { valid: true, p: i, max: n });
      } else if (n === max) {
        record.set(j, { valid: false, max: n });
      }
    } else {
      record.set(j, { valid: true, p: i, max: n });
    }
  })
);
const answer = new Set(
  [...record.values()].filter((v) => v.valid).map((v) => v.p)
).size;
console.log(answer);
