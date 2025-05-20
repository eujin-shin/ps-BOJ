const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
console.log([...input].every((v, _, arr) => v === arr[0]) ? "Yes" : "No");
