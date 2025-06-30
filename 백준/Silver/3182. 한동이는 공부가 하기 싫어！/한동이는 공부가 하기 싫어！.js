const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, ...arr] = input.map(Number);
function solution(n, arr) {
  let max = 0;
  let answer = 0;
  for (let i = 0; i < n; i++) {
    const history = Array.from({ length: n }, () => 0);
    history[i] = 1;
    let x = i;
    let count = 1;
    while (history[arr[x] - 1] === 0) {
      x = arr[x] - 1;
      history[x] = 1;
      count++;
    }
    if (max < count) {
      max = count;
      answer = i + 1;
    }
  }
  return answer;
}
console.log(solution(n, arr));
