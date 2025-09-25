const fs = require("fs");
const input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .slice(0, -1);
const count = new Map();
const nameList = [...new Set(input)];
input.forEach((name) => count.set(name, (count.get(name) || 0) + 1));
nameList.forEach((name) => console.log(`${name}: ${count.get(name)}`));
console.log("Grand Total:", input.length);
