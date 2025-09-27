const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const target = input[1];
let count = 0;
for (let i = 2; i < input.length; i++) {
  let success = false;
  for (let space = 1; space < input[i].length; space++) {
    for (let start = 0; start < input[i].length; start++) {
      for (let x = 0; x < target.length; x++) {
        const pos = start + space * x;
        if (input[i][pos] !== target[x]) break;
        if (x === target.length - 1) success = true;
      }
      if (success) break;
    }
    if (success) break;
  }
  count += success ? 1 : 0;
}
console.log(count);
