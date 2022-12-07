#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <set>

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << str << std::endl;
    for (int i = 0; i < str.length()-14; i++) {
        std::string last14 = str.substr(i,14);
        std::cout << i << " looking at " << last14 << std::endl;
        std::set<char> last14set;
        std::cout << last14set.size() << std::endl;
        last14set.insert(last14.begin(), last14.end());
        std::cout << last14set.size() << std::endl;
        if (last14set.size() == 14) {
            std::cout << "found signal start: " << last14 << " at " << i+14 << std::endl;
            break;
        }
    }
}

