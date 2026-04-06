const result = [, 1, , 3].map(function() {
    return arguments[0] + arguments[1];
}).reduce(function() {
    return arguments[0] + arguments[1];
});
console.log(result);