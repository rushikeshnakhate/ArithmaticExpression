#pragma once

#include <string>
#include <memory>
#include <vector>
#include "Tree.h"

struct Node {
    Token element;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(const std::string &_element) {
        this->element = _element;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree : public Tree {
    std::shared_ptr<Node> root;
    std::vector<std::shared_ptr<Node>> stack;
public:
    bool CreateTree(std::deque<TokenMaster> queue) override;

    bool TraverseTree() override;

    bool TraverseTree(std::shared_ptr<Node>, bool isLeft, const std::string &str = "");

    int SolveExpression(std::deque<TokenMaster> &queue);

    void BuildNode(const TokenMaster &token, const std::shared_ptr<Node> &rhs, const std::shared_ptr<Node> &lhs);

    std::shared_ptr<Node> PrepareNode();

    void DoArithmetic(std::vector<int> &stack, const TokenMaster &token) const;
};