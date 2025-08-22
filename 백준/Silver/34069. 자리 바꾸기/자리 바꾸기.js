const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n, m], ...seats] = input.map((str) => str.split(" ").map(Number));
if ((n * m) % 2 === 0) {
  console.log("Yes");
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j += 2) {
      const temp = seats[i][j];
      if (j === m - 1 && i % 2 === 0) {
        seats[i][j] = seats[i + 1][j];
        seats[i + 1][j] = temp;
      } else if (j < m - 1) {
        seats[i][j] = seats[i][j + 1];
        seats[i][j + 1] = temp;
      }
    }
  }
  seats.forEach((arr) => console.log(arr.join(" ")));
} else {
  console.log("No");
}
