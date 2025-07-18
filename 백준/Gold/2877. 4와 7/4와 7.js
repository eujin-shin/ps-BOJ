const fs = require("fs");
let n = Number(fs.readFileSync("/dev/stdin").toString().trim()) - 1;
let x = 2;
while (x <= n) {
  n -= x;
  x *= 2;
}
let answer = "";
x /= 2;
while (1 <= x) {
  if (x <= n) {
    n -= x;
    answer += "7";
  } else {
    answer += "4";
  }
  x /= 2;
}
console.log(answer);
