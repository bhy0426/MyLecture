function f1(x) { return x / 2; }
var f2 = function(x) { return x / 2; }
console.log(f1(2) + f2(4));
f1 = function(x) { return x * 2; }
function f2(x) { return x * 2; }