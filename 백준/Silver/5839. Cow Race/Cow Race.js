const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...records] = input.map((str) => str.split(" ").map(Number));
const recordToArr = (record) => {
  const arr = record
    .map(([speed, time]) => Array.from({ length: time }, () => speed))
    .flat();
  arr.forEach((_, idx) => (arr[idx] += arr[idx - 1] || 0));
  return arr;
};
const bessie = recordToArr(records.slice(0, n));
const elsie = recordToArr(records.slice(n));
let b = undefined;
let count = 0;
bessie.forEach((v, idx) => {
  const cur = v > elsie[idx] ? "b" : v < elsie[idx] ? "a" : undefined;
  if ((b === "a" && cur === "b") || (b === "b" && cur === "a")) count++;
  b = cur !== undefined ? cur : b;
});
console.log(count);
