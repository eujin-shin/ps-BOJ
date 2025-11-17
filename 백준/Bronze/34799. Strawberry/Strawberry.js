const fs = require("fs");
const [s, n] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const length = BigInt(s.length);
const shift = BigInt(n) % 26n;
const full = (BigInt(n) - shift) / 26n;
const letter = "rstuvwxyzabcdefghijklnmopq".slice(0, Number(shift));
const count = [...s].filter((l) => letter.includes(l)).length;
console.log((full * length + BigInt(count)).toString());
