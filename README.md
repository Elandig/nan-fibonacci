# nan-fibonacci
Node.js Addon that returns the next number of the fibonacci sequence
* [Usage example in a web application](https://github.com/Elandig/nan-fibonacci-wapp)


# Install

## Clone the repository
```
git clone https://github.com/Elandig/nan-fibonacci.git
```

## Initialize & update submodules
```
git submodule update --init
```

## Install dependencies
```
npm install
```

## Make sure you have [node-gyp](https://github.com/nodejs/node-gyp#installation) installed properly
```
npm install -g node-gyp
```


# Build
```
npm run build
```

# Test
```
npm run test
```


# Usage example
```javascript
// Initialization
const { NanFibonacci } = require('bindings')('nan_fibonacci.node')
var instance = new NanFibonacci()

console.log(instance.get()) // 0
console.log(instance.get()) // 1
console.log(instance.next()) // true
console.log(instance.next()) // true
console.log(instance.get()) // 3
console.log(instance.get()) // 5
...
// Reset the accumulator
instance.reset()
console.log(instance.get()) // 0
...
// Check if the given number is the part of the fibonacci sequence
instance.isFibo("280571172992510140037611932413038677189525") // true
instance.isFibo(8944394323791464) // true (Integer values have limitations)
...
// Generate the N-th number of the fibonacci sequence
instance.genFibo(4) // 2
instance.genFibo(16) // 610
...
```

# License
[MIT](https://github.com/Elandig/nan-fibonacci/blob/main/LICENSE) Copyright (C) 2021 [Elandig](https://github.com/Elandig)
