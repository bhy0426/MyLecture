function func(v) { return () => v++; }
let f1 = func(2);
let f2 = func(2);
console.log(f1() + f1() + f2());