const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [, ...cards] = input.map((str) => str.split(" "));

function solution(cards) {
  const fruits = ["STRAWBERRY", "BANANA", "LIME", "PLUM"];
  const counts = new Map();
  for (let i = 0; i < cards.length; i++) {
    const [fruit, number] = cards[i];
    counts.set(fruit, (counts.get(fruit) || 0) + Number(number));
  }
  return fruits.some((v) => counts.get(v) === 5) ? "YES" : "NO";
}

console.log(solution(cards));
