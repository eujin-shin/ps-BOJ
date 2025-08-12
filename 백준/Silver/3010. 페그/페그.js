const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().split("\n");
let answer = 0;
const dir = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];
for (let y = 0; y < 7; y++) {
  for (let x = 0; x < 7; x++) {
    if (input[y][x] !== ".") continue;
    dir.forEach(([xMove, yMove]) => {
      if (
        input[y + yMove]?.[x + xMove] === "o" &&
        input[y + 2 * yMove]?.[x + 2 * xMove] === "o"
      )
        answer++;
    });
  }
}
console.log(answer);
