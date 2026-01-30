const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [n] = input[0].split(" ").map(Number);
const count = new Map();
input.slice(1, 1 + n).forEach((str) => {
  const answer = str.split(" ");
  for (let x = 0; x < 8; x++) {
    const arr = x.toString(2).padStart(3, "0").split("");
    const key = answer
      .map((word, idx) => (arr[idx] === "1" ? word : "-"))
      .join(" ");
    count.set(key, (count.get(key) || 0) + 1);
  }
});
input.slice(1 + n).forEach((str) => console.log(count.get(str) || 0));
