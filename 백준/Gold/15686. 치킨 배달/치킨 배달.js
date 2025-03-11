const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[, m], ...city] = input.map((str) => str.split(" ").map(Number));

function solution(m, city) {
  const houses = [];
  const chicken = [];
  city.forEach((row, y) =>
    row.forEach((v, x) => {
      if (v === 1) houses.push([x, y]);
      else if (v === 2) chicken.push([x, y]);
    })
  );

  let min = Infinity;
  const backtrack = (r, costs, k) => {
    if (r === m) {
      const sum = costs.reduce((sum, val) => sum + val, 0);
      min = sum < min ? sum : min;
      return;
    }
    for (let i = k; i < chicken.length - (m - r - 1); i++) {
      const [xc, yc] = chicken[i];
      const newCosts = houses.map(([xh, yh], idx) => {
        const distance =
          (xh < xc ? xc - xh : xh - xc) + (yh < yc ? yc - yh : yh - yc);
        return distance < costs[idx] ? distance : costs[idx];
      });
      backtrack(r + 1, newCosts, i + 1);
    }
  };

  backtrack(
    0,
    Array.from({ length: houses.length }, () => Infinity),
    0
  );
  return min;
}

console.log(solution(m, city));
