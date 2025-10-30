const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [first, last] = input.slice(1).reduce(
  (prev, str, idx) => {
    const time = str.split(" ").map(Number);
    if (idx === 0) return [time, time];
    const [s, e] = time;
    const [first, last] = prev;
    return [first[1] > e ? time : first, last[0] < s ? time : last];
  },
  [0, Infinity]
);
console.log(Math.max(0, last[0] - first[1]));
