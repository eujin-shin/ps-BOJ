const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], ...students] = input.map((str) => str.split(" ").map(Number));
const friends = Array.from({ length: n }, (_, i) =>
  Array.from({ length: m }, (_, j) => students[(i + j) % n][j])
);
console.log(n);
friends.forEach((list) => console.log(list.join(" ")));
