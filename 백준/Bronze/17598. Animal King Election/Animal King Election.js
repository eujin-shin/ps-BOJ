const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let a = 0;
let b = 0;
input.forEach((name) => (name === "Lion" ? (a += 1) : (b += 1)));
console.log(a > b ? "Lion" : "Tiger");
