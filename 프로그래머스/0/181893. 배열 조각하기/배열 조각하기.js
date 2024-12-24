function solution(arr, query) {
    query.forEach((q, index) => {
        if(index % 2 === 0) {
            arr.splice(q + 1);
        } else {
            arr.splice(0, q);
        }
    })
    return arr;
}