const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(house, roads) {
  const parents = Array.from({ length: house }, (_, idx) => idx);
  roads.sort((a, b) => a[2] - b[2]);

  const find = (x) => (parents[x] === x ? x : find(parents[x]));
  const union = (x, y) => {
    const parentX = find(x);
    const parentY = find(y);
    if (parentX === parentY) {
      return false;
    }
    const min = parentX < parentY ? parentX : parentY;
    parents[parentX] = min;
    parents[parentY] = min;
    return true;
  };

  let sum = 0;
  roads.forEach(([x, y, z]) => {
    if (!union(x, y)) {
      sum += z;
    }
  });
  return sum;
}

while (1) {
  const [m, n] = input.shift().split(" ").map(Number);
  if (m === 0 && n === 0) break;
  const roads = input.splice(0, n).map((str) => str.split(" ").map(Number));
  console.log(solution(m, roads));
}
