const arr = [1, 2, 3, 4, 5, 6];
const sum = arr.reduce((acc, value) => acc + value, 0);
console.log(sum / arr.length);