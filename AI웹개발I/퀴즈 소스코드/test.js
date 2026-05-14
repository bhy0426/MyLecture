// const str = "Korean Bible University";
// const result = str.split("").reduce((acc, v) => v + acc, "");
// console.log(result);

/* const str = "Korean Bible University";
const result = str.split("")
    .filter(ch => ch != ch.toUpperCase() || ch == " ")
    .reduce((acc, v) => v + acc, ""); // toUppterCase()
console.log(result); */

// 정규표현식
const str = "Korean Bible University";
const result = str.split("")
    .filter(ch => !/[A-Z]/.test(ch))
    .reduce((acc, v) => v + acc);
console.log(result);
