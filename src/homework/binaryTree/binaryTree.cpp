/**
 * @file binaryTree.cpp
 * @author your name (you@domain.com)
 * @brief 二叉树5.2.4综合题部分
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "../../../include/binaryTree/binaryTreeSequentialStorage.h"
#include <iostream>
/*
05.已知一棵二叉树按顺序存储结构进行存储，设计一个算法，求编号分别为i和j的两个结点的最近的公共祖先结点的值
*/
int findLowestCommonAncestor(TreeNode t[], int root, int i, int j)
{
    // 如果根节点为空，返回-1表示未找到
    if (root >= MaxSize || t[root].isEmpty)
    {
        return -1;
    }

    // 如果当前节点的值等于i或j，返回当前节点的值
    if (t[root].value == i || t[root].value == j)
    {
        return t[root].value;
    }

    // 在左子树中查找i和j的最近公共祖先
    int leftLCA = findLowestCommonAncestor(t, 2 * root + 1, i, j);

    // 在右子树中查找i和j的最近公共祖先
    int rightLCA = findLowestCommonAncestor(t, 2 * root + 2, i, j);

    // 如果左子树和右子树都找到了最近公共祖先，当前节点就是它们的最近公共祖先
    if (leftLCA != -1 && rightLCA != -1)
    {
        return t[root].value;
    }

    // 否则返回不为空的那个子树中找到的最近公共祖先
    return (leftLCA != -1) ? leftLCA : rightLCA;
}

int myFindLowestCommonAncestor(TreeNode t[], int i, int j)
{
    // 找到i和j在数组t中的索引
    int index_i = -1;
    int index_j = -1;

    for (int k = 0; k < MaxSize; k++)
    {
        if (t[k].isEmpty)
            continue;

        if (t[k].value == i)
        {
            index_i = k;
        }

        if (t[k].value == j)
        {
            index_j = k;
        }

        if (index_i != -1 && index_j != -1)
        {
            break; // 一旦找到i和j的索引，就可以停止搜索
        }
    }

    if (index_i == -1 || index_j == -1)
    {
        return -1; // 未找到i或j，返回-1表示未找到
    }

    // 找到i和j在同一层的祖先节点
    while (index_i != index_j)
    {
        if (index_i > index_j)
        {
            index_i = (index_i - 1) / 2; // 向上查找i的父节点
        }
        else
        {
            index_j = (index_j - 1) / 2; // 向上查找j的父节点
        }
    }

    // 最终，index_i和index_j相等，它们是i和j的最近公共祖先的索引
    return t[index_i].value;
}

// 完全二叉树
int completeFindLowestCommonAncestor(TreeNode t[], int i, int j)
{
    while (i != j)
    {
        if (i > j)
        {
            i = (i - 1) / 2; // 向上查找i的父节点
        }
        else
        {
            j = (j - 1) / 2; // 向上查找j的父节点
        }
    }
    return t[i].value;
}

int main()
{
    // 假设根节点的索引为0
    int rootIndex = 0;
    int i = 2; // 编号为2的节点
    int j = 5; // 编号为5的节点

    int result = findLowestCommonAncestor(t, rootIndex, i, j);

    if (result != -1)
    {
        std::cout << "最近公共祖先的值为: " << result << std::endl;
    }
    else
    {
        std::cout << "没有找到最近公共祖先" << std::endl;
    }

    return 0;
}
