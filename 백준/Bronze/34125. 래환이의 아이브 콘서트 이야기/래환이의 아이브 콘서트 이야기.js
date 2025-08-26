const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, m], ...seats] = input.map((str) => str.split(" ").map(Number));
function solution(n, m, seats) {
  let answer = -1;
  let x;
  let y;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      if (seats[i][j] === 1) continue;
      const value = i + 1 + Math.abs((m + 1) / 2 - (j + 1));
      if (answer < 0 || value < answer) {
        x = j + 1;
        y = i + 1;
        answer = value;
      }
    }
  }
  return answer !== -1 ? `${y} ${x}` : -1;
}
console.log(solution(n, m, seats));
