const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);
const bridges = input.map((str) => str.split(" ").map(Number));

function solution(n, bridges) {
  const parent = Array.from({ length: n }, (_, idx) => idx + 1);
  const find = (x) => {
    return parent[x - 1] === x ? x : find(parent[x - 1]);
  };
  const union = (a, b) => {
    const parentA = find(a);
    const parentB = find(b);
    parent[parentA - 1] = parentA < parentB ? parentA : parentB;
    parent[parentB - 1] = parentA < parentB ? parentA : parentB;
  };
  for (let i = 0; i < n - 2; i++) {
    union(...bridges[i]);
  }
  const findDifferent = () => {
    for (let i = 2; i <= n; i++) {
      if (find(i) !== parent[0]) return i;
    }
  };
  return `${1} ${findDifferent()}`;
}

console.log(solution(n, bridges));
