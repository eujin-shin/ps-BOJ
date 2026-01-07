const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const number = new Map();
["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"].forEach((v, idx) =>
  v.split("").forEach((l) => number.set(l, idx + 2))
);
input.slice(1).forEach((word) =>
  console.log(
    word
      .split("")
      .map((v) => number.get(v.toUpperCase()))
      .join("")
  )
);
