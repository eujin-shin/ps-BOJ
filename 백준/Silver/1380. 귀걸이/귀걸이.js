const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(n, names, list) {
  const arr = Array.from({ length: n }, () => 0);
  list.forEach(([num, _]) => arr[Number(num) - 1]++);
  return names[arr.indexOf(1)];
}

let i = 1;
while (1) {
  const n = Number(input.shift());
  if (n === 0) {
    break;
  }
  const names = input.splice(0, n);
  const list = input.splice(0, n * 2 - 1).map((str) => str.split(" "));
  console.log(i++, solution(n, names, list));
}
