const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[, arrive], ...busList] = input.map((str) => str.split(" ").map(Number));

function solution(arrive, busList) {
  const ans = busList.reduce((ans, [start, interval, limit]) => {
    const count = Math.ceil(Math.max(arrive - start, 0) / interval);
    const wait = count < limit ? start + count * interval - arrive : null;
    return ans === null || (wait !== null && wait < ans) ? wait : ans;
  }, null);
  return ans === null ? -1 : ans;
}

console.log(solution(arrive, busList));
