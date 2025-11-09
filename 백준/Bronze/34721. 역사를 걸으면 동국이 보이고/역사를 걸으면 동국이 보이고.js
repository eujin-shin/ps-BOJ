const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
for (let i = 0; i < n; i++) console.log("I love DGU");
