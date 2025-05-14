const fs = require("fs");
const words = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(word) {
  const mirrored = {
    b: "d",
    d: "b",
    p: "q",
    q: "p",
    i: "i",
    o: "o",
    v: "v",
    w: "w",
    x: "x",
  };

  const arr = [...word].reverse();
  return arr.every((v) => mirrored[v])
    ? arr.map((v) => mirrored[v]).join("")
    : "INVALID";
}

while (words[0] !== "#") {
  console.log(solution(words.shift()));
}
