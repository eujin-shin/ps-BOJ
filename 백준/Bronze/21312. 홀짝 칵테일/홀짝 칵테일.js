const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();

function solution(list) {
  const tastes = [];
  for (let i = 1; i < 8; i++) {
    let x = i;
    let taste = 1;
    for (let j = 4, idx = 0; idx < 3; j /= 2, idx++) {
      if (j <= x) {
        x -= j;
        taste *= list[idx];
      }
    }
    tastes.push(taste);
  }
  return tastes.sort((a, b) => {
    if ((a + b) % 2 === 0) {
      return b - a;
    } else if (a % 2 === 0) {
      return 1;
    } else {
      return -1;
    }
  })[0];
}

console.log(solution(input.split(" ").map(Number)));
