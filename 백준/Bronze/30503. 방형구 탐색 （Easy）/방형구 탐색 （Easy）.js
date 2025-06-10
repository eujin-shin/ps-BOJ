const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [, flowers, [m], ...queries] = input.map((str) =>
  str.split(" ").map(Number)
);

function solution(m, flowers, queries) {
  for (let i = 0; i < m; i++) {
    const [x, l, r, k] = queries[i];
    let count = 0;
    for (let idx = l - 1; idx < r; idx++) {
      if (x === 1 && flowers[idx] === k) {
        count++;
      } else if (x === 2) {
        flowers[idx] = 0;
      }
    }
    if (x === 1) {
      console.log(count);
    }
  }
}

solution(m, flowers, queries);
