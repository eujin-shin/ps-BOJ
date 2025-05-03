const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [n, m] = firstLine.split(" ").map(Number);
const songs = input.splice(0, n).map((str) => {
  const [, name, ...start] = str.split(" ");
  return { name, start };
});
const melodies = input.map((str) => str.split(" "));

function solution(n, m, songs, melodies) {
  const findSong = (melodies) => {
    let count = 0;
    let targetName = "";
    for (let i = 0; i < n; i++) {
      if (melodies.every((v, idx) => v === songs[i].start[idx])) {
        targetName = songs[i].name;
        count++;
      }
    }
    return count === 1 ? targetName : count === 0 ? "!" : "?";
  };

  for (let i = 0; i < m; i++) {
    console.log(findSong(melodies[i]));
  }
}

solution(n, m, songs, melodies);
