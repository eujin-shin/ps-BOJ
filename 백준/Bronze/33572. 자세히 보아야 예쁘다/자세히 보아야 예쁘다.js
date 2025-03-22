const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[, m], limits] = input.map((str) => str.split(" ").map(Number));

function solution(m, limits) {
  for (let i = 0; i < limits.length && 0 < m; i++) {
    m -= limits[i] - 1;
  }
  return 0 < m ? "OUT" : "DIMI";
}

console.log(solution(m, limits));
