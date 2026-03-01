const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const m = 5000000;
input.slice(1).reduce((arr, cur) => {
  const l = Number(cur);
  if (l !== 0) return arr.concat([l]);
  const prices = arr.sort((a, b) => b - a);
  const answer = prices.reduce((sum, v, idx) => {
    let temp = v;
    for (let i = 0; i < idx && sum >= 0 && sum + temp * 2 <= m; i++) temp *= v;
    return sum < 0 || sum + temp > m ? -1 : sum + temp * 2;
  }, 0);
  console.log(answer < 0 ? "Too expensive" : answer);
  return [];
}, []);
