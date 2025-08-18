const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, , ...days] = input;
const arr = [];
days.forEach((element) => {
  const day = Number(element);
  if (!arr.some((v) => (day - 1) % v === 0)) {
    arr.push(day - 1);
  }
});
console.log(arr.length);
