const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [a, b] = input.split(" ").map(Number);
console.log(Number("1".repeat(a)) + Number("1".repeat(b)));
