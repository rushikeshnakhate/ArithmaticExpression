#include<iostream>

using namespace std;

int main() {
    try {

    }
    catch (std::exception &ex) {
        std::cout << "Error in Main Error=" << ex.what();
    }
    return 0;
}
