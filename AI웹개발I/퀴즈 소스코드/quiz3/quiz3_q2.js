var a = 1;
global.a = 3;

const obj = {
    a: 5,
    f: function() {
        return this.a;
    }
};

let f = obj.f;
console.log(f()); // 함수로서 호출 a=3