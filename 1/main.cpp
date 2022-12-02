#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::ifstream file("cals.txt");
    std::string str;
    int global_max = 0;
    int current_total = 0;
    int i = 0;
    int maxi = 0;
    while (std::getline(file, str)) {
        if (str == "") {
            if (current_total > global_max) {
                global_max = current_total;
                maxi = i;
            }
            current_total = 0;
             i++;
        } else {
             current_total += stoi(str);
        }
    }
    std::cout << "global max: " << global_max << std::endl;
    std::cout << "elf: " << maxi << std::endl;
}
