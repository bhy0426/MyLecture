var a = 1;
function f1() { return 2; }
var f2 = function() { return 3; }
function f1() { return 4; }
var f2 = function() { return 5; }

function answer() {
    if (a) console.log(a + f1() + f2());
    else console.log(f1() * f2());
    var a = 11;
}

var f2 = function() { return 6; }
function f1() { return 7; };

answer();

var a = 8;
var f2 = function() { return 9; }
function f1() { return 10; }