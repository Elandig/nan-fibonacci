// MIT License. Copyright (c) 2021 Elandig
'use strict'

const { NanFibonacci } = require('bindings')('nan_fibonacci.node')

var instance = new NanFibonacci()

const init = () => {
  printSequence(instance)

  instance.reset()
  console.log('Sequence was reset!')
  printSequence(instance, 20)
}

const printSequence = (obj, amount = 10) => {
  let sequence = []
  for (let i=0; i < amount; i++)
    sequence.push(obj.get())

  console.log(`Should output the first ${amount} numbers of the fibonacci sequence: ${sequence.join()}`)
}

init()
