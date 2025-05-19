const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[h, w], [n], ...stickers] = input.map((str) =>
  str.split(" ").map(Number)
);

function solution(h, w, n, stickers) {
  let answer = 0;
  const getValue = (i, j) => {
    const [ai, bi] = stickers[i];
    const [aj, bj] = stickers[j];
    return (ai + aj <= h && Math.max(bi, bj) <= w) ||
      (ai + aj <= w && Math.max(bi, bj) <= h) ||
      (ai + bj <= h && Math.max(aj, bi) <= w) ||
      (ai + bj <= w && Math.max(aj, bi) <= h) ||
      (bi + bj <= h && Math.max(ai, aj) <= w) ||
      (bi + bj <= w && Math.max(ai, aj) <= h) ||
      (aj + bi <= h && Math.max(ai, bj) <= w) ||
      (aj + bi <= w && Math.max(ai, bj) <= h)
      ? ai * bi + aj * bj
      : 0;
  };
  for (let x = 0; x < n - 1; x++) {
    for (let y = x + 1; y < n; y++) {
      const val = getValue(x, y);
      answer = Math.max(answer, val);
    }
  }
  return answer;
}

console.log(solution(h, w, n, stickers));
