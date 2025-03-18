const fs = require("fs");
const [firstLine, ...input] = fs
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

const [amount, companies] = firstLine.split(" ").map(Number);
const profits = input.map((str) => str.split(" ").splice(1).map(Number));

function solution(amount, companies, profits) {
  let prev = Array.from({ length: amount }, () => 0);
  let history = Array.from({ length: amount }, () => new Array());

  for (let c = 0; c < companies; c++) {
    const row = [];
    const usedPrice = [];
    for (let a = 1; a <= amount; a++) {
      let max = prev[a - 1];
      let maxIdx = a - 1;
      for (let price = 1; price <= a; price++) {
        const temp = profits[price - 1][c] + (prev[a - price - 1] || 0);
        if (max < temp) {
          max = temp;
          maxIdx = a - price - 1;
        }
      }
      row[row.length] = max;
      usedPrice[usedPrice.length] = [
        ...(history[maxIdx] || Array.from({ length: c }, () => 0)),
        a - maxIdx - 1,
      ];
    }
    prev = row;
    history = usedPrice;
  }

  return [prev[amount - 1], history[amount - 1].join(" ")];
}

const [answer, price] = solution(amount, companies, profits);
console.log(answer);
console.log(price);
