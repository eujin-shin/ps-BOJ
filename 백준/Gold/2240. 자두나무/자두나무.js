const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [, limit] = firstLine.split(" ").map(Number);
const positions = input.map(Number);

function solution(limit, positions) {
  let prev = [[0], []];
  let answer = 0;

  const setList = (x, y, newFruit) => {
    const list = [];
    for (let i = 0; i <= limit; i++) {
      const fromSame = prev[x - 1][i] ?? -1;
      const fromOpposite = prev[y - 1][i - 1] ?? -1;
      if (fromSame < 0 && fromOpposite < 0) {
        list[list.length] = -1;
      } else {
        const max = fromSame < fromOpposite ? fromOpposite : fromSame;
        list[list.length] = max + newFruit;
        answer = answer < max + newFruit ? max + newFruit : answer;
      }
    }
    return list;
  };

  positions.forEach((x) => {
    prev = [setList(1, 2, x === 1 ? 1 : 0), setList(2, 1, x === 2 ? 1 : 0)];
  });
  return answer;
}

console.log(solution(limit, positions));
