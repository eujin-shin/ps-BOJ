const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const numbers = new Set(Array.from({ length: 49 }, (_, index) => index + 1));
for (let i = 0; i < input.length - 1; ) {
  const n = Number(input[i++]);
  const lotto = new Set();
  for (let x = 0; x < n; x++, i++) {
    input[i].split(" ").forEach((v) => lotto.add(Number(v)));
  }
  console.log(
    new Set([...lotto, ...numbers]).size === lotto.size ? "Yes" : "No"
  );
}
