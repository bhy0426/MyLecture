const arr = [1, 2, 3];
const r = arr.map(e => e - 1).reduce((acc, e, i) => acc += e * i);
console.log(r);