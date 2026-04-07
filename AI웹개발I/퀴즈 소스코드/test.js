const arr = [10, 20, 30, 40, 50];

for(var i = 0; i < arr.length; ++i)
{
    setTimeout(function() {
        console.log("i: " + i);
    }, 1000)
}