const str = "javascript";
const count = {};

for (const ch of str)
    count[ch] = (count[ch] || 0) + 1;

let maxChar = "";
let maxCount = 0;

for (const key in count) {
    if (count[key] > maxCount) {
        maxCount = count[key];
        maxChar = key;
    }
}
console.log(maxChar);