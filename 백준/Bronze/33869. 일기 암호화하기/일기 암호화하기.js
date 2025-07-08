const fs = require("fs");
const [password, target] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");
function solution(password, target) {
  const key = [
    ...new Set([...password, ..."ABCDEFGHIJKLMNOPQRSTUVWXYZ".split("")]),
  ];
  const a = "A".charCodeAt(0);
  return [...target].map((letter) => key[letter.charCodeAt(0) - a]).join("");
}
console.log(solution(password, target));
