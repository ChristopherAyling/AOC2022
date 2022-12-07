#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <set>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    for (int i = 0; i < str.length()-4; i++) {
        std::string last4 = str.substr(i,4);
        std::cout << i << " looking at " << last4 << std::endl;
        std::set<char> last4set;
        std::cout << last4set.size() << std::endl;
        last4set.insert(last4.begin(), last4.end());
        std::cout << last4set.size() << std::endl;
        if (last4set.size() == 4) {
            std::cout << "found signal start: " << last4 << " at " << i+4 << std::endl;
            break;
        }
    }
}

