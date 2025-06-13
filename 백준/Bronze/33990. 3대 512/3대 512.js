const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...records] = input.map((str) => str.split(" ").map(Number));

function solution(records) {
  return records.reduce((prev, [a, b, c]) => {
    const sum = a + b + c;
    return 512 <= sum && (prev < 0 || sum < prev) ? sum : prev;
  }, -1);
}
console.log(solution(records));
