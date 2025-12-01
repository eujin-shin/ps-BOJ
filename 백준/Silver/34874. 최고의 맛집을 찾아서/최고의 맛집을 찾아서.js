const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, m], ...scores] = input.map((str) => str.split(" ").map(Number));
const bestScore = scores.map((arr) => Math.max(...arr));
const answer = [];
for (let res = 0; res < m; res++) {
  let count = 0;
  for (let person = 0; person < n; person++) {
    if (scores[person][res] !== bestScore[person]) count++;
  }
  answer.push(count);
}
console.log(answer.join(" "));
