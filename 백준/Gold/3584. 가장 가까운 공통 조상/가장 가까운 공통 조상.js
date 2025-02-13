const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const t = Number(firstLine);
const numbers = input.map((str) => str.split(" ").map(Number));

function solution(n, a, b, vertex) {
  const tree = Array.from({ length: n + 1 }, () => new Array());
  const parents = Array.from({ length: n + 1 }, () => 0);
  const children = Array.from({ length: n + 1 }, () => 0);

  vertex.forEach(([x, y]) => {
    parents[y] = x;
    children[x]++;
    tree[x].push(y);
  });

  let root = vertex[0][0];
  while (parents[root] !== 0) {
    root = parents[root];
  }

  const levels = Array.from({ length: n + 1 }, () => 0);
  const queue = [root];
  let front = 0;
  while (front !== queue.length) {
    const cur = queue[front++];
    tree[cur].forEach((child) => {
      levels[child] = levels[cur] + 1;
      queue.push(child);
    });
  }

  while (a !== b) {
    const depthA = levels[a];
    const depthB = levels[b];
    a = depthA >= depthB ? parents[a] : a;
    b = depthA <= depthB ? parents[b] : b;
  }
  return a;
}

for (let i = 0; i < t; i++) {
  const [[n]] = numbers;
  const [, ...vertex] = numbers.splice(0, n + 1);
  const [[a, b]] = vertex.splice(-1);
  console.log(solution(n, a, b, vertex));
}
