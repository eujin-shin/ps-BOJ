const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, type] = input;
const match = "qwertyuiopasdfghjklzxcvbnm";
const a = "a".charCodeAt(0);
console.log(
  type
    .split("")
    .map((v) => (v === " " ? v : match[v.charCodeAt(0) - a]))
    .join("")
);
