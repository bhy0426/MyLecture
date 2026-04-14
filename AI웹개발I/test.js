var newArr = [10, 20, 30].map(function(element, index, array) {
    console.log(element, index, array);
    return element + 5;
});

console.log(`newArr : ${newArr}`);
