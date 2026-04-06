```
let age: number = 25;

function add(a: number, b: number): number {
    return a + b;
}
```

```
const user: { name: string; age: number } = {
    name: "Wonvin",
    age: 30
};
console.log(user);
```

```
// any
let data: any = 1;
data = 's';
console.log(data);

// unkown
let data: unknown = 1;
if (typeof data === 'number')
    console.log(data);
```

```
// Array
let numbers: number[] = [1, 2, 3, 4];

// Generic
let strings: Array<string> = ['One', 'Two', 'Three', 'Four']; 

// Tuple
let person: [string, number] = ['John', 30];

// never: 절대 실행이 끝나지 않거나, 절대 반환되지 않는 함수의 반환 타입
function throwError(): never {
    throw new Error('예외');
}
function infiniteLoop(): never {
    while (true) {}
}
```

```
// Union
let state: "Success" | "Fail" | "None";
state = "Success";
state = "Fail";
state = "None";
console.log(state);

// ---

function printId(id: number | string) {
    if (typeof id === 'string')
        console.log(id.toUpperCase());
    else
        console.log(id.toFixed(2)); // if id = 5 then 5.00
}
```

/*
Type
- 확장 불가
- 재선언 불가
*/

type User = {
    name: string;
    age: number;
};

const user: User = {
    name: 'Wonvin',
    age: 30
};

console.log(user);

// ---

// - Union
type ID = number | string;

// - Tuple
type Point = [number, number];
```

```
/* 
Interface
- 확장 가능
- 재선언 시 자동 병합
*/

interface User {
    name: string;
}

interface User {
    age: number;
    isAdmin?: boolean;  // '?' 선택적 속성(Optional)
}

const user: User = {
    name: 'Wonvin',
    age: 30
}
console.log(user);

// ---

interface Person {
    name: string;
    age: number;
}

interface Employee extends Person {
    employeeId: number
}

const employee: Employee = {
    name: 'Wonvin',
    age: 30,
    employeeId: 101
}
console.log(employee);

```

```
// Intersection
type HasName = { name: string };
type HasAge = { age: number };

type Person = HasName & HasAge;

const p: Person = {
    name: 'Wonvin',
    age: 30
};
```

/*
타입 관리

src/
    components/
        UserComponent/
            UserComponent.tsx
            types.ts    # 모듈별 타입 정의
    services/
        userService/
            userService.ts
            types.ts    # 모듈별 타입 정의
    types/
        commonTypes.ts  # 공통 타입 정의
        userTypes.ts    # 공통 타입 정의
        apiTypes.ts     # 공통 타입 정의
    index.ts
*/

/*
Generic

function identity<value: T>: T {
    return value;
}

identity<number>(111);
identity<string>('hello');

// ---

type Optional<T = string> = T | undefined;

const greet: Optional = 'hello';
const count: Optional<number> = 10;
console.log(greet, count)
*/

/*
class Duck {
    quack(): void {
        console.log('Quack!');
    }
}

class Robot {
    quack(): void {
        console.log('Robotic Quack!');
    }
}

class Chicken {
    cluck(): void {
        console.log('Cluck!');
    }
}

// ---

function makeItQuack(animal: { quack(): void }) {
    animal.quack();
}

makeItQuack(new Robot());
makeItQuack(new Chicken()); // Error

// ---

function isQuackable(animal: any): animal is { quack: () => void } {
    return 'quack' in animal;
}

function makeItQuack(animal: unknown) {
    if (isQuackable(animal)) animal.quack();
}

makeItQuack(new Robot());
*/

/*
interface Quackable {
    quack(): void;
}

class Duck implements Quackable {
    quack() {
        console.log('Quack!');
    }
}

function makeItQuack(animal: Quackable) {
    animal.quack();
}

makeItQuack(new Duck());
*/


/*
Utility type

Partial<T>
- 타입의 모든 속성을 선택적(optional)로 변경
- 수정 요청이나 부분 상태 업데이트 시 활용

Required<T>
- 타입의 모든 속성을 필수(required)로 변경
- 초기화 누락 방지를 위해 활용

Pick<T, K>
- 타입 T에서 일부 속성만 선택(pick)하여 새로운 타입 생성

Omit<T, K>
- 타입 T에서 특정 속성을 제외(omit)한 타입 생성
- 민감 정보 제거할 때 활용

Record<K, T>
- 키 집합 K의 각 원소를 키로, 타입 T를 값으로 가지는 객체 타입을 생성
*/

```
// Partial<T>

type User = {
    id: number;
    name: string;
};

// id 생략
const patchUser: Partial<User> = {
    name: 'Wonvin'
}
console.log(patchUser);
```

```
// Required<T>

type Config = {
    debug?: boolean;
};

const strictConfig: Required<Config> = {
    debug: true
}
console.log(strictConfig);
```

```
// Pick<T, K>

type User = {
    id: number;
    name: string;
    age: number;
};

type UserPreview = Pick<User, 'id' | 'name'>;

const user: UserPreview = {
    id: 1001,
    name: 'Wonvin',
};
console.log(user);
```

```
// Omit<T, K>

type User = {
    id: number;
    name: string;
    Password: string;
};

type SafeUser = Omit<User, 'Password'>

const user: SafeUser = {
    id: 1001,
    name: 'Wonvin'
};
console.log(user);
```

```
// Record<K, T>

type Page = "home" | "about" | "contact";

interface PageInfo {
  title: string;
}

// 'home', 'about', 'contact'라는 키를 가지며, 값은 모두 PageInfo 타입이어야 함
const nav: Record<Page, PageInfo> = {
  home: { title: "Home" },
  about: { title: "About" },
  contact: { title: "Contact" },
};
```