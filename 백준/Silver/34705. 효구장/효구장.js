const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...cases] = input.map((str) => str.split(" ").map(Number));
for (let i = 0, idx = 0; i < n; i++, idx += 2) {
  const [x, y] = cases[idx];
  const weight = [0];
  let answer = false;
  for (let k = 0; k < 5 && !answer; k++) {
    const cur = cases[idx + 1][k];
    weight.push(
      ...weight.map((v) => {
        answer = answer || (x <= v + cur && v + cur <= y);
        return v + cur;
      })
    );
  }
  console.log(answer ? "YES" : "NO");
}
