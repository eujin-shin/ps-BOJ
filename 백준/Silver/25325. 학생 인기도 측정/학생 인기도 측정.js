const fs = require("fs");
const [, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [names, ...favorites] = input.map((str) => str.split(" "));

function solution(names, favorites) {
  const nameMap = new Map(names.map((v) => [v, 0]));
  favorites.forEach((list) => {
    list.forEach((name) => nameMap.set(name, (nameMap.get(name) || 0) + 1));
  });
  return [...nameMap].sort((a, b) => b[1] - a[1] || a[0].localeCompare(b[0]));
}

const result = solution(names, favorites);
result.forEach((v) => console.log(v.join(" ")));
