const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [, weights, , beads] = input.map((str) => str.split(" ").map(Number));

function solution(weights, beads) {
  const sum = weights.reduce((sum, v) => sum + v, 0);
  const OFFSET = sum;
  const arr = [];
  arr[OFFSET] = 1;

  const isVisited = (x, idx) => arr[x + OFFSET] && arr[x + OFFSET] < idx + 2;

  weights.reduce((sum, v, idx) => {
    for (let i = -(sum + v); i <= sum + v; i++) {
      arr[i + OFFSET] =
        !arr[i + OFFSET] && (isVisited(i - v, idx) || isVisited(i + v, idx))
          ? idx + 2
          : arr[i + OFFSET];
    }
    return sum + v;
  }, 0);

  return beads.map((v) => (arr[v + OFFSET] ? "Y" : "N")).join(" ");
}

console.log(solution(weights, beads));
