const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const scores = input[1].split(" ").map(Number);
const answer = input.slice(2).reduce(
  ([id, max], str) => {
    const [x, ...res] = str.split(" ");
    const score = res.reduce(
      (sum, v, idx) => sum + (v === "X" ? 0 : scores[idx]),
      0
    );
    return score > max || (score === max && Number(x) < id)
      ? [Number(x), score]
      : [id, max];
  },
  [0, -1]
);
console.log(answer.join(" "));
