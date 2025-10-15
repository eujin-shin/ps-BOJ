const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...cases] = input;
cases.forEach((str) => {
  const n = str.length;
  console.log(str[n / 2] === str[n / 2 - 1] ? "Do-it" : "Do-it-Not");
});
