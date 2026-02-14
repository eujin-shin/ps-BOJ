const fs = require("fs");
const n = Number(fs.readFileSync("/dev/stdin").toString().trim());
let count = 0;
for (let i = 1; i <= n; i++)
  count += String(i).match(/\d*2\d*0\d*2\d*3\d*/g) ? 1 : 0;
console.log(count);
