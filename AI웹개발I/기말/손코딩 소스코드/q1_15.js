const a = [1, 2, 3, 4];
const b = [3, 4, 5, 6];
const setA = new Set(a);
const setB = new Set(b);
const result = setA.intersection(setB);
console.log([...result]);