#include <iostream>
#include "BinaryTree.h"

bool BinaryTree::CreateTree(std::deque<TokenMaster> queue) {
    try {
        while (!queue.empty()) {
            const auto token = queue.front();
            queue.pop_front();
            switch (token.type) {
                case TokenType::Number:
                    stack.push_back(std::make_shared<Node>(token.token));
                    break;
                case TokenType::Operator: {
                    std::shared_ptr<Node> rhs = PrepareNode();
                    std::shared_ptr<Node> lhs = PrepareNode();
                    BuildNode(token, rhs, lhs);
                    break;
                }
                default:
                    throw std::runtime_error(" Unsupported token " + token.token);
            }
        }
    } catch (std::bad_alloc &e) {
        std::cout << " Binary Tree error=" << e.what() << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << __func__ << ex.what();
    }
    return true;
}

std::shared_ptr<Node> BinaryTree::PrepareNode() {
    std::shared_ptr<Node> lhs;
    if (!stack.empty()) {
        lhs = stack.back();
        stack.pop_back();
    }
    return lhs;
}

void
BinaryTree::BuildNode(const TokenMaster &token, const std::shared_ptr<Node> &rhs, const std::shared_ptr<Node> &lhs) {
    auto node = (std::make_shared<Node>(token.token));
    node->left = lhs;
    node->right = rhs;
    if (root != nullptr && root->left == nullptr) {
        node->left = nullptr;
        root->left = node;
        stack.push_back(root);
    } else if (root != nullptr && root->right == nullptr) {
        root->right = node;
    } else {
        root = node;
        stack.push_back(node);
    }
}

bool BinaryTree::TraverseTree() {
    TraverseTree(root, false, "");
}

bool BinaryTree::TraverseTree(std::shared_ptr<Node> node, bool isLeft, const std::string &prefix) {
    //Recursion is not efficient way but for simplicity and in interest of time using recursion
    //to print tree
    if (node != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->element << std::endl;
        TraverseTree(node->left, true, prefix + (isLeft ? "│   " : "    "));
        TraverseTree(node->right, false, prefix + (isLeft ? "│   " : "    "));
    }
}

int BinaryTree::SolveExpression(std::deque<TokenMaster> &queue) {
    std::vector<int> stack;
    while (!queue.empty()) {
        std::string op;
        const auto token = queue.front();
        queue.pop_front();
        switch (token.type) {
            case TokenType::Number:
                stack.push_back(std::stoi(token.token));
                break;
            case TokenType::Operator: {
                DoArithmetic(stack, token);
            }
        }
    }
    if (!stack.empty()) return stack.front() ;else 0;
}

void BinaryTree::DoArithmetic(std::vector<int> &stack, const TokenMaster &token) const {
    const auto rhs = stack.back();
    stack.pop_back();
    const auto lhs = stack.back();
    stack.pop_back();
    switch (token.tokenName) {
        case Multiply:
            stack.push_back(lhs * rhs);
            break;
        case Divide:
            stack.push_back(lhs / rhs);
            break;
        case Plus:
            stack.push_back(lhs + rhs);
            break;
        case Minus:
            stack.push_back(lhs - rhs);
            break;
        default:
            throw std::runtime_error(" Unsupported token " + token.token);
    }
}
