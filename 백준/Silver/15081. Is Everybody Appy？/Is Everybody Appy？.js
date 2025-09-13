const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const apps = new Set();
console.log(
  input
    .slice(1)
    .map((str) => {
      const [, ...list] = str.split(" ");
      const app = list.find((word) => !apps.has(word));
      apps.add(app);
      return app;
    })
    .join(" ")
);
