# pixel-converter
Pixel format converter. (e.g. bgra2rgba) 
## example
```js
const cvter = require('pixel-converter')

let buff = Buffer.from([1,2,3,4,5,6,7,8]);
console.log('before', buff);
cvter.BGRA2RGBA(buff);
console.log('after', buff);
```
## install
### nodejs
```bash
npm i pixel-converter
```
### electron
```
npm i pixel-converter
npm i --save-dev electron-rebuild
npm i --save-dev electron-prebuilt
.\node_modules\.bin\electron-rebuild.cmd -v 10.1.5/your electron version -w pixel-converter
```