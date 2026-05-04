global.a = 1;
const obj = {
    a: 2
}

function f1(a, b, c) {
    return this.a + b + c;
}

const f2 = f1.bind(obj, 3, 5, 7); // 이해 못함
console.log(f2(4, 6, 8));