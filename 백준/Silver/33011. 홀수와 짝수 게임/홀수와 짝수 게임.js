const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(cards) {
  const [min, max] = cards
    .reduce(
      ([odds, evens], v) =>
        v % 2 === 0 ? [odds, evens + 1] : [odds + 1, evens],
      [0, 0]
    )
    .sort((a, b) => a - b);
  return min < max && max % 2 === 1 ? "amsminn" : "heeda0528";
}

while (0 < input.length) {
  const [, cards] = input.splice(0, 2).map((str) => str.split(" ").map(Number));
  console.log(solution(cards));
}
