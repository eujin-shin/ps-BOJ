const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const sequences = input
  .map((str) => str.split(" ").slice(1).map(Number))
  .slice(0, -1);

function solution(sequence) {
  const arr = [];
  sequence.reduce((prev, v, idx) => {
    arr.push(...Array.from({ length: v - prev }, () => idx + 1));
    return v;
  }, 0);
  return arr.join(" ");
}

sequences.forEach((v) => console.log(solution(v)));
