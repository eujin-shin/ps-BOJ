const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
let i = 0;
const t = Number(input[i++]);
for (let x = 0; x < t; x++) {
  const k = Number(input[i++]);
  const students = new Set(input[i++].split(" ").map(Number));
  const n = Number(input[i++]);
  const answer = {
    min: Infinity,
    win: 0,
    count: 0,
  };
  for (let y = 0; y < n; y++) {
    const [id, h, m] = input[i++].split(" ").map(Number);
    if ((h < 0 && m < 0) || !students.has(id)) continue;
    const record = h * 60 + m;
    if (record < answer.min) {
      answer.win = id;
      answer.min = record;
    }
    if (record <= 6 * 60) {
      answer.count++;
    }
  }
  console.log(answer.win, answer.count);
}
