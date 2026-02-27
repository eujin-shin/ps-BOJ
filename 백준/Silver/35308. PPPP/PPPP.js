const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.slice(1).forEach((t) => {
  const [n, k] = t.split(" ").map(Number);
  const answer =
    n === 1 && k === 1
      ? "1"
      : k === 2
      ? Array.from({ length: n - 1 }, (_, idx) => idx + 2)
          .concat([1])
          .join(" ")
      : "-1";
  console.log(answer);
});
