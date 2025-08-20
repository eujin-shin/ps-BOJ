const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim("\n").split("\n");
input.forEach((str) => {
  if (str !== "0")
    console.log(
      str
        .split(" ")
        .map((v, index, array) =>
          index === 0 || v === array[index - 1] ? undefined : v
        )
        .filter((v) => v !== undefined)
        .join(" "),
      "$"
    );
});
