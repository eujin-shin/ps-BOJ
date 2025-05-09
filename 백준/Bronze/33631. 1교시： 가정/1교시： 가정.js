const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [ingredient, need, , ...queries] = input.map((str) =>
  str.split(" ").map(Number)
);

function solution(ingredient, need, queries) {
  let cookies = 0;
  const makeCookies = (k) => {
    if (ingredient.every((v, idx) => need[idx] * k <= v)) {
      for (let i = 0; i < 4; i++) {
        ingredient[i] -= need[i] * k;
      }
      return (cookies += k);
    }
    return "Hello, siumii";
  };
  queries.forEach(([x, i]) => {
    if (x === 1) {
      console.log(makeCookies(i));
    } else {
      ingredient[x - 2] += i;
      console.log(ingredient[x - 2]);
    }
  });
}

solution(ingredient, need, queries);
