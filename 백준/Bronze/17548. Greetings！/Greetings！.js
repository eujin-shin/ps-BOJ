const fs = require("fs");
const greeting = fs.readFileSync("/dev/stdin").toString().trim();
console.log("h" + "e".repeat((greeting.length - 2) * 2) + "y");
