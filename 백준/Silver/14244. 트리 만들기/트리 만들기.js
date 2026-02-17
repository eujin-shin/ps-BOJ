const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [n, m] = input.split(" ").map(Number);
const leaf = new Set([0, 1]);
const node = new Set();
const answer = ["0 1"];
for (let i = 2; i < n; i++) {
  const x = (function () {
    if (leaf.size === m || node.size === 0) {
      const x = leaf.values().next().value;
      leaf.delete(x);
      node.add(x);
      return x;
    }
    return node.values().next().value;
  })();
  leaf.add(i);
  answer.push(`${x} ${i}`);
}
console.log(answer.join("\n"));
