var a;
function func() {
    var v1 = a === null ? 1 : 3;
    var v2 = a == null ? 2 : 4;
    var v3 = a === undefined ? 3 : 5;
    return v1 + v2 + v3;
};
console.log(func());