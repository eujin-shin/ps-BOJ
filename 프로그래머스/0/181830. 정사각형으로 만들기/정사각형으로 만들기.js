function solution(arr) {
    const height = arr.length;
    const width = arr[0].length;
    return height > width ? arr.map((cur) => cur.concat(Array(height - width).fill(0))) : arr.concat(Array.from({length: width - height}, () => Array(width).fill(0)));
}