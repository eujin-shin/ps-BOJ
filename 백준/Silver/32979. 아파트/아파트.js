const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], , hands, targets] = input.map((str) => str.split(" ").map(Number));
let x = 1;
const count = n * 2;
console.log(targets.map((v) => hands[((x += v - 1) - 1) % count]).join(" "));
