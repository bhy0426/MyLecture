const arr = [1, 2, 3, 4, 5, 6];
const result = [];
for (const num of arr) {
 if (num % 2 === 0) result.push(num);
}
console.log(result);