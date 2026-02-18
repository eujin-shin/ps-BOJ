const fs = require("fs");
const [a, ...h] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, i] = a.split(" ").map(Number);
console.log(h.sort()[i - 1]);
