const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[, k], track] = input.map((str) => str.split(" ").map(Number));
console.log(
  track.reduce(
    ([prev, sum], v) => {
      if (sum === -1) return [v, -1];
      if (prev < v) return [v, sum];
      else if (prev < v + k) return [v + k, sum + 1];
      else return [v, -1];
    },
    [-1, 0]
  )[1]
);
