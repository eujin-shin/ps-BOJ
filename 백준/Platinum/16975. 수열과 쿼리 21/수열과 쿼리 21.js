const fs = require("fs");
const inputs = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n], arr, , ...queries] = inputs.map((str) =>
  str.split(" ").map(Number)
);

function solution(n, arr, queries) {
  "use strict";
  const tree = Array.from({ length: arr.length * 4 }, () => 0);

  const add = (start, end, k) => {
    const search = (left, right, node) => {
      if (end < left || right < start) {
        return;
      }
      if (start <= left && right <= end) {
        tree[node] += k;
      } else if (left < right) {
        const mid =
          (left + right) % 2 === 0
            ? (left + right) / 2
            : (left + right - 1) / 2;
        return (
          search(left, mid, node * 2) || search(mid + 1, right, node * 2 + 1)
        );
      }
    };
    search(1, n, 1);
  };

  const print = (x) => {
    const search = (left, right, node, sum) => {
      const mid =
        (left + right) % 2 === 0 ? (left + right) / 2 : (left + right - 1) / 2;
      const update = sum + tree[node];
      if (left === right) {
        return update;
      }
      return x <= mid
        ? search(left, mid, node * 2, update)
        : search(mid + 1, right, node * 2 + 1, update);
    };
    console.log(search(1, n, 1, 0) + arr[x - 1]);
  };

  const func = {
    1: add,
    2: print,
  };

  queries.forEach(([id, ...param]) => {
    func[id](...param);
  });
}

solution(n, arr, queries);
