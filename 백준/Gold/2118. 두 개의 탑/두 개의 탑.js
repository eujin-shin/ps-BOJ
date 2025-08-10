const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n, ...towers] = input.map(Number);
const sum = towers.reduce((prev, cur) => prev + cur, 0);
let max = 0;
let distance = towers[0];
let end = 1;
for (let start = 0; start < n; start++) {
  if (start === end) {
    distance += towers[end];
    end = (end + 1) % n;
  }
  while (distance + towers[end] <= sum - (distance + towers[end])) {
    distance += towers[end];
    end = (end + 1) % n;
  }
  const min = Math.min(distance, sum - distance);
  max = Math.max(max, min, sum - (distance + towers[end]));
  distance -= towers[start];
}
console.log(max);
