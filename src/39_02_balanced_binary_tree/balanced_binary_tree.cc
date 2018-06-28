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

// 面试题55(二): 平衡二叉树
// 题目: 输入一棵二叉树的根结点, 判断该树是不是平衡二叉树. 如果某二叉树中任意结点的左右子树的深度相
// 差不超过1, 那么它就是一棵平衡二叉树.

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include "common/binary_tree.h"

// ====================方法1====================
int TreeDepth(BinaryTreeNode const* root) {
  if (root == nullptr) return 0;
  int left_depth = TreeDepth(root->m_pLeft);
  int right_depth = TreeDepth(root->m_pRight);
  return (left_depth > right_depth) ? (left_depth + 1) : (right_depth + 1);
}

bool IsBalanced_Solution1(BinaryTreeNode const* root) {
  if (root == nullptr) return true;
  int left_depth = TreeDepth(root->m_pLeft);
  int right_depth = TreeDepth(root->m_pRight);
  return ((std::abs(left_depth - right_depth) <= 1) &&
          (IsBalanced_Solution1(root->m_pLeft) && IsBalanced_Solution1(root->m_pRight)));
}

// ====================方法2====================
bool IsBalanced_Solution2Core(BinaryTreeNode const* root, int* depth) {
  if (depth == nullptr) throw std::invalid_argument("");
  if (root == nullptr) {
    *depth = 0;
    return true;
  }
  int left_depth = 0;
  int right_depth = 0;
  if ((IsBalanced_Solution2Core(root->m_pLeft, &left_depth) == true) &&
      (IsBalanced_Solution2Core(root->m_pRight, &right_depth) == true)) {
    *depth = 1 + std::max(left_depth, right_depth);
    return (std::abs(left_depth - right_depth) <= 1);
  }
  return false;
}

bool IsBalanced_Solution2(BinaryTreeNode const* root) {
  int depth = 0;
  return IsBalanced_Solution2Core(root, &depth);
}

// ====================测试代码====================
void Test(const char* testName, const BinaryTreeNode* pRoot, bool expected) {
  if (testName != nullptr) printf("%s begins:\n", testName);

  printf("Solution1 begins: ");
  if (IsBalanced_Solution1(pRoot) == expected)
    printf("Passed.\n");
  else
    printf("Failed.\n");

  printf("Solution2 begins: ");
  if (IsBalanced_Solution2(pRoot) == expected)
    printf("Passed.\n");
  else
    printf("Failed.\n");
}

// 完全二叉树
//           1
//         /   \
//        2     3
//       / \   / \
//      4   5 6   7
void Test1() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNode1, pNode2, pNode3);
  ConnectTreeNodes(pNode2, pNode4, pNode5);
  ConnectTreeNodes(pNode3, pNode6, pNode7);

  Test("Test1", pNode1, true);

  DestroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//          1
//         / \
//        2   3
//       / \   \
//      4   5   6
//         /
//        7
void Test2() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
  BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

  ConnectTreeNodes(pNode1, pNode2, pNode3);
  ConnectTreeNodes(pNode2, pNode4, pNode5);
  ConnectTreeNodes(pNode3, nullptr, pNode6);
  ConnectTreeNodes(pNode5, pNode7, nullptr);

  Test("Test2", pNode1, true);

  DestroyTree(pNode1);
}

// 不是平衡二叉树
//          1
//         / \
//        2   3
//       / \
//      4   5
//         /
//        6
void Test3() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
  BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

  ConnectTreeNodes(pNode1, pNode2, pNode3);
  ConnectTreeNodes(pNode2, pNode4, pNode5);
  ConnectTreeNodes(pNode5, pNode6, nullptr);

  Test("Test3", pNode1, false);

  DestroyTree(pNode1);
}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test4() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNode1, pNode2, nullptr);
  ConnectTreeNodes(pNode2, pNode3, nullptr);
  ConnectTreeNodes(pNode3, pNode4, nullptr);
  ConnectTreeNodes(pNode4, pNode5, nullptr);

  Test("Test4", pNode1, false);

  DestroyTree(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test5() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
  BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
  BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
  BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

  ConnectTreeNodes(pNode1, nullptr, pNode2);
  ConnectTreeNodes(pNode2, nullptr, pNode3);
  ConnectTreeNodes(pNode3, nullptr, pNode4);
  ConnectTreeNodes(pNode4, nullptr, pNode5);

  Test("Test5", pNode1, false);

  DestroyTree(pNode1);
}

// 树中只有1个结点
void Test6() {
  BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
  Test("Test6", pNode1, true);

  DestroyTree(pNode1);
}

// 树中没有结点
void Test7() {
  Test("Test7", nullptr, true);
}

int main(int argc, char* argv[]) {
  Test1();
  Test2();
  Test3();
  Test4();
  Test5();
  Test6();
  Test7();

  return 0;
}
