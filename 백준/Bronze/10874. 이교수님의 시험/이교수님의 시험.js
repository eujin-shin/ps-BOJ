const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.slice(1).forEach((str, i) => {
  if (str.split(" ").every((v, j) => Number(v) === (j % 5) + 1))
    console.log(i + 1);
});
