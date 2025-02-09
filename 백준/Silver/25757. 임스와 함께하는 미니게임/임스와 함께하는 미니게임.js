const fs = require("fs");
const [firstLine, ...names] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, game] = firstLine.split(" ");

function solution(game, names) {
  const player = {
    Y: 1,
    F: 2,
    O: 3,
  };
  const set = new Set(names);
  return Math.floor(set.size / player[game]);
}

console.log(solution(game, names));
