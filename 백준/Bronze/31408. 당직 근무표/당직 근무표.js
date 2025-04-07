const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const list = input.split(" ").map(Number);

function solution(list) {
  const a = Math.ceil(list.length / 2);
  const b = list.length - a;
  const count = new Map();
  list.forEach((v) => {
    count.set(v, (count.get(v) || 0) + 1);
  });
  const [first, second] = [...count.values()].sort((a, b) => b - a);
  return a < first || b < second ? "NO" : "YES";
}

console.log(solution(list));
