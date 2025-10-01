const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const record = new Map();
let sum = 0;
input.forEach((str) => {
  const [name, flag] = str.split(" ");
  if (flag === "+") {
    record.set(name, (record.get(name) || 0) + 1);
  } else {
    const current = record.get(name) || 0;
    if (current === 0) sum++;
    record.set(name, Math.max(0, current - 1));
  }
});
console.log(sum + [...record.values()].reduce((prev, v) => prev + v, 0));
