const fs = require("fs");
const [firstLine, secondLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);
const count = secondLine.split(" ").map(Number);
const adjacent = input.map((str) => str.split(" ").map(Number).splice(1));

function solution(n, count, adjacent) {
  let answer = Infinity;

  const search = (selected, target, needToVisit) => {
    if (needToVisit < 1) {
      return -1;
    }

    const start = selected.indexOf(target);
    const queue = [start + 1];
    let people = count[start];
    selected[start] = -1;
    needToVisit--;
    while (queue.length > 0 && needToVisit > 0) {
      const cur = queue.shift();
      adjacent[cur - 1].forEach((v) => {
        if (selected[v - 1] === target) {
          needToVisit--;
          selected[v - 1] = -1;
          people += count[v - 1];
          queue.push(v);
        }
      });
    }
    return needToVisit === 0 ? people : -1;
  };

  const backTrack = (r, selected, x) => {
    if (r === n) {
      const result = [...selected];
      const a = search(result, 1, x);
      const b = search(result, 0, n - x);
      if (a >= 0 && b >= 0) {
        const diff = a < b ? b - a : a - b;
        answer = diff < answer ? diff : answer;
      }
    } else {
      backTrack(r + 1, selected, x);
      selected[r] = 1;
      backTrack(r + 1, selected, x + 1);
      selected[r] = 0;
    }
  };

  backTrack(
    1,
    Array.from({ length: n }, () => 0),
    0
  );

  return answer === Infinity ? -1 : answer;
}

console.log(solution(n, count, adjacent));
