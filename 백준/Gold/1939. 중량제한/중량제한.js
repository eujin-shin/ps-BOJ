const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], ...bridges] = input.map((str) => str.split(" ").map(Number));
const [[start, end]] = bridges.splice(-1);

function solution(n, bridges, start, end) {
  const connects = Array.from({ length: n }, () => new Map());
  let max = 0;
  for (let i = 0; i < bridges.length; i++) {
    const prev = connects[bridges[i][0] - 1].get(bridges[i][1]) || 0;
    if (prev < bridges[i][2]) {
      max = max < bridges[i][2] ? bridges[i][2] : max;
      connects[bridges[i][0] - 1].set(bridges[i][1], bridges[i][2]);
      connects[bridges[i][1] - 1].set(bridges[i][0], bridges[i][2]);
    }
  }

  const bfs = (limit) => {
    const visits = Array.from({ length: n }, () => 0);
    visits[start - 1] = 1;

    const queue = [start];
    while (0 < queue.length) {
      const x = queue.shift();
      if (x === end) {
        return true;
      }

      connects[x - 1].forEach((bridge, y) => {
        if (limit <= bridge && visits[y - 1] === 0) {
          queue[queue.length] = y;
          visits[y - 1] = 1;
        }
      });
    }
    return false;
  };

  let l = 1;
  let r = max;
  let answer = 0;
  while (l <= r) {
    const mid = (l + r) % 2 === 0 ? (l + r) / 2 : (l + r - 1) / 2;
    if (bfs(mid)) {
      l = mid + 1;
      answer = mid;
    } else {
      r = mid - 1;
    }
  }

  return answer;
}

console.log(solution(n, bridges, start, end));
