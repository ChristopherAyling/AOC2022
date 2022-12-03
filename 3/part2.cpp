#include <iostream>
#include <string>
#include <fstream>
#include <set>

int main() {
    std::ifstream file("sack.txt");
    std::string str1;
    std::string str2;
    std::string str3;
    int priority_sum = 0;
    while (std::getline(file, str1)) {
        std::sort(str1.begin(), str1.end());
        std::getline(file, str2);
        std::sort(str2.begin(), str2.end());
        std::getline(file, str3);
        std::sort(str3.begin(), str3.end());
        // std::cout << str1 << " " << str2 << " " << str3 << std::endl; 

        std::string inter1;
        std::string inter2;
        std::set_intersection(str1.begin(), str1.end(), str2.begin(), str2.end(), std::back_inserter(inter1));
        std::set_intersection(str1.begin(), str1.end(), str3.begin(), str3.end(), std::back_inserter(inter2));
        std::string strinter;
        std::sort(inter1.begin(), inter1.end());
        std::sort(inter2.begin(), inter2.end());
        std::set_intersection(inter1.begin(), inter1.end(), inter2.begin(), inter2.end(), std::back_inserter(strinter));
        // std::cout << inter1 << " " << inter2 << std::endl;
        // std::cout << strinter << std::endl;
        char same = strinter[0];
        int priority;
        if (same >= 'a') {
            priority = same - 'a' + 1;
        } else {
            priority = same - 'A' + 27;
        }
        priority_sum += priority;
    }
    std::cout << "total priority: " << priority_sum << std::endl;
}
