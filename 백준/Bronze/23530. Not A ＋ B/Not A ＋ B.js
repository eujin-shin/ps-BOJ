const fs = require("fs");
const [, ...arr] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
console.log(arr.map(() => 1).join("\n"));
