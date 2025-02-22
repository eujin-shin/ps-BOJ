const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const lines = input.map((str) => str.split(" "));

function solution(lines) {
  lines.forEach((line, index) => {
    const reversed = line.reverse().join(" ");
    console.log(`Case #${index + 1}: ${reversed}`);
  });
  return;
}

solution(lines);
