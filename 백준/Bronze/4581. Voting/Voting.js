const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
function solution(votes) {
  const array = [...votes];
  const x = array.length;
  const y = array.filter((v) => v === "Y").length;
  const n = array.filter((v) => v === "N").length;
  const p = array.filter((v) => v === "P").length;
  const a = array.filter((v) => v === "A").length;
  return x / 2 <= a ? "need quorum" : y < n ? "no" : n < y ? "yes" : "tie";
}
for (let i = 0; i < input.length - 1; i++) {
  console.log(solution(input[i]));
}
