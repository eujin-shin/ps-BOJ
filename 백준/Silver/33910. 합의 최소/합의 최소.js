const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], numbers] = input.map((str) => str.split(" ").map(Number));

function solution(n, numbers) {
  const stack = [];
  for (let i = 0; i < n; i++) {
    const item = [numbers[i], 1];
    for (let i = stack.length - 1; i >= 0; i--) {
      if (stack[i][0] < item[0]) {
        break;
      }
      item[1] += stack[i][1];
      stack.splice(-1);
    }
    stack.push(item);
  }
  return stack.reduce((sum, [x, count]) => sum + x * count, 0);
}

console.log(solution(n, numbers));
