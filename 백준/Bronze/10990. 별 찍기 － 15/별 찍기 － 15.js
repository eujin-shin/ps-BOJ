const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

const n = Number(input);

function solution(n) {
  for (let i = 0, space = -1; i < n; i++, space += 2) {
    const left = n - 1 - i;
    const string =
      " ".repeat(left) + "*" + (space < 0 ? "" : " ".repeat(space) + "*");
    console.log(string);
  }
}

solution(n);
