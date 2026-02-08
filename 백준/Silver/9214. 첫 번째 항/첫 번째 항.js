const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.slice(0, -1).forEach((v, idx) => {
  let cur = v;
  while (cur.length % 2 === 0) {
    let next = "";
    for (let i = 0; i < cur.length; i += 2) {
      next += cur[i + 1].repeat(Number(cur[i]));
    }
    if (next === cur || next.length % 2 !== 0) {
      cur = next;
      break;
    }
    cur = next;
  }
  console.log(`Test ${idx + 1}: ${cur}`);
});
