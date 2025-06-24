const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, m], periods, plan] = input.map((str) => str.split(" ").map(Number));
const tangled = Array.from({ length: n }, () => false);
const history = Array.from({ length: n }, () => 0);
for (let i = 1; i <= m + 1; i++) {
  for (let j = 0; j < n; j++) {
    tangled[j] = tangled[j] || periods[j] < i - history[j];
  }
  if (m < i) {
    break;
  }
  const x = plan[i - 1] - 1;
  tangled[x] = tangled[x] && history[x] !== i - 1;
  history[x] = i;
}
console.log(tangled.filter((v) => v).length);
