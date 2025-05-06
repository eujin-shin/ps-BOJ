const fs = require("fs");
const [, input] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

function solution(input) {
  const count = [...input].reduce((count, letter, idx) => {
    if (4 < count) {
      return count;
    } else if (
      Math.abs(letter.charCodeAt(0) - input.charCodeAt(idx - 1)) === 1
    ) {
      return count + 1;
    } else {
      return 1;
    }
  }, 1);
  return 4 < count ? "YES" : "NO";
}

console.log(solution(input));
