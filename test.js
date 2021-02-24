const cvter = require('./index')

let buff = Buffer.from([1,2,3,4,5,6,7,8]);
console.log('before', buff);
cvter.BGRA2RGBA(buff);
console.log('after', buff);