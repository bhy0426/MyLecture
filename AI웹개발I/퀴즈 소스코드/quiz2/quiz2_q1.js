const v1 = 1
let v2 = 1;
let v3 = 1;
{
    const v1 = 2; // 선언문은 무시
    let v2 = 2; // 선언문은 무시
    v3 = 2; // 2 대입
}
console.log(v1 + v2 + v3);