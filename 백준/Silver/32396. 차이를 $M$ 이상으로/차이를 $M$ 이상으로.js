const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], numbers] = input.map((str) => str.split(" ").map(Number));

function solution(n, m, numbers) {
  const dp = [0, 1];
  for (let i = 1; i < n; i++) {
    const value = numbers[i];
    const diff =
      numbers[i - 1] < value ? value - numbers[i - 1] : numbers[i - 1] - value;
    const notChange = diff < m || dp[1] < dp[0] ? dp[1] : dp[0];
    const change = (dp[1] < dp[0] ? dp[1] : dp[0]) + 1;
    dp[0] = notChange;
    dp[1] = change;
  }
  const answer = dp[0] < dp[1] ? dp[0] : dp[1];
  return answer === Infinity ? -1 : answer;
}

console.log(solution(n, m, numbers));
