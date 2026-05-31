const arr = [1, 3, 5, 8, 10, 12];
let count =0;
const result =arr.findIndex(x => {
    if (x % 2 == 0) count++;
    return count == 2;
});
console.log(result);