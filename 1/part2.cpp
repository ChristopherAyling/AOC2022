#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>

int main() {
    std::ifstream file("cals.txt");
    std::string str;
    std::vector<int> cals;
    int current_total = 0;
    while (std::getline(file, str)) {
        if (str == "") {
            cals.push_back(current_total);
            current_total = 0;
        } else {
             current_total += stoi(str);
        }
    }
    std::sort(cals.begin(), cals.end(), std::greater<int>());
    int top3sum = std::accumulate(cals.begin(), cals.begin()+3, 0);
    std::cout << "top3 elves total: " << top3sum << std::endl;
}
