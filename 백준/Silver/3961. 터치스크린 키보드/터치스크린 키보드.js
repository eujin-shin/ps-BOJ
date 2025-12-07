const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const keyboard = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
const distances = {};
keyboard.forEach((row, y) =>
  row.split("").forEach((v, x) => {
    for (let distY = y; distY < 3; distY++) {
      for (
        let distX = y === distY ? x : 0;
        distX < keyboard[distY].length;
        distX++
      ) {
        const w = keyboard[distY][distX];
        const dist = Math.abs(distY - y) + Math.abs(distX - x);
        distances[v] = {
          ...distances[v],
          [w]: dist,
        };
        distances[w] = {
          ...distances[w],
          [v]: dist,
        };
      }
    }
  })
);

let line = 1;
while (line < input.length) {
  const [word, n] = input[line++].split(" ");
  const x = Number(n);
  const next = line + x;
  const arr = input
    .slice(line, next)
    .map((dict) => {
      const dist = dict
        .split("")
        .reduce((sum, letter, idx) => sum + distances[letter][word[idx]], 0);
      return [dict, dist];
    })
    .sort((a, b) => (a[1] - b[1] === 0 ? (a[0] < b[0] ? -1 : 1) : a[1] - b[1]))
    .map((arr) => arr.join(" "))
    .join("\n");
  console.log(arr);
  line = next;
}
