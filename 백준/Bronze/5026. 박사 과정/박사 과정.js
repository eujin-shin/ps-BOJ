const fs = require("fs");
const [, ...questions] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(question) {
  if (question === "P=NP") {
    return "skipped";
  }
  const [a, b] = question.split("+");
  return Number(a) + Number(b);
}

questions.forEach((v) => console.log(solution(v)));
