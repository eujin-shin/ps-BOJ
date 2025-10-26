const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");
input.forEach((str) => {
  const [x, customers] = str.split(" ");
  const n = Number(x);
  if (n !== 0) {
    const salons = new Set();
    const wait = new Set();
    const count = customers.split("").reduce((sum, customer) => {
      if (salons.has(customer)) {
        salons.delete(customer);
      } else if (wait.has(customer)) {
        wait.delete(customer);
        return sum + 1;
      } else if (salons.size < n) {
        salons.add(customer);
      } else {
        wait.add(customer);
      }
      return sum;
    }, 0);
    console.log(
      count === 0
        ? "All customers tanned successfully."
        : `${count} customer(s) walked away.`
    );
  }
});
