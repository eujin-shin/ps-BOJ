const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[a], [w, v]] = input.map((str) => str.split(" ").map(Number));
console.log(a <= w / v ? 1 : 0);
