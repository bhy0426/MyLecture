var v1 = 4;
var v2 = v1;
var o1 = { k: v2};
var o2 = o1;
o1.k = 1;
v2 = o2.k
console.log(v1 - v2 - o1.k - o2.k);