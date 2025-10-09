const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
for (let i = 1; i < input.length; i++) {
  const [b, d] = input[i].split(" ");
  const sum = d.split("").reduce((prev, v) => prev + Number(v), 0);
  console.log(sum % (b - 1));
}
