const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim();
console.log(
  [...input].reduce(
    ([sum, prev, count], letter) => {
      const cur = letter.charCodeAt(0);
      const isContinue = prev < cur;
      const newCount = isContinue ? count + 1 : 1;
      return [sum + newCount, cur, newCount];
    },
    [0, 0, 0]
  )[0]
);
