/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者: 何海涛
//==================================================================

// 面试题39: 数组中出现次数超过一半的数字
// 题目: 数组中有一个数字出现的次数超过数组长度的一半, 请找出这个数字. 例如输入一个长度为9的数组{1,
// 2, 3, 2, 2, 2, 5, 4, 2}. 由于数字2在数组中出现了5次, 超过数组长度的一半, 因此输出2.

#include <cstdio>
#include <stdexcept>
#include "array.h"

bool CheckMoreThanHalf(int* numbers, int length, int number) {
  int times = 0;
  for (int i = 0; i < length; ++i) {
    if (numbers[i] == number) times++;
  }
  if (times * 2 <= length) {
    return false;
  }
  return true;
}

// ====================方法1====================
int MoreThanHalfNum_Solution1(int* numbers, int length) {
  if ((numbers == nullptr) || (length <= 0)) throw std::invalid_argument("");
  int mid_idx = length >> 1;
  int begin = 0;
  int end = length;
  // Only loop when there are more than one items in data need to be sort.
  while ((begin + 1) < end) {
    int pivot_idx = Partition(numbers, begin, end);
    if (pivot_idx == mid_idx) {
      break;
    } else if (pivot_idx < mid_idx) {
      begin = pivot_idx + 1;
    } else {
      end = pivot_idx;
    }
  }
  if (CheckMoreThanHalf(numbers, length, numbers[mid_idx]) == false) {
    throw std::invalid_argument("");
  }
  return numbers[mid_idx];
}

// ====================方法2====================
int MoreThanHalfNum_Solution2(int* numbers, int length) {
  if ((numbers == nullptr) || (length <= 0)) throw std::invalid_argument("");

  int result = numbers[0];
  int count = 1;
  for (int i = 1; i < length; ++i) {
    if (count == 0) {
      result = numbers[i];
      count = 1;
    } else if (numbers[i] == result) {
      ++count;
    } else {
      --count;
    }
  }

  if (CheckMoreThanHalf(numbers, length, result) == false) throw std::invalid_argument("");
  return result;
}

// ====================测试代码====================
void Test(char const* testName, int* numbers, int length, int expectedValue, bool expectedFlag) {
  if (testName != nullptr) printf("%s begins: \n", testName);

  int* copy = new int[length];
  for (int i = 0; i < length; ++i) copy[i] = numbers[i];

  printf("Test for solution1: ");
  try {
    int result = MoreThanHalfNum_Solution1(numbers, length);
    if (result == expectedValue) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  } catch (std::invalid_argument const& ia) {
    if (expectedFlag == true) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
  }

  printf("Test for solution2: ");
  try {
    int result = MoreThanHalfNum_Solution2(copy, length);
    if (result == expectedValue) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
    delete[] copy;
  } catch (std::invalid_argument const& ia) {
    if (expectedFlag == true) {
      printf("Passed.\n");
    } else {
      printf("Failed.\n");
    }
    delete[] copy;
  }
}

// 存在出现次数超过数组长度一半的数字
void Test1() {
  int numbers[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
  Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2() {
  int numbers[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
  Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3() {
  int numbers[] = {2, 2, 2, 2, 2, 1, 3, 4, 5};
  Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4() {
  int numbers[] = {1, 3, 4, 5, 2, 2, 2, 2, 2};
  Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5() {
  int numbers[] = {1};
  Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6() {
  Test("Test6", nullptr, 0, 0, true);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();

  return 0;
}
