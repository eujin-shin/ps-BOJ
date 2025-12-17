const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
console.log(
  input
    .slice(1)
    .map((word) => {
      const n = word.length;
      for (let i = 0; i < n; i++) {
        let overlap = true;
        for (let x = 0; i + x < n && overlap; x++) {
          if (word[i + x] !== word[n - 1 - x]) overlap = false;
        }
        if (overlap) {
          return word + word.slice(0, i).split("").reverse().join("");
        }
      }
    })
    .join("\n")
);
