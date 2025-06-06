const fs = require("fs");
const [, answer] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
console.log(answer);
