const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const n = Number(input[0]);
const arr = input[1].split(" ").map(Number);
const hamburger = input[2].split("");
let answer = true;
for (let i = 0; i < n && answer; i++) {
  if ((i === 0 || i === n - 1) && hamburger[i] !== "a") answer = false;
  if (i > 0 && hamburger[i] === hamburger[i - 1]) answer = false;
  if (--arr[hamburger[i].charCodeAt(0) - "a".charCodeAt(0)] < 0) answer = false;
}
console.log(answer ? "Yes" : "No");
