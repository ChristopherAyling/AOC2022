#include <iostream>
#include <string>
#include <fstream>
#include <set>

int main() {
    std::ifstream file("sack.txt");
    std::string str;
    int priority_sum = 0;
    while (std::getline(file, str)) {
        int halfn = str.length() / 2;
        std::string comp1 = str.substr(0, halfn);
        std::string comp2 = str.substr(halfn, std::string::npos);
        std::sort(comp1.begin(), comp1.end());
        std::sort(comp2.begin(), comp2.end());
        std::string intersection;
        std::set_intersection(comp1.begin(), comp1.end(), comp2.begin(), comp2.end(), std::back_inserter(intersection));
        char same = intersection[0];        
        int samei;
        if (same >= 'a') {
            samei = same - 'a' + 1;
        } else {
            samei = same - 'A' + 27;
        }
        // std::cout << str << " halfway: " << halfn << " first half: " << comp1 << " second half: " << comp2 << " same: " << same << " samei: " << samei << std::endl;
        priority_sum += samei;
    }
    std::cout << "total priority: " << priority_sum << std::endl;
}
