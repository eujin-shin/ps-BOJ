const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[, k], arr] = input.map((str) => str.split(" ").map(Number));
const [sum] = arr.reduce(
  ([sum, { count, min, max }], v) => {
    const height = count + 1;
    min = min === undefined || v < min ? v : min;
    max = max === undefined || max < v ? v : max;
    const width = max - min + 1;
    return height * width <= k
      ? [sum, { count: height, min, max }]
      : [sum + 1, { count: 1, min: v, max: v }];
  },
  [1, { count: 0 }]
);
console.log(sum);
