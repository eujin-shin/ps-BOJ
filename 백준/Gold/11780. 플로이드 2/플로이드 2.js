const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], , ...bus] = input.map((str) => str.split(" ").map(Number));

function solution(n, bus) {
  const distance = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => Infinity)
  );
  const route = Array.from({ length: n }, () => Array.from({ length: n }));

  bus.forEach(([start, end, price]) => {
    if (price < distance[start - 1][end - 1]) {
      distance[start - 1][end - 1] = price;
      route[start - 1][end - 1] = [start, end];
    }
  });

  const update = (via) => {
    for (let x = 0; x < n; x++) {
      if (x === via) continue;
      for (let y = 0; y < n; y++) {
        if (y === via || x === y) continue;
        const cur = distance[x][y];
        const temp = distance[x][via] + distance[via][y];
        if (temp < cur) {
          distance[x][y] = temp;
          route[x][y] = [
            ...(route[x][via] ? route[x][via].slice(0, -1) : [x]),
            via + 1,
            ...(route[via][y] ? route[via][y].slice(1) : [y]),
          ];
        }
      }
    }
  };

  for (let i = 0; i < n; i++) {
    update(i);
  }

  return { distance, route };
}

const { distance, route } = solution(n, bus);

distance.forEach((row) => {
  const str = row.map((v) => (v === Infinity ? "0" : `${v}`)).join(" ");
  console.log(str);
});

route.forEach((row) => {
  row.forEach((cell) => {
    console.log(cell ? `${cell.length} ${cell.join(" ")}` : "0");
  });
});
