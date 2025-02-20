const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m], ...vertex] = input.map((str) => str.split(" ").map(Number));

function solution(n, vertex) {
  const answer = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => -1)
  );
  const dist = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => Infinity)
  );

  vertex.forEach(([x, y, cost]) => {
    if (dist[x - 1][y - 1] > cost) {
      dist[x - 1][y - 1] = dist[y - 1][x - 1] = cost;
      answer[x - 1][y - 1] = y;
      answer[y - 1][x - 1] = x;
    }
  });

  for (let via = 1; via <= n; via++) {
    for (let x = 1; x <= n; x++) {
      if (x === via) {
        continue;
      }
      for (let y = 1; y <= n; y++) {
        if (y === via || x === y) {
          continue;
        }
        const temp = dist[x - 1][via - 1] + dist[via - 1][y - 1];
        if (temp < dist[x - 1][y - 1]) {
          dist[x - 1][y - 1] = dist[y - 1][x - 1] = temp;
          answer[x - 1][y - 1] = answer[x - 1][via - 1];
          answer[y - 1][x - 1] = answer[y - 1][via - 1];
        }
      }
    }
  }

  return answer;
}

const answer = solution(n, vertex);
answer
  .map((arr) => arr.join(" ").replaceAll("-1", "-"))
  .forEach((str) => console.log(str));
