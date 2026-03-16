const fs = require("fs");
const [input, s] = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [p, w] = input.split(" ").map(Number);
const keyboard = ["ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"];
const buttons = new Map();
const counts = new Map();
keyboard.forEach((letters, button) =>
  letters.split("").forEach((letter, count) => {
    counts.set(letter, count + 1);
    buttons.set(letter, button);
  })
);
const [sum, wait] = s.split("").reduce(
  ([sum, wait, prev], v) => {
    const button = v === " " ? -1 : buttons.get(v);
    const count = v === " " ? 1 : counts.get(v);
    return [
      sum + count,
      wait + (prev === button && button >= 0 ? 1 : 0),
      button,
    ];
  },
  [0, 0]
);
console.log(sum * p + wait * w);
