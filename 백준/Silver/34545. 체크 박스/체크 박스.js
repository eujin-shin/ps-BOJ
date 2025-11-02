const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], cur, target] = input.map((str) => str.split(" ").map(Number));
const diff = cur.filter((v, idx) => target[idx] !== v).length;
const curChecked = cur.filter((v) => v === 1).length;
const curUncheked = n - curChecked;
const targetChecked = target.filter((v) => v === 1).length;
const targetUncheked = n - targetChecked;
const toEmpty = curChecked < 2 ? curChecked : 2;
const fromEmpty =
  targetChecked < 1 + targetUncheked ? targetChecked : 1 + targetUncheked;
const toFull = curUncheked < 1 ? curUncheked : 1;
const fromFull =
  targetUncheked < 1 + targetChecked ? targetUncheked : 1 + targetChecked;
console.log(Math.min(diff, toEmpty + fromEmpty, toFull + fromFull));
