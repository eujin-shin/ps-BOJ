const fs = require("fs");
const input = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split(":")
  .map(Number);
let count = 0;
for (let h = 0; h < 3; h++) {
  for (let m = 0; m < 3; m++) {
    for (let s = 0; s < 3; s++) {
      if (h !== m && m !== s && s !== h) {
        count +=
          0 < input[h] &&
          input[h] < 13 &&
          0 <= input[m] &&
          input[m] < 60 &&
          0 <= input[s] &&
          input[s] < 60;
      }
    }
  }
}
console.log(count);
