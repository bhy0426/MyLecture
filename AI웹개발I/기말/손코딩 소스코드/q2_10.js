const text = "Korean Bible University";
const result = text.split("").reduce((acc, value) => value + acc, "");
console.log(result);