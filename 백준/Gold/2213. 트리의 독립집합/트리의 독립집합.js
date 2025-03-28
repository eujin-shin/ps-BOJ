/*
     1   2   3  4  5  6  7
on : 140 120 60 10 20 20 70
off: 130 130 20 20 0  70 0


1 - 2 - 3 - 4 - 5
      \ 6 - 7

*/

const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);
const [weights, ...vertex] = input.map((str) => str.split(" ").map(Number));

function solution(n, weights, vertex) {
  const graph = Array.from({ length: n }, () => new Array());
  vertex.forEach(([x, y]) => {
    graph[x - 1][graph[x - 1].length] = y;
    graph[y - 1][graph[y - 1].length] = x;
  });

  const parents = Array.from({ length: n }, () => -1);
  const children = Array.from({ length: n }, () => 0);
  const queue = [1];
  const leaves = [];
  parents[0] = 0;
  while (0 < queue.length) {
    const cur = queue.shift();
    graph[cur - 1].forEach((v) => {
      if (parents[v - 1] < 0) {
        parents[v - 1] = cur;
        queue[queue.length] = v;
        children[cur - 1]++;
      }
    });
    if (children[cur - 1] === 0) {
      leaves[leaves.length] = cur;
    }
  }

  function Record() {
    this.value = 0;
    this.set = new Array();
  }

  function Node() {
    this.on = new Record();
    this.off = new Record();
  }

  const dp = Array.from({ length: n }, () => new Node());
  while (0 < leaves.length) {
    const cur = leaves.shift();

    dp[cur - 1].on.value = weights[cur - 1];
    dp[cur - 1].on.set = [cur];
    for (let i = 0; i < graph[cur - 1].length; i++) {
      const child = graph[cur - 1][i];
      if (child === parents[cur - 1]) {
        continue;
      }

      dp[cur - 1].on.value += dp[child - 1].off.value;
      dp[cur - 1].on.set.push(...dp[child - 1].off.set);

      const { value: maxValue, set: maxSet } =
        dp[child - 1].on.value < dp[child - 1].off.value
          ? dp[child - 1].off
          : dp[child - 1].on;
      dp[cur - 1].off.value += maxValue;
      dp[cur - 1].off.set.push(...maxSet);
    }

    if (--children[parents[cur - 1] - 1] === 0) {
      leaves[leaves.length] = parents[cur - 1];
    }
  }

  return dp[0].on.value < dp[0].off.value ? dp[0].off : dp[0].on;
}

const { value, set } = solution(n, weights, vertex);
console.log(value);
console.log(set.sort((a, b) => a - b).join(" "));
