const obj1 = { a: 1 };
const obj2 = { a: 5 };
global.a = 2;
module.exports.a = 3;

const f1 = (a, b, c) => this.a + b + c;
const f2 = f1.bind(obj1, 5, 6);
console.log(f2.apply(obj2, [7, 8, 9]));