const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.slice(1).reduce((max, cur) => {
  if (cur === "/") {
    console.log(max);
    return max;
  } else {
    const limit = Number(cur);
    console.log(cur);
    return max > limit
      ? max
      : limit % 10 === 0
      ? limit + 10
      : 10 * Math.ceil(limit / 10);
  }
}, 0);
