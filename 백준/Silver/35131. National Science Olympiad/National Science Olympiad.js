const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const answer = input
  .slice(1)
  .map((str) => {
    const [name, ...score] = str.split(" ");
    const [a, b, c, d] = score.map(Number);
    return { name, point: a + c, penalty: b + d };
  })
  .sort((a, b) => {
    if (a.point === b.point && a.penalty === b.penalty)
      return a.name < b.name ? -1 : 1;
    else if (a.point === b.point) return a.penalty - b.penalty;
    return b.point - a.point;
  })
  .map((v) => v.name)
  .join("\n");
console.log(answer);
