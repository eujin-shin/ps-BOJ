const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let index = 0;
while (1) {
  const n = Number(input[index++]);
  if (n < 0) break;
  const sorted = input
    .slice(index, index + n)
    .map((str) => {
      index++;
      const [a, b, c, name] = str.split(" ");
      const v = [a, b, c].map(Number).reduce((prev, v) => prev * v, 1);
      return [v, name];
    })
    .sort((a, b) => a[0] - b[0]);
  console.log(`${sorted[n - 1][1]} took clay from ${sorted[0][1]}.`);
}
