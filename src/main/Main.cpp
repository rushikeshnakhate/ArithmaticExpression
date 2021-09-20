#include<iostream>
#include <vector>
#include "helper/Utils.h"
#include "engine/ShuntingYard.h"
#include "helper/Parser.h"
#include "tree/BinaryTree.h"

using namespace std;

int main() {
    try {
        std::string expressions = "((15/(7-(1+1)))*-3)-(2+(1+1))";
        std::vector<std::string> untokenize = Utils::ExpressionsIntoTokens(expressions);
        auto coreEngine = std::make_unique<ShuntingYard>();
        auto queue = coreEngine->Process(Parser::Parse(untokenize));
        auto tree = std::make_unique<BinaryTree>();
        tree->CreateTree(queue);
        tree->TraverseTree();
    }
    catch (std::exception &ex) {
        std::cout << "Error in Main Error=" << ex.what();
    }
    return 0;
}
