const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [, ...keys] = input.map((str) => str.split(" "));
console.log(
  keys
    .sort((a, b) =>
      Number(a[1]) === Number(b[1])
        ? Number(a[0]) - Number(b[0])
        : Number(a[1]) - Number(b[1])
    )
    .map((v) => v[2])
    .join("")
);
