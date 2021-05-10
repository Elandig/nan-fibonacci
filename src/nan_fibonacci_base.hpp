/*
 * MIT License. Copyright (c) 2021 Elandig
 */

#ifndef NANFIBONACCIBASE_H
#define NANFIBONACCIBASE_H

#define INITIAL_SIZE 3
#define POOL_BEFORE_RESIZE 15

#include <algorithm>
#include "../lib/infint/InfInt.h"

class NanFibonacciBase
{
public:
  static bool isFibonacci(InfInt &val);

  void CreateArray();
  void ResizeArray(size_t nv);
  std::string GetFormattedArray();
  void GenNextValue();
  void Reset();

protected:
  static std::string GenFibonacci(size_t n);
  InfInt *value_{NULL};
  size_t arr_size{3}, last_index{0};

private:
  static InfInt *NewArray(size_t size);
  static std::string FormatArray(InfInt *&arr, size_t size);
  static bool isPerfectSquare(InfInt &val);
  static void NanFibonacciBase::Fibo(InfInt *&arr, size_t i);
};

#endif