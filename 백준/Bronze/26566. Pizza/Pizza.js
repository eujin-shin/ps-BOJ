const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], ...pizza] = input.map((str) => str.split(" ").map(Number));

for (let i = 0; i < n * 2; i += 2) {
  console.log(
    pizza[i][0] / pizza[i][1] <
      (Math.pow(pizza[i + 1][0], 2) * Math.PI) / pizza[i + 1][1]
      ? "Whole pizza"
      : "Slice of pizza"
  );
}
