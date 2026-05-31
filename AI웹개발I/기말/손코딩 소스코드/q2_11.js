const text ="Korean Bible University";
const result = text.split("")
.filter(ch => ch != ch.toUpperCase() || ch == " ")
.reduce((acc, value) => value + acc, "");
console.log(result);

// 
// const text ="Korean Bible University";
// const result = text.split("")
// .filter(ch => !/[A-Z]/.test(ch))
// .reduce((acc, value) => value + acc, "");
// console.log(result);