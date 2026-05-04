const arr = [1, 2, 3];
let sum = 0;
for(let i = 0; i < arr.length; i++)
    setTimeout(() => sum += arr[i], 1000);
console.log(sum);