const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

let lineIdx = 0;
const t = Number(input[lineIdx++]);
const output = [];

for (let testCase = 1; testCase <= t; testCase++) {
  const n = Number(input[lineIdx++]);
  const k = Number(input[lineIdx++]);
  const parent = Array.from({ length: n }, (_, i) => i);

  const find = (x) => {
    if (parent[x] !== x) parent[x] = find(parent[x]);
    return parent[x];
  };

  const union = (a, b) => {
    const pa = find(a);
    const pb = find(b);
    if (pa !== pb) {
      parent[pb] = pa;
    }
  };

  for (let i = 0; i < k; i++) {
    const [a, b] = input[lineIdx++].split(" ").map(Number);
    union(a, b);
  }

  const m = Number(input[lineIdx++]);
  output.push(`Scenario ${testCase}:`);

  for (let i = 0; i < m; i++) {
    const [a, b] = input[lineIdx++].split(" ").map(Number);
    output.push(find(a) === find(b) ? "1" : "0");
  }

  if (testCase < t) output.push("");
}

console.log(output.join("\n"));
