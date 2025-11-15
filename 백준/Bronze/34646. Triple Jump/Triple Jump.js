const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], jumps] = input.map((str) => str.split(" ").map(Number));
const targets = jumps.filter((v) => v % 3 === 0).map((v) => v / 3);
const check = (...arr) => {
  const results = new Set();
  for (let a = 0; a < 3; a++) {
    for (let b = 0; b < 3; b++) {
      for (let c = 0; c < 3; c++) {
        results.add(arr[a] + arr[b] + arr[c]);
      }
    }
  }
  return (
    results.size === n &&
    [...results].sort((a, b) => a - b).every((v, idx) => v === jumps[idx])
  );
};
const solution = () => {
  for (let a = 0; a < targets.length; a++) {
    for (let b = a + 1; b < targets.length; b++) {
      for (let c = b + 1; c < targets.length; c++) {
        if (check(targets[a], targets[b], targets[c])) {
          console.log(targets[a], targets[b], targets[c]);
          return;
        }
      }
    }
  }
};
solution();
