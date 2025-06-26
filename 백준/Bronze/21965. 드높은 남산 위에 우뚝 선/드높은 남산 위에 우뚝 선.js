const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], numbers] = input.map((str) => str.split(" ").map(Number));
function solution(n, numbers) {
  let isDown = false;
  for (let i = 1; i < n; i++) {
    if (
      numbers[i - 1] === numbers[i] ||
      (isDown && numbers[i - 1] < numbers[i])
    ) {
      return "NO";
    }
    isDown = numbers[i] < numbers[i - 1];
  }
  return "YES";
}
console.log(solution(n, numbers));
