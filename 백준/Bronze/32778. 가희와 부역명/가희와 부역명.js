const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const names = input.split(" (");
console.log(names[0]);
console.log(names[1]?.slice(0, -1) || "-");
