const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], ...board] = input.map((str) => str.split(" ").map(Number));

function solution(n, board) {
  function Position() {
    this.diagonal = 0;
    this.horizontal = 0;
    this.vertical = 0;
  }
  const dp = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => new Position())
  );

  dp[0][1].horizontal = 1;
  for (let y = 0; y < n; y++) {
    for (let x = y === 0 ? 2 : 0; x < n; x++) {
      if (board[y][x] !== 0) continue;
      dp[y][x].horizontal =
        (dp[y][x - 1]?.horizontal || 0) + (dp[y][x - 1]?.diagonal || 0);
      dp[y][x].vertical =
        (dp[y - 1]?.[x].vertical || 0) + (dp[y - 1]?.[x].diagonal || 0);
      dp[y][x].diagonal =
        board[y - 1]?.[x] === 0 && board[y][x - 1] === 0
          ? dp[y - 1][x - 1].diagonal +
            dp[y - 1][x - 1].horizontal +
            dp[y - 1][x - 1].vertical
          : 0;
    }
  }

  const { diagonal, horizontal, vertical } = dp[n - 1][n - 1];
  return diagonal + horizontal + vertical;
}

console.log(solution(n, board));
