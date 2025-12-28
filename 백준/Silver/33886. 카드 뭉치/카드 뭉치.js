const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const count = input.split(" ").reduce((map, v, index) => {
  const x = Number(v);
  const newMap = new Map();
  for (const [count, left] of map) {
    const withSplit = map.get(count - 1) ? x : 0;
    const noSplit = Math.max(0, left - 1);
    newMap.set(count, Math.max(withSplit, noSplit));
  }
  return newMap.set(index + 1, x);
}, new Map());
const validKeys = [...count.keys()].filter((v) => count.get(v));
console.log(Math.min(...validKeys));
