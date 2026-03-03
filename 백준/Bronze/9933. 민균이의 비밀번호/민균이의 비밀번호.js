const fs = require("fs");
const [, ...arr] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const words = new Set(arr);
const password = arr.find((v) => words.has([...v].reverse().join("")));
console.log(password.length, password[(password.length - 1) / 2]);
