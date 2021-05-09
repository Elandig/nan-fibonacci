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
  static bool isFibonacci(InfInt& val);
  
  void CreateArray();
  void ResizeArray(size_t nv);
  std::string GetFormattedArray() const;
  void GenNextValue();
  void Reset();

protected:
  static InfInt *NewArray(size_t size);
  InfInt *value_{NULL};
  size_t arr_size{3}, last_index{0};

private:
  static bool isPerfectSquare(InfInt& val);
};

#endif