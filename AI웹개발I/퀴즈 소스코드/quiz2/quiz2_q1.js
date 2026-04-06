const v1 = 1
let v2 = 1;
let v3 = 1;
{
    const v1 = 2;
    let v2 = 2;
    v3 = 2;
}
console.log(v1 + v2 + v3);