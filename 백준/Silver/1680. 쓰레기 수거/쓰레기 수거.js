const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[t], ...arr] = input.map((str) => str.split(" ").map(Number));
let row = 1;
for (let i = 0; i < t; i++) {
  const [k, n] = arr[row++];
  const [sum] = arr.slice(row, row + n).reduce(
    ([sum, cur], [x, w], idx) => {
      if (cur + w > k) {
        sum += x * 2;
        cur = 0;
      }
      cur += w;
      if (cur === k || idx === n - 1) {
        sum += x * 2;
        cur = 0;
      }
      return [sum, cur];
    },
    [0, 0]
  );
  console.log(sum);
  row += n;
}
