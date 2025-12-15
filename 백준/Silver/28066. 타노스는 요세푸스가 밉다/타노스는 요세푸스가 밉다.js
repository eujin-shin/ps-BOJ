const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
const [n, k] = input.split(" ").map(Number);

const calc = (arr, start) => {
  const nextArr = [];
  const size = arr.length;
  let i;
  for (i = start; i < size; i += k) nextArr.push(arr[i]);
  return i - size < nextArr.length
    ? [nextArr, i - size]
    : [undefined, nextArr[nextArr.length - 1]];
};

let cur = Array.from({ length: n }, (_, index) => index + 1);
let start = 0;
while (cur) {
  [cur, start] = calc(cur, start);
}
console.log(start);
