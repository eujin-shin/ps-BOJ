const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], answers, submits] = input.map((str) => str.split(" "));
function solution(n, answers, submits) {
  const indexes = new Map(submits.map((v, idx) => [v, idx]));
  let total = 0;
  let correct = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      total++;
      correct += indexes.get(answers[i]) < indexes.get(answers[j]);
    }
  }
  return `${correct}/${total}`;
}
console.log(solution(n, answers, submits));
