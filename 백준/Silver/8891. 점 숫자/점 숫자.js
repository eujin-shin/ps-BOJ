const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...cases] = input.map((str) => str.split(" ").map(Number));

const coord = Array.from({ length: 301 }, () =>
  Array.from({ length: 301 }, () => 0)
);
const arr = new Array();
let num = 1;
for (let yStart = 1; yStart <= 300; yStart++) {
  for (let x = 1, y = yStart; y > 0; x++, y--) {
    coord[y][x] = num;
    arr[num - 1] = [x, y];
    num++;
  }
}

for (let i = 0; i < n; i++) {
  const [a, b] = cases[i];
  const x = arr[a - 1][0] + arr[b - 1][0];
  const y = arr[a - 1][1] + arr[b - 1][1];
  console.log(coord[y][x]);
}
