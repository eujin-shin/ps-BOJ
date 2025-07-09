const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
const [n, m] = firstLine.split(" ").map(Number);
const names = input.splice(0, n);
function solution(n, m, names, initials) {
  const addresses = new Map();
  for (let i = 0; i < n; i++) {
    const init = names[i]
      .split(" ")
      .map((str) => str[0])
      .join("");
    addresses.set(init, addresses.has(init) ? "ambiguous" : names[i]);
  }
  for (let i = 0; i < m; i++) {
    console.log(addresses.get(initials[i]) || "nobody");
  }
}
solution(n, m, names, input);
