const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
for (let i = 0; i < input.length - 1; i++) {
  const [start, action, value] = input[i].split(" ");
  const balance = Number(start) + (action === "W" ? -1 : 1) * value;
  console.log(-200 <= balance ? balance : "Not allowed");
}
