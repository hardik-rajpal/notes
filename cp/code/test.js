let b = [1,2,3];
let d = {j:b};
Object.preventExtensions(d);
delete d.j
// Object.defineProperty(d,'i',{value:0})
console.log(d);