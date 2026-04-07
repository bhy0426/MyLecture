const arr = [10, 20, 30, 40, 50];

for(var i = 0; i < arr.length; ++i)
{
    setTimeout(function(index) {
        return function() {
            console.log('i : ' + index);
        }
    }(i), 1000)
}