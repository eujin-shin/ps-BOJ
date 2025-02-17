const fs = require("fs");
const input = fs.readFileSync("/dev/stdin").toString().trim().split("\n");

const [[n, m, k], ...lines] = input.map((str) => str.split(" ").map(Number));
const arr = lines.splice(0, n);
const trees = lines.splice(0, m);

function solution(n, k, add, init) {
  const map = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => 5)
  );
  function Tree(x, y, age) {
    this.x = x;
    this.y = y;
    this.age = age;
  }

  Tree.prototype.getNutrient = function () {
    if (map[this.y][this.x] < this.age) {
      return false;
    }
    map[this.y][this.x] -= this.age;
    this.age++;
    return true;
  };

  Tree.prototype.makeNewTree = function () {
    if (this.age % 5 !== 0) {
      return [];
    }
    const newTrees = [];
    for (let i = -1; i < 2; i++) {
      for (let j = -1; j < 2; j++) {
        if (
          (i !== 0 || j !== 0) &&
          this.x + j < n &&
          this.x + j >= 0 &&
          this.y + i < n &&
          this.y + i >= 0
        ) {
          newTrees.push(new Tree(this.x + j, this.y + i, 1));
        }
      }
    }
    return newTrees;
  };

  let trees = init.map(([x, y, z]) => new Tree(y - 1, x - 1, z));

  for (let i = 0; i < k; i++) {
    const deadTrees = [];
    trees = trees.filter((tree) => {
      const result = tree.getNutrient();
      if (!result) {
        deadTrees.push(tree);
      }
      return result;
    });

    deadTrees.forEach((tree) => {
      map[tree.y][tree.x] += Math.floor(tree.age / 2);
    });

    const newTrees = [];
    trees.forEach((tree) => {
      newTrees.push(...tree.makeNewTree());
    });
    trees.unshift(...newTrees);

    add.forEach((row, y) => row.forEach((v, x) => (map[y][x] += v)));
  }

  return trees;
}

console.log(solution(n, k, arr, trees).length);
