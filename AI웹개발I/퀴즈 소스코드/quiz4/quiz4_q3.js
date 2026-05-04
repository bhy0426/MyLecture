var func = function() { return this; }
var obj = {
    v: 3,
    o: {
        v: 5,
        m: func
    },
    m1: () => func(),
    m2: () => this
}

var result = 0;
result += func() == obj.o.m() ? 1 : 0;
result += obj.v == func.bind(obj.o).call(obj).v ? 1 : 0;
result += obj.v == obj.m1().v ? 1 : 0;
result += obj.m2() == obj ? 1 : (obj.m2() == global ? 2 : 0);
console.log(result);