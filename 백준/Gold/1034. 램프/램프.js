const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const k = Number(input.splice(-1));

function solution(input, k) {
  const count = new Map();
  input.forEach((str) => count.set(str, (count.get(str) || 0) + 1));

  const isAble = (str) => {
    const x = [...str].filter((v) => v === "0").length;
    return x <= k && (k - x) % 2 === 0;
  };

  const set = [...new Set(input)];
  set.sort((a, b) => count.get(b) - count.get(a));
  for (let i = 0; i < set.length; i++) {
    if (isAble(set[i])) {
      return count.get(set[i]);
    }
  }
  return 0;
}

console.log(solution(input, k));
