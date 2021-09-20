#include "Utils.h"
#include <regex>

std::vector<std::string> Utils::ExpressionsIntoTokens(std::string &expressions) {
    std::vector<std::string> untokenize;
    try {
        std::regex words_regex(R"([0-9]?([0-9]*[.])?[0-9]+|[\\\-\\+\\(\)\/\*])");
        auto words_begin = std::sregex_iterator(expressions.begin(), expressions.end(), words_regex);
        auto words_end = std::sregex_iterator();
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            untokenize.push_back((*i).str());
        }
    } catch (std::exception &ex) {
        std::cout << __func__ << ex.what();
    }
    return untokenize;
}
