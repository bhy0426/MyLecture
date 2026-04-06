const a = 1;
global.a = 2;
module.exports.a = 3;

const obj = {
    a: 4,
    f: () => this.a,
    g: () => a,
    h: function() { return this.a; }
};

const f = obj.f;
console.log(f() + obj.g() * 2 + obj.h() * 4);