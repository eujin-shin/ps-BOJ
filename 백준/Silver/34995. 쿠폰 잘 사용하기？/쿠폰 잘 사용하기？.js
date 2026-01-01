const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
const [[x, coupon], [price]] = input.map((str) => str.split(" "));
const fillCoupon = coupon.split("").map((v) => (v === "?" ? "9" : v));
const n = Number(x);
console.log(
  n < price.length ||
    (n === price.length &&
      fillCoupon.reduce((prev, val, index) => {
        if (prev !== 0) return prev;
        const a = Number(val);
        const b = Number(price[index]);
        return a === b ? 0 : a > b ? 1 : -1;
      }, 0) < 0)
    ? -1
    : fillCoupon.join("")
);
