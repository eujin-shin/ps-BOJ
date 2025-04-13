const fs = require("fs");
const [firstLine, input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);
const scores = input.split(" ").map(Number);

function solution(n, scores) {
  const OFFSET = 10000;
  const indexList = Array.from({ length: 20001 });
  scores
    .sort((a, b) => a - b)
    .forEach((v, index) => {
      indexList[OFFSET + v] = indexList[OFFSET + v] || { first: index };
      indexList[OFFSET + v].last = index;
    });

  let answer = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const need = -(scores[i] + scores[j]);
      if (indexList[need + OFFSET] === undefined) {
        continue;
      }
      const { first, last } = indexList[need + OFFSET];
      answer +=
        last - first + 1 - (first <= j ? Math.min(last, j) - first + 1 : 0);
    }
  }
  return answer;
}

console.log(solution(n, scores));
