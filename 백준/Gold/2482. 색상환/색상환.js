const fs = require("fs");
const [n, k] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n")
  .map(Number);

function solution(n, k) {
  const MOD = 1000000003;
  let prev = [[1], [0, 1, 1]];
  for (let i = 3; i <= n; i++) {
    const cur = [];
    const bound = Math.ceil(i / 2);
    for (let j = 0; j <= bound; j++) {
      cur[j] = [
        ((prev[j]?.[0] || 0) + (prev[j]?.[2] || 0)) % MOD,
        ((prev[j]?.[1] || 0) + (prev[j]?.[3] || 0)) % MOD,
        (prev[j - 1]?.[0] || 0) % MOD,
        (prev[j - 1]?.[1] || 0) % MOD,
      ];
    }
    prev = cur;
  }
  return prev[k] ? (prev[k][0] + prev[k][1] + prev[k][2]) % MOD : 0;
}

console.log(solution(n, k));
