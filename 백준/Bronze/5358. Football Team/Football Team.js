const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.forEach((str) =>
  console.log(
    [...str]
      .map((char) => {
        if (char === "i") return "e";
        if (char === "e") return "i";
        if (char === "I") return "E";
        if (char === "E") return "I";
        return char;
      })
      .join("")
  )
);
