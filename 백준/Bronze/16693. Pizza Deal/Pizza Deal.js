const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[a, pa], [r, pr]] = input.map((str) => str.split(" ").map(Number));
const x = a / pa;
const y = (r * r * Math.PI) / pr;
console.log(x < y ? "Whole pizza" : "Slice of pizza");
