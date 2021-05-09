/*
 * MIT License. Copyright (c) 2021 Elandig
 */

'use strict'

const { NanFibonacci } = require('bindings')('nan_fibonacci.node')

var instance = new NanFibonacci()

const init = () => {
  console.log(`* Check methods .get(); .next()`)
  printSequence(instance, 20)

  console.log(`\n* Check method .reset()`)
  instance.reset() ? console.log('Sequence was reset!') : ''
  printSequence(instance)

  console.log(`\n* Check method .isFibo()`)
  checkIsFibonacci();
}

const printSequence = (obj, amount = 10) => {
  for (let i=0; i < amount-1; i++)
    obj.next()

  console.log(`Should output the first ${amount} numbers of the fibonacci sequence: ${obj.get()}`)
}

const checkIsFibonacci = () => {
  console.log(`Should output true (String): ${instance.isFibo("280571172992510140037611932413038677189525")}`)
  console.log(`Should output true (Max value for Number): ${instance.isFibo(8944394323791464)}`)
  console.log(`Should output false (Max value for Number exceeded): ${instance.isFibo(14472334024676221)}`)
}

init()
