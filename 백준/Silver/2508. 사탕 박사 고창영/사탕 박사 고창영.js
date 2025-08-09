const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let index = 0;
const t = Number(input[index++]);
const vertical = "vo^";
const horizontal = ">o<";

function solution(r, c, candies) {
  let sum = 0;
  let target = 0;
  for (let x = 0; x < c; x++) {
    target = 0;
    for (let y = 0; y < r; y++) {
      target =
        candies[y][x] === vertical[target]
          ? target + 1
          : candies[y][x] === vertical[0]
          ? 1
          : 0;
      if (target === 3) {
        target = 0;
        sum++;
      }
    }
  }
  for (let y = 0; y < r; y++) {
    target = 0;
    for (let x = 0; x < c; x++) {
      target =
        candies[y][x] === horizontal[target]
          ? target + 1
          : candies[y][x] === horizontal[0]
          ? 1
          : 0;
      if (target === 3) {
        target = 0;
        sum++;
      }
    }
  }
  return sum;
}
index++;
for (let i = 0; i < t; i++) {
  const [r, c] = input[index++].split(" ").map(Number);
  console.log(solution(r, c, input.slice(index, index + r)));
  index += r + 1;
}
