const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], ...vertex] = input.map((str) => str.split(" ").map(Number));

function solution(n, vertex) {
  const root = Array.from({ length: n }, (_, idx) => idx);

  const find = (a) => (root[a] === a ? a : (root[a] = find(root[a])));

  const union = (a, b) => {
    const rootA = find(a);
    const rootB = find(b);

    if (rootA < rootB) {
      root[rootB] = rootA;
    } else {
      root[rootA] = rootB;
    }
    return rootA !== rootB;
  };

  return vertex.reduce(
    (answer, [a, b], idx) => (answer === 0 && !union(a, b) ? idx + 1 : answer),
    0
  );
}

console.log(solution(n, vertex));
