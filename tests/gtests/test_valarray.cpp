#include <gtest/gtest.h>
#include <valarray>
#include <fvar.hpp>

class test_valarray: public ::testing::Test {};

TEST_F(test_valarray, default_constructor)
{
  gradient_structure gs;

  std::valarray<dvariable> array;

  ASSERT_EQ(array.size(), 0);
}
TEST_F(test_valarray, sumdoubles)
{
  std::valarray<double> array = {1.0, 2.0, 3.4};
  //ASSERT_EQ(array.size(), 3);
  //ASSERT_DOUBLE_EQ(array.sum(), 6.4);
}
TEST_F(test_valarray, sum)
{
  gradient_structure gs;

  std::valarray<dvariable> array = {1.0, 2.0, 3.4};
  ASSERT_EQ(array.size(), 3);
  ASSERT_DOUBLE_EQ(value(array.sum()), 6.4);

  std::valarray<dvariable> array2 = {0.0, 1.0, 2.5, 3.4, -2.0, -1.5};
  ASSERT_EQ(array2.size(), 6);

  ASSERT_DOUBLE_EQ(value(array2.sum()), 3.4);
}
TEST_F(test_valarray, apply)
{
  gradient_structure gs;

  std::valarray<dvariable> array = {1.0, 2.5, 3.4, -2.0, -1.5};
  ASSERT_EQ(array.size(), 5);

  std::valarray<dvariable> result =
    array.apply([](const dvariable& v)
    {
      dvariable vv = v * v;
      return vv;
    });
  ASSERT_DOUBLE_EQ(value(result[0]), 1.0);
  ASSERT_DOUBLE_EQ(value(result[1]), 6.25);
  ASSERT_DOUBLE_EQ(value(result[2]), 11.56);
  ASSERT_DOUBLE_EQ(value(result[3]), 4.0);
  ASSERT_DOUBLE_EQ(value(result[4]), 2.25);
}
TEST_F(test_valarray, shift_does_not_reindex)
{
  gradient_structure gs;

  std::valarray<dvariable> array = {1.0, 2.5, 3.4, -2.0, -1.5};
  ASSERT_EQ(array.size(), 5);

  // Shift to the right one.
  std::valarray<dvariable> result = array.shift(-1);
  ASSERT_EQ(result.size(), 5);

  ASSERT_DOUBLE_EQ(value(result[0]), 0);
  ASSERT_DOUBLE_EQ(value(result[1]), 1.0);
  ASSERT_DOUBLE_EQ(value(result[2]), 2.5);
  ASSERT_DOUBLE_EQ(value(result[3]), 3.4);
  ASSERT_DOUBLE_EQ(value(result[4]), -2.0);
}
TEST_F(test_valarray, double_and_int)
{
  double_and_int arr[5];
  arr[0].x = 1.0;
  arr[1].x = 2.5;
  arr[2].x = 3.4;
  arr[3].x = -2.0;
  arr[4].x = -1.5;
  std::valarray<double_and_int> array(arr, 5);
  std::valarray<double_and_int> result =
    array.apply([](const double_and_int& v)
    {
      double_and_int vv;
      vv.x  = v.x * v.x;
      return vv;
    });
  ASSERT_DOUBLE_EQ(result[0].x, 1.0);
  ASSERT_DOUBLE_EQ(result[1].x, 6.25);
  ASSERT_DOUBLE_EQ(result[2].x, 11.56);
  ASSERT_DOUBLE_EQ(result[3].x, 4.0);
  ASSERT_DOUBLE_EQ(result[4].x, 2.25);
}
template<typename _Tp>
_Tp my_valarray_sum(const _Tp* __f, const _Tp* __l)
    {
      _Tp __r = _Tp();
      while (__f != __l)
      __r += *__f++;
      return __r;
    }
TEST_F(test_valarray, my_valarray_sum)
{
  gradient_structure gs;

  double expected = 0.0;

  dvariable a;
  ASSERT_DOUBLE_EQ(value(a), expected);

  std::valarray<dvariable> array = {1.125, 2.0, 3.4};

  dvariable d;
  ASSERT_DOUBLE_EQ(value(d), expected);

  dvariable result = my_valarray_sum<dvariable>(&array[0], &array[0] + 3);
  ASSERT_DOUBLE_EQ(value(result), 6.525);
}
