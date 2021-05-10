/*
 * MIT License. Copyright (c) 2021 Elandig
 */

#include "nan_fibonacci_base.hpp"

/*
 * Purpose: Creates, initializes and returns a new InfInt* array
 */
InfInt *NanFibonacciBase::NewArray(size_t size = INITIAL_SIZE)
{
  // I surely could've used STL containers but I'm specifically asked to do it this way
  InfInt *obj = new InfInt[size];
  for (size_t i = 0; i < size; i++)
    obj[i] = 0;
  return obj;
}

/*
 * Purpose: Creates and initializes a new InfInt* array "value_" if none are present
 */
void NanFibonacciBase::CreateArray()
{
  if (!value_)
  {
    value_ = NewArray(INITIAL_SIZE);
    arr_size = INITIAL_SIZE;
    last_index = 0;
  }
}

/*
 * Purpose: Resizes the "value_" InfInt* array to a greater specified size
 */
void NanFibonacciBase::ResizeArray(size_t new_value)
{
  if (new_value > last_index)
  {
    InfInt *new_array = new InfInt[new_value];
    if (new_array)
    {
      std::copy(value_, value_ + std::min(last_index, new_value), new_array);
      delete[] value_;
      value_ = new_array;
      arr_size = new_value;
    }
    new_array = NULL;
  }
}

/*
 * Purpose: Formats the "value_" InfInt* array to string
 */
std::string NanFibonacciBase::GetFormattedArray()
{
  return FormatArray(value_, last_index);
}

/*
 * Purpose: Adds the next fibonacci sequence number to the "value_" InfInt* array
 *          and resizes it when needed
 */
void NanFibonacciBase::GenNextValue()
{
  if (last_index + 1 >= arr_size)
    ResizeArray(last_index + POOL_BEFORE_RESIZE);
  Fibo(value_, last_index);
  last_index++;
}

/*
 * Purpose: Generates specified amount of numbers of the fibonacci sequence
 * And formats them to string
 */
std::string NanFibonacciBase::GenFibonacci(size_t n)
{
  InfInt *arr = NewArray(n);
  for (size_t i = 0; i < n; i++)
    Fibo(arr, i);
  std::string str = FormatArray(arr, n);
  delete[] arr;
  return str;
}

/*
 * Purpose: Calculates the fibonacci sequence for the given array
 */
void NanFibonacciBase::Fibo(InfInt *&arr, size_t i)
{
  if (i < 2)
    arr[i] = i;
  else
    arr[i] = arr[i - 1] + arr[i - 2];
}

/*
 * Purpose: Resets the state
 */
void NanFibonacciBase::Reset()
{
  if (value_)
  {
    delete[] value_;
    value_ = NULL;
  }
  CreateArray();
}

/*
 * Purpose: Checks if the given number is perfect square
 */
bool NanFibonacciBase::isPerfectSquare(InfInt &val)
{
  InfInt sqrt_v = val.intSqrt();
  return (sqrt_v * sqrt_v == val);
}

/*
 * Purpose: Formats the given InfInt* array to string
 */
std::string NanFibonacciBase::FormatArray(InfInt *&arr, size_t size)
{
  std::string result;
  for (size_t i = 0; i < size; i++)
  {
    result.append(arr[i].toString());
    if (i + 1 == size)
      result.append(".");
    else
      result.append(",");
  }
  return result;
}

/*
 * Purpose: Checks if the given number is a part of the fibonacci sequence
 */
bool NanFibonacciBase::isFibonacci(InfInt &val)
{
  return isPerfectSquare(InfInt(4) + InfInt(5) * val * val) || isPerfectSquare(InfInt(5) * val * val - InfInt(4));
}