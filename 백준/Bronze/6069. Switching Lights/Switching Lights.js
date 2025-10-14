const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...queries] = input.map((str) => str.split(" ").map(Number));
const on = Array.from({ length: n }, () => false);
queries.forEach(([a, s, e]) => {
  if (a === 0) {
    for (let x = s - 1; x < e; x++) on[x] = !on[x];
  } else {
    let sum = 0;
    for (let x = s - 1; x < e; x++) sum += on[x] ? 1 : 0;
    console.log(sum);
  }
});
