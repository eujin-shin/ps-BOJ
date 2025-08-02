const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], bridges, [a, b]] = input.map((str) => str.split(" ").map(Number));
function solution(n, a, b, bridges) {
  const history = Array.from({ length: n }, () => Infinity);
  let queue = [a];
  let count = 0;
  history[a - 1] = count;
  while (history[b - 1] === Infinity && queue.length > 0) {
    const nextVisit = [];
    count++;
    for (let i = 0; i < queue.length; i++) {
      const x = queue[i];
      const distance = bridges[x - 1];
      for (let temp = x - distance; 0 < temp; temp -= distance) {
        if (count < history[temp - 1]) {
          nextVisit.push(temp);
          history[temp - 1] = count;
        }
      }
      for (let temp = x + distance; temp <= n; temp += distance) {
        if (count < history[temp - 1]) {
          nextVisit.push(temp);
          history[temp - 1] = count;
        }
      }
      if (history[b - 1] !== Infinity) break;
    }
    queue = nextVisit;
  }
  return history[b - 1] === Infinity ? -1 : count;
}
console.log(solution(n, a, b, bridges));
