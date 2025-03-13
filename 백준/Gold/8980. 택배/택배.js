const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, c], , ...send] = input.map((str) => str.split(" ").map(Number));

function solution(n, c, send) {
  const towns = Array.from({ length: n }, () => new Array());
  send.forEach(([x, y, count]) => towns[x - 1].push([y, count]));

  const truck = {};
  let loaded = 0;
  let lastArrival = 0;
  let sum = 0;
  towns.forEach((list, idx) => {
    if (truck[idx + 1]) {
      loaded -= truck[idx + 1];
      delete truck[idx + 1];
    }

    const beforeAdd = loaded;
    list.forEach(([y, count]) => {
      lastArrival = lastArrival < y ? y : lastArrival;
      truck[y] = (truck[y] || 0) + count;
      loaded += count;
    });

    for (let i = lastArrival; c < loaded; i--) {
      if (truck[i]) {
        const unload = loaded - c < truck[i] ? loaded - c : truck[i];
        loaded -= unload;
        lastArrival = i;

        if (unload === truck[i]) {
          delete truck[i];
        } else {
          truck[i] -= unload;
        }
      }
    }

    sum += loaded - beforeAdd;
  });

  return sum;
}

console.log(solution(n, c, send));
