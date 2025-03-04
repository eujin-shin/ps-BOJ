const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, k], ...houses] = input.map((str) => str.split(" ").map(Number));

function solution(n, k, houses) {
  const getDistance = ([xa, ya], [xb, yb]) =>
    (xa < xb ? xb - xa : xa - xb) + (ya < yb ? yb - ya : ya - yb);
  const distances = houses.map((a) => houses.map((b) => getDistance(a, b)));

  const selectedHouses = [];
  let answer = Infinity;

  const check = () => {
    return distances.reduce((max, distance) => {
      const min = Math.min(...selectedHouses.map((i) => distance[i]));
      return max < min ? min : max;
    }, 0);
  };

  const select = (r, x) => {
    if (r === k) {
      const temp = check();
      answer = answer < temp ? answer : temp;
      return;
    }
    for (let i = x + 1; i < n; i++) {
      selectedHouses[r] = i;
      select(r + 1, i);
    }
  };

  select(0, -1);

  return answer;
}

console.log(solution(n, k, houses));
