const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, d, k], stars] = input.map((str) => str.split(" ").map(Number));

function solution(n, d, k, stars) {
  let counts = Array.from({ length: n }, () => 0);
  let answer = 0;
  for (let i = 0; i < d; i++) {
    for (let j = 0; j < n; j++) {
      if (k < counts[j] + stars[j]) {
        answer++;
        counts = [...stars];
        break;
      } else {
        counts[j] += stars[j];
      }
    }
  }
  return answer;
}

console.log(solution(n, d, k, stars));
