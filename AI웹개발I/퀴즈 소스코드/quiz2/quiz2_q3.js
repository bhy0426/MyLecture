let v1 = 1;
let v2 = v1;
let o1 = { v1 } // 키, 값이 모두 v1
let o2 = o1;
o1.v1 = 2;
v1 = 3;
console.log(v1 + v2 + o1.v1 + o2.v1);