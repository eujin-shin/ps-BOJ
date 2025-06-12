const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[s], [x, y, z]] = input.map((str) => str.split(" ").map(Number));
console.log(s <= 240 || s <= x + y + z ? "high speed rail" : "flight");
