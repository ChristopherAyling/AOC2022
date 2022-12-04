#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

std::tuple<int, int> get_nums(std::string pair) {
    int dash_location = pair.find("-");
    int first_num = std::stoi(pair.substr(0, dash_location));
    int second_num = std::stoi(pair.substr(dash_location+1, std::string::npos));
    return std::make_tuple(first_num, second_num);
}

bool is_enclosed(std::tuple<int, int> pair1, std::tuple<int, int> pair2) {
    int lower1, higher1, lower2, higher2;
    std::tie(lower1, higher1) = pair1;
    std::tie(lower2, higher2) = pair2;
    if (lower2 >= lower1 && higher2 <= higher1) return true;
    if (lower1 >= lower2 && higher1 <= higher2) return true;
    return false;
}


int main() {
    std::ifstream file("pairs.txt");
    std::string str;
    int total_enclosed = 0;
    while (std::getline(file, str)) {
        int comma_location = str.find(",");
        std::cout << "comma location: " << comma_location << std::endl;
        std::string first_pair = str.substr(0, comma_location);
        std::string second_pair = str.substr(comma_location+1, std::string::npos);
        std::cout << "first pair: " << first_pair << " second pair: " << second_pair << std::endl;
        std::tuple<int, int> pair1 = get_nums(first_pair);
        std::tuple<int, int> pair2 = get_nums(second_pair);
        bool enc = is_enclosed(pair1, pair2); 
        if (enc) total_enclosed += 1;
        std::cout << "enclosed? " << enc << std::endl;
    }
    std::cout << "total enclosed: " << total_enclosed << std::endl;
}
