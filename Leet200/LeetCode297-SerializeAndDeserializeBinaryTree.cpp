// LeetCode297-SerializeAndDeserializeBinaryTree.cpp
// Ad147
// Init: 19Mar22
/* -----------------------------------------------------------------------------

297. Serialize and Deserialize Binary Tree
Hard
Tree, Design

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 
----------------------------------------
You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
----------------------------------------

Clarification: 
The above format is the same as `how LeetCode serializes a binary tree`. 
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: 
Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.

----------------------------------------------------------------------------- */

#include <cmath>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
};

// Solution-0 ==================================================================

// Runtime: 40 ms, faster than 99.15% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Memory Usage: 24.7 MB, less than 93.47% of C++ online submissions for Serialize and Deserialize Binary Tree.
// Algorithm: Level-order traversal/BFS.
// Time Complexity: O(n).
// Space Complexity: O(n).

class Codec
{
  public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        if (!root)
            return std::string{};

        std::string ret;
        std::deque<TreeNode *> nodes{root};
        while (!nodes.empty())
        {
            auto t = nodes.front();
            nodes.pop_front();
            if (!t)
            {
                ret += "#,";
                continue;
            }
            ret += std::to_string(t->val) + ',';
            nodes.push_back(t->left);
            nodes.push_back(t->right);
        }

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        if (data.empty())
            return nullptr;

        std::istringstream iss{data};
        std::string str;
        std::getline(iss, str, ',');
        auto root = new TreeNode{std::stoi(str)};
        std::deque<TreeNode *> nodes{root};

        while (iss.rdbuf()->in_avail())
        {
            auto t = nodes.front();
            nodes.pop_front();
            if (!t)
                continue;

            std::getline(iss, str, ',');
            if (str != "#")
                t->left = new TreeNode{std::stoi(str)};
            std::getline(iss, str, ',');
            if (str != "#")
                t->right = new TreeNode{std::stoi(str)};

            nodes.push_back(t->left);
            nodes.push_back(t->right);
        }

        return root;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(false); std::cout.sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

// Main ========================================================================

int main()
{
    Codec cdc;
    auto root = new TreeNode{1};
    root->left = new TreeNode{2};
    root->right = new TreeNode{3};
    root->right->left = new TreeNode{4};
    root->right->right = new TreeNode{5};
    auto r2 = new TreeNode{1};
    r2->right = new TreeNode{2};
    std::cout << cdc.serialize(r2) << std::endl;
    std::cout << cdc.serialize(cdc.deserialize(cdc.serialize(r2))) << std::endl;

    system("pause");
    return 0;
}