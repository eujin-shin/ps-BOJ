const fs = require("fs");
const [, ...words] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

function solution(words) {
  const letterList = [
    "a",
    "b",
    "k",
    "d",
    "e",
    "g",
    "h",
    "i",
    "l",
    "m",
    "n",
    "ng",
    "o",
    "p",
    "r",
    "s",
    "t",
    "u",
    "w",
    "y",
  ];
  const getLetter = (word, index) =>
    word[index] === "n" && word[index + 1] === "g" ? "ng" : word[index];
  const compareWords = (a, b) => {
    const index = {
      a: 0,
      b: 0,
    };
    let result = 0;
    while (result === 0) {
      const x = getLetter(a, index.a);
      const y = getLetter(b, index.b);
      index.a += x?.length;
      index.b += y?.length;
      result = letterList.indexOf(x) - letterList.indexOf(y);
    }
    return result;
  };
  return words.sort(compareWords);
}

solution(words).forEach((v) => console.log(v));
