const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], numbers] = input.map((str) => str.split(" ").map(Number));

function solution(n, numbers) {
  let max = 0;
  const findNumber = (r, len, sum) => {
    if (r === len) {
      max = sum <= n && max < sum ? sum : max;
    } else {
      numbers.forEach((num) => findNumber(r + 1, len, sum * 10 + num));
    }
  };
  for (let len = 1; len <= String(n).length; len++) {
    findNumber(0, len, 0);
  }
  return max;
}

console.log(solution(n, numbers));
