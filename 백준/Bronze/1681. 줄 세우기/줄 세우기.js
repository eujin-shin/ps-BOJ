const fs = require("fs");
const [n, l] = fs.readFileSync("/dev/stdin").toString().trim().split(" ");
let x = 0;
let answer = 0;
const k = String(n);
while (x < k) {
  answer++;
  if (!String(answer).includes(l)) x++;
}
console.log(answer);
