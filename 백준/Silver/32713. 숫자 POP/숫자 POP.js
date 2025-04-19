const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, k], numbers] = input.map((str) => str.split(" ").map(Number));

function solution(n, k, numbers) {
  let max = 0;
  for (let i = 0; i < n; i++) {
    let sequence = 1;
    const value = numbers[i];
    for (let j = i + 1, count = 0; j < n && count <= k; j++) {
      if (numbers[j] === value) {
        sequence++;
      } else {
        count++;
      }
    }
    max = max < sequence ? sequence : max;
  }
  return max;
}

console.log(solution(n, k, numbers));
