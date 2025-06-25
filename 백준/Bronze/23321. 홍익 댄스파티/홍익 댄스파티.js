const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const pictures = [".omln", "owln.", "..oLn"];
const answer = Array.from({ length: 5 }, () =>
  Array.from({ length: input[0].length }, () => "")
);
for (let x = 0; x < input[0].length; x++) {
  const idx = input[0][x] === "o" ? 0 : input[1][x] === "o" ? 1 : 2;
  for (let y = 0; y < 5; y++) {
    answer[y][x] = pictures[idx][y];
  }
}
for (let i = 0; i < 5; i++) console.log(answer[i].join(""));
