const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.slice(0, -1).forEach((v) => {
  console.log(BigInt(v) % 42n === 0n ? "PREMIADO" : "TENTE NOVAMENTE");
});
