const fs = require("fs");
const [firstLine, letter] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const n = Number(firstLine);

function solution(n, letter) {
  const letterList = Array.from(letter);

  const compare = (str, list) => {
    return list.reduce((sum, cur, idx) => sum + (cur !== str.at(idx)), 0);
  };

  const getAnswer = (word) => {
    const match = {
      A: "000000",
      B: "001111",
      C: "010011",
      D: "011100",
      E: "100110",
      F: "101001",
      G: "110101",
      H: "111010",
    };

    for (key in match) {
      if (compare(match[key], word) < 2) {
        return key;
      }
    }
    return undefined;
  };

  let result = "";
  for (let i = 0; i < n; i++) {
    const word = letterList.splice(0, 6);
    const answer = getAnswer(word);
    if (!answer) {
      return i + 1;
    }
    result += answer;
  }
  return result;
}

console.log(solution(n, letter));
