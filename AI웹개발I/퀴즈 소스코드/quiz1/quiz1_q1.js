var v1 = 1;
let v2 = 2;
var v3 = v1;
let v4 = v2;
{
    var v1 = 3;
    let v2 = 4;
    var v3 = v1;
    let v4 = v2;
}
console.log(v1 + v2 + v3 + v4);