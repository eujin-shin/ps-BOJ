const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const PLU = "plu";
input.slice(1).forEach((str) => {
  console.log(
    str
      .toLowerCase()
      .split("")
      .reduce(
        ([count, cur], letter) =>
          letter === PLU[cur]
            ? [count + (cur === 2 ? 1 : 0), (cur + 1) % 3]
            : [count, cur],
        [0, 0]
      )[0]
  );
});
