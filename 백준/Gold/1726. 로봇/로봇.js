const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[m, n], ...field] = input.map((str) => str.split(" ").map(Number));
const [s, e] = field.splice(-2);

function solution(m, n, s, e, field) {
  class Position {
    constructor(y, x, dir) {
      this.y = y;
      this.x = x;
      this.dir = dir;
    }

    isSame(compare) {
      return (
        this.y === compare.y && this.x === compare.x && this.dir === compare.dir
      );
    }

    static isAble(y, x) {
      return 0 < y && y <= m && 0 < x && x <= n;
    }
  }
  const start = new Position(...s);
  const end = new Position(...e);

  const visits = Array.from({ length: m }, () =>
    Array.from({ length: n }, () => Array.from({ length: 4 }, () => 0))
  );
  const moves = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];
  const search = new Map();
  search.set(0, [start]);
  let count = 0;
  let curSearch = search.get(count);

  const addSearch = (y, x, dir, count) => {
    if (visits[y - 1][x - 1][dir - 1] !== 0) {
      return;
    }
    const nextPos = new Position(y, x, dir);
    search.set(
      count,
      search.has(count) ? [...search.get(count), nextPos] : [nextPos]
    );
    visits[y - 1][x - 1][dir - 1] = count;
  };

  while (0 <= search.size) {
    if (curSearch.length === 0) {
      curSearch = search.get(++count);
    }
    const curPos = curSearch.shift();
    if (end.isSame(curPos)) {
      break;
    }

    const { y, x, dir } = curPos;
    if (visits[y - 1][x - 1][dir - 1] !== count) {
      continue;
    }
    let tempY = y;
    let tempX = x;
    for (let i = 1; i <= 3; i++) {
      tempY += moves[dir - 1][0];
      tempX += moves[dir - 1][1];
      if (!Position.isAble(tempY, tempX) || field[tempY - 1][tempX - 1] !== 0) {
        break;
      }
      addSearch(tempY, tempX, dir, count + 1);
    }

    for (let i = 1; i <= 4; i++) {
      if (i === dir) {
        continue;
      } else if ((i - 2.5) * (dir - 2.5) > 0) {
        addSearch(y, x, i, count + 2);
      } else {
        addSearch(y, x, i, count + 1);
      }
    }
  }

  return count;
}

console.log(solution(m, n, s, e, field));
