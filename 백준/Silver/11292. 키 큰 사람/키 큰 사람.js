const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let r = 0;
while (1) {
  const n = Number(input[r++]);
  if (n === 0) break;
  let names = [];
  let max = 0;
  for (let i = 0; i < n; i++) {
    const [name, x] = input[r++].split(" ");
    const height = Number(x);
    if (max < height) {
      names = [name];
      max = height;
    } else if (max === height) {
      names.push(name);
    }
  }
  console.log(names.join(" "));
}
