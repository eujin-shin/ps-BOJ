const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, ...cases] = input.map(Number);
const history = {};
const gcd = (a, b) =>
  a % b === 0 ? b : b < a % b ? gcd(a % b, b) : gcd(b, a % b);
function solution(x) {
  if (history[x] === undefined) {
    let answer = 0;
    for (let i = 1; i * i <= x; i++) {
      if (x % i !== 0) continue;
      const j = x / i;
      const k = i < j ? gcd(j, i) : gcd(i, j);
      answer += k === 1 ? 1 : 0;
    }
    history[x] = answer;
  }
  return history[x];
}
for (let i = 0; i < n; i++) {
  console.log(solution(cases[i]));
}
