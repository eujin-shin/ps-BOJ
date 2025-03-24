const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], ...vertex] = input.map((str) => str.split(" ").map(Number));

function solution(n, vertex) {
  const parents = Array.from({ length: n }, (_, i) => i + 1);

  const find = (x) => (parents[x - 1] === x ? x : find(parents[x - 1]));

  const union = (x, y) => {
    const parentX = find(x);
    const parentY = find(y);

    if (parentX === parentY) {
      return false;
    }

    const update = parentX < parentY ? parentX : parentY;
    parents[parentX - 1] = update;
    parents[parentY - 1] = update;
    return true;
  };

  vertex.sort((a, b) => a[2] - b[2]);
  let sum = 0;
  let count = 0;
  for (let i = 0; count < n - 2; i++) {
    if (union(vertex[i][0], vertex[i][1])) {
      count++;
      sum += vertex[i][2];
    }
  }
  return sum;
}

console.log(solution(n, vertex));
