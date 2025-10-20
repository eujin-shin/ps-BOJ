const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("");
console.log(
  input.reduce(
    ([sum, idx], v) => {
      if (v === v.toUpperCase() && idx % 4 !== 0)
        return [sum + (4 - (idx % 4)), idx + (5 - (idx % 4))];
      return [sum, idx + 1];
    },
    [0, 0]
  )[0]
);
