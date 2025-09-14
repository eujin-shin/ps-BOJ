const fs = require("fs");
const [, a, b] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const arr = Array.from({ length: 26 }, () => 0);
const getIndex = (letter) => letter.charCodeAt(0) - "a".charCodeAt(0);
[...a].forEach((letter) => arr[getIndex(letter)]++);
let count = 0;
[...b].forEach((letter) => {
  const index = getIndex(letter);
  if (arr[index] > 0) arr[index]--;
  else count++;
});
console.log(count);
