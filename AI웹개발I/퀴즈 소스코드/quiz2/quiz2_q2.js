const result = [, 1, , 3].map(function() {
    return arguments[0] + arguments[1];
}).reduce(function() {
    return arguments[1] + arguments[0]; // arguments[0]는 누적값인데 처음에는 비어있음
});
console.log(result);