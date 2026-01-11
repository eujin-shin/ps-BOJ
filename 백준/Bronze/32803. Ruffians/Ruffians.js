const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...games] = input.map((str) => str.split(" ").map(Number));
let y = 0;
for (let i = 0; i < n; i++) {
  const record = new Map();
  let answer = false;
  for (let a = 0; a < 2 && !answer; a++, y++) {
    for (let x = 0; x < 5 && !answer; x++) {
      const v = games[y][x];
      if (!record.has(v)) record.set(v, [[x, y]]);
      else if (record.get(v).some((coor) => coor[0] !== x && coor[1] !== y))
        answer = true;
      else record.set(v, [...record.get(v), [x, y]]);
    }
  }
  console.log(answer ? "YES" : "NO");
}
