const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);
const numbers = input.map((str) => str.split(" ").map(Number));

function solution(n, numbers) {
  const asc = [];
  const desc = [];
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      asc[asc.length] = numbers[i][0] + numbers[j][1];
      desc[desc.length] = numbers[i][2] + numbers[j][3];
    }
  }
  asc.sort((a, b) => a - b);
  desc.sort((a, b) => b - a);

  let i = -1;
  let j = 0;
  let count = 0;
  while (++i < asc.length) {
    while (0 < asc[i] + desc[j] && j < desc.length) j++;
    if (j === desc.length) break;
    count += asc[i] + desc[j] === 0 ? 1 : 0;
  }
  return count;
}

function solutionMap(n, numbers) {
  const map = new Map();
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const a = numbers[i][0] + numbers[j][1];
      map.set(a, (map.get(a) || 0) + 1);
    }
  }

  let count = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      const b = numbers[i][2] + numbers[j][3];
      count += map.get(-b) || 0;
    }
  }
  return count;
}

console.log(solutionMap(n, numbers));
