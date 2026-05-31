const arr = [3, 8, 2, 15, 7];
let max = arr[0];
for (let i = 1; i < arr.length; i++) {
 if (arr[i] > max) max = arr[i];
}
console.log(max);