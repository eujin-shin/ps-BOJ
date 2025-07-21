const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[n], ...play] = input.map((str) => str.split(" ").map(Number));
const scores = Array.from({ length: n }, () => 0);
play.forEach(([a, b, c, d]) => {
  scores[a - 1] += c > d ? 3 : c === d ? 1 : 0;
  scores[b - 1] += d > c ? 3 : c === d ? 1 : 0;
});
const ranks = Array.from({ length: n }, () => 0);
scores
  .map((v, idx) => [v, idx])
  .sort((a, b) => b[0] - a[0])
  .reduce(
    ([prev, rank], [v, team], idx) => {
      const newRank = prev === v ? rank : idx + 1;
      ranks[team] = newRank;
      return [v, newRank];
    },
    [0, 0]
  );
ranks.forEach((v) => console.log(v));
