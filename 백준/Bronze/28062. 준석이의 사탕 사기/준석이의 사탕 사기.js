const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [, candy] = input.map((str) => str.split(" ").map(Number));

function solution(candy) {
  const [sum, minOdd] = candy.reduce(
    ([sum, minOdd], v) => [sum + v, v < minOdd && v % 2 === 1 ? v : minOdd],
    [0, Infinity]
  );
  return sum % 2 === 0 ? sum : minOdd === Infinity ? 0 : sum - minOdd;
}

console.log(solution(candy));
