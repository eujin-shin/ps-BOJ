const fs = require("fs");
const [a, b] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
console.log(
  Number(a) / 2 <= [...b].filter((v) => v === "O").length ? "Yes" : "No"
);
