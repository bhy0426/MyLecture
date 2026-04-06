# ES5 vs ES6+

- ES6(ECMAScript 2015)


## strict mode

- 자바스크립트 언어의 문법을 보다 엄격히 적용하여 오류를 발생시킬 가능성이 높거나 자바스크립트 엔진의 최적화 작업에 문제를 일으킬 수 있는 코드에 대해 명시적인 에러를 발생시키는 모드

```
function f() {
    // implicit global (암묵적 전역 변수)
    x = 10;
    console.log(x);
}
```

- strict mode를 적용하려면 전역의 선두 또는 함수 몸체의 선두에 'use strict'; 추가
- 전역에 strict mode를 적용하는 것은 바람직하지 않음

```
function f() {
    'use strict';

    x = 10;
    console.log(x);
}
```

- strict mode 에서 함수를 일반 함수로서 호출하면 this에 undefined가 바인딩

```
'use strict';

function f() {
    console.log(this);
}

f();
new f();
```


## Function scope vs. Block scope

```
var a = 10;
let b = 20;

{
    var a = 40;
    let b = 80;
}

console.log(a + b);
```

- 일시적 사각지대 (Temporal Dead Zone; TDZ)

```
console.log(foo);
var foo;

console.log(bar);
let bar;
```

```
let foo = 1;

{
    console.log(foo);
    let foo = 2;
}
```


## Const

```
const a = 0;
a = 1;
```

```
const c;
```

```
{
    const y = 3;
}
console.log(y);
```

- 상수는 가독성과 유지 보수의 편의를 위해 적극적으로 사용하는 것이 좋음

```
if (rows > 10) {
}

const MAXROWS = 10;
if (rows > MAXROWS) {
}
```

- 객체 타입 변수 선언에는 const를 사용하는 것이 좋음
- 객체 타입 변수의 주소값을 변경하여야 한다면 let을 사용

```
const user = { name: 'Lee' };

user.name = 'Kim';
console.log(user);
```


## Lexical(Static) scope vs. Dynamic scope

```
정적 스코프: 호출 스택과 관계없이 함수 선언 시점에 스코프를 결정
=> 출력 - Web system development

동적 스코프: 런타임 도중에 실행 컨텍스트에 의해 결정
=> 출력 - 웹 시스템 개발
```

```
const lecture = 'Web system development';

function study() {
    const lecture = '웹 시스템 개발';
    print();
}

function print() {
    console.log(lecture);
}

study();
```


## Template literal

- 백틱(backtick) 문자 `를 사용
- String Interpolation

```
var num1 = 1;
var num2 = 2;
var result = 3;
var str = num1 + ' + ' + num2 + ' = ' + result;
console.log(str);
```

```
var num1 = 1;
var num2 = 2;
var result = 3;
var str = `${num2} + ${num1} = ${result}`;
console.log(str);
```

- String Interpolation 내의 표현식은 문자열로 강제 타입 변환

```
console.log(`1 + 1 = ${1 + 1}`);
```

- '작은따옴표(single quotes)'과 "큰따옴표(double quotes)" 사용 가능

```
const template = `'작은따옴표(single quotes)'과 "큰따옴표(double quotes)"`;
console.log(template);
```


## Hoisting

```
// 함수 표현식
var func = function() {
    console.log("함수 표현식")
}

// 함수 선언문
function func() {
    console.log("함수 선언문");
}

// 호이스팅에 의해서 함수 표현식이 출력됨
console.log(func())
```


```
// 호이스팅에 의해서 함수 선언문이 출력됨
console.log(func())

// 함수 표현식
var func = function() {
    console.log("함수 표현식")
}

// 함수 선언문
function func() {
    console.log("함수 선언문");
}
```


## Arrow function

```
function add1(x, y) {
    return x + y;
}

const add2 = (x, y) => {
    return x + y;
};

const add3 = (x, y) => x + y;


function not1(x) {
    return !x;
}

const not2 = x => !x;
```

```
var obj = {
    name: 'KBU',
    list: ['a', 'b', 'c'],

    func() {
        this.list.forEach(function (e) {
            console.log(this.name, e); // undefined a
        });

        var that = this;
        this.list.forEach(function (e) {
            console.log(that.name, e);
        });

        this.list.forEach(e => {
            console.log(this.name, e);
        });
    }
};

obj.func();
```


## Object expression

```
var obj = {
    key1: 5,
    key2: function() {
        return 3;
    } 
};

console.log(obj.key1 + obj.key2());
```

```
function func1() {
    console.log('func1');
}

function func2() {
    console.log('func2');
}

var obj = {
    func1: func1,
    func2
};

obj.func1();
obj.func2();
```

```
var obj = {
    func1: function() {
        console.log("func1");
    },
    func2() {
        console.log("func2");
    }
}

obj.func1();
obj.func2();
```

```
var key = 'ABC';

var obj = {
}

obj[key + 'D'] = '100';

console.log(obj.ABCD);
console.log(obj);
```

```
var key = 'KBU';

var obj = {
    [key + 2022]: '200'
};

console.log(obj.KBU2022);
console.log(obj);
```

```
const obj1 = { a: 1, b: 2 };
const obj2 = { b: 3, c: 4 };

const mergedObj = { ...obj1, ...obj2 };
console.log(mergedObj);
```


## Destructuring (구조 분해 할당)

```
var obj = {
    state: {
        name: 'KBU'
    },
    method() {
        return 10000;
    },
};

// 1
var name = obj.state.name;
var method = obj.method;
console.log(state, method());

// 2
var { state: { name }, method } = obj;
console.log(name, method());
```

```
var array = ['web', {}, 10, true]

// 1
var str = array[0];
var obj = array[1];
var bool = array[3];
console.log(str, obj, bool);

// 2
const [str, obj, , bool] = array;
console.log(str, obj, bool);
```


## Deep Copy

```
const obj = {
    inner: {
        k: {
            v: 1
        }
    }
};

const s = obj;
console.log(obj.inner.k.v);
console.log(s === obj);

const d1 = structuredClone(obj);
console.log(d1.inner.k.v);
console.log(d1 === obj);

const d2 = JSON.parse(JSON.stringify(obj));
console.log(d2.inner.k.v);
console.log(d2 === obj);
```


## Object-oriented

```
var Human = function (name, age) {
    this.name = name;
    this.age = age;
};

// 정적 메소드
Human.isHuman = function (human) {
    return human instanceof Human;
}

// 인스턴스 메소드
Human.prototype.eat = function () {
    console.log('eat');
};

var Student = function (name, age, univ) {
    Human.call(this, name, age);
    this.univ = univ;
};

Student.prototype = Object.create(Human.prototype);
Student.prototype.constructor = Student;

var wkim = new Student('wkim', 30, 'KBU');
console.log(Human.isHuman(wkim));
wkim.eat();
console.log(wkim.name, wkim.age, wkim.univ);
console.log(wkim);
```

```
class Human {
    constructor(name, age) {
        this.name = name;
        this.age = age;
    }

    static isHuman(human) {
        return human instanceof Human;
    }

    eat() {
        console.log('eat');
    }
}

class Student extends Human {
    constructor(name, age, univ) {
        super(name, age);
        this.univ = univ;
    }
}

var wkim = new Student('wkim', 30, 'KBU');
console.log(Human.isHuman(wkim));

wkim.eat();
console.log(wkim.name, wkim.age, wkim.univ);
```

```
class Car {
    #speed = 0;

    get speed() { 
        return this.#speed; 
    }

    set speed(v) { 
        if (v >= 0) this.#speed = v;
    }
}

const c = new Car();
c.speed = 100;
console.log(c.speed);
```

## Getter / Setter

```
const car = {
    _speed: 0,
    get speed() { 
        return this._speed;
    },
    set speed(v) { 
        if(v >= 0) this._speed = v;
    }
};

car.speed = 100;
console.log(car.speed);

// 가능하지만 하면 안 됨
car._speed = -50;
console.log(car.speed);
```

## 조합

```
const canBark = (state) => ({
  bark: () => console.log(`${state.name} barks!`)
});

const canEat = (state) => ({
  eat: () => console.log(`${state.name} eats!`)
});

const state = { name: "Dog" };
const dog = Object.assign({}, canBark(state), canEat(state));

dog.bark();
dog.eat();
```


## Worker

```
# Worker API in Web Browser

// worker.js

self.onmessage = function(e) {
    const n = e.data;
    let sum = 0;
    for (let i = 1; i <= n; i++) {
        sum += i;
    }
    self.postMessage(sum);
}

// main script

const worker = new Worker('worker.js');

worker.onmessage = function(e) {
    console.log(`Sum: ${e.data}`);
};

worker.postMessage(100);
```

```
# Worker Threads in Node.js

import { Worker, isMainThread, parentPort, workerData } from 'worker_threads';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);

if (isMainThread) {
  const worker = new Worker(__filename, { workerData: 100 });
  worker.on('message', sum => console.log(`Sum: ${sum}`));
} else {
  // Worker Thread
  let sum = 0;
  for (let i = 1; i <= workerData; i++) sum += i;
  parentPort.postMessage(sum);
}
```


## Collection

```
let fruits = ['귤', '레몬', '사과', '수박', '바나나', '복숭아', '자두', '파인애플'];

// 배열 끝에 항목 추가
fruits.push('포도');
console.log(fruits);

// 배열 끝에서부터 항목 제거
let item = fruits.pop();
console.log(item);
console.log(fruits);

// 배열 앞에서부터 항목 제거
item = fruits.shift();
console.log(item);
console.log(fruits);

// 배열 앞에 항목 추가
fruits.unshift(item);
console.log(fruits);
```

```
let fruits = ['귤', '레몬', '사과', '수박', '바나나', '복숭아', '자두', '파인애플'];
console.log(fruits);

console.log(fruits.slice(2, 4));

let index = fruits.indexOf('수박')
console.log(index);

// 인덱스 기반 항목 제거, (index, deleteCount)
let items = fruits.splice(index, 3);
console.log(items);
console.log(fruits);
```

```
let items = new Set();

for (let i = 0; i < 5; i++) {
    let v = Math.floor(Math.random() * 10);
    if (items.has(v)) i--;
    else items.add(v);
}

// Spread Operator
items = [...items].sort();
console.log(items);

console.log(items.every(item => item < 5));
console.log(items.some(item => item < 5));
console.log(items.filter(item => item < 5));
console.log(items.map(item => item + 10));
console.log(items.reduce((acc, item) => acc + item, 100));
```

```
const arr = ['a', 'b', 'c'];

const iterator = arr.values();
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());
console.log(iterator.next());

// for ... of
// 내부적으로 iterator.next() 호출
for (const value of arr.values()) {
    console.log(value);
}
```


## Module

```
# CommonJS(require / module.exports)

// math.js
const add = (a, b) => a + b;
const subtract = (a, b) => a - b;
module.exports = { add, subtract };

// index.js
const { add } = require('./math.js');
console.log(add( 1, 3 ));
```

```
# ESM(SCMAScript Modules)

- Tree Shaking 가능
트리 쉐이킹(Tree Shaking)은 나무를 흔들어 죽은 잎사귀(사용하지 않는 코드)를 떨어뜨리는 것처럼, 최종 결과물에서 쓰지 않는 코드를 자동으로 삭제하는 최적화 기술

// math.js
export const add = (a, b) => a + b;
export const subtract = (a, b) => a - b;

export default (a, b) => a * b;

// index.js
import { add } from './math.js';
console.log(add( 1, 3 ));

# re-export
export { default as multiply } from './math.js';
``