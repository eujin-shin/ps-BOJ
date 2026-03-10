const fs = require("fs");
const [, ...arr] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const mapped = arr.map((str) => {
  const [name, ...nums] = str.split(" ");
  const [score, risk, cost] = nums.map(Number);
  const value = Math.floor(Math.pow(score, 3) / (cost * (risk + 1)));
  return { name, cost, value };
});
const { name } = mapped.sort((a, b) => {
  if (a.value !== b.value) return b.value - a.value;
  if (a.cost !== b.cost) return a.cost - b.cost;
  return a.name < b.name ? -1 : 1;
})[1];
console.log(name);
