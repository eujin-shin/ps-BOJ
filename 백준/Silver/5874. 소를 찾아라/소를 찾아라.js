const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("");
const x = [];
const y = [];
input.forEach((l, idx) => {
  if (input[idx - 1] === "(" && l === "(") x.push(idx - 1);
  else if (input[idx - 1] === ")" && l === ")") y.push(idx - 1);
});
console.log(
  x.reduce(
    ([sum, prev], cur) => {
      let idx = prev;
      while (y[idx] <= cur && idx < y.length) idx++;
      return [sum + y.length - idx, idx];
    },
    [0, 0]
  )[0]
);
