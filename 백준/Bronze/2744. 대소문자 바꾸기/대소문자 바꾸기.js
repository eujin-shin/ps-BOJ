const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("");
console.log(
  input
    .map((c) => (c === c.toLowerCase() ? c.toUpperCase() : c.toLowerCase()))
    .join("")
);
