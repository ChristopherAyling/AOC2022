#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <tuple>

std::string parse_name(std::string line) {
    int name_start = line.find("- ");
    int name_end = line.find(" (");
    return line.substr(name_start, name_end-name_start);
}

std::string parse_kind(std::string line) {
    bool is_file = false;
    for (char c : line) {
        if (c == ',') {
            is_file = true;
            break;
        }
    }
    return is_file ? "file" : "dir";
}

int parse_size(std::string line) {
    int size_start = line.find("size=");
    int size_end = line.find(")");
    return std::stoi(line.substr(size_start, size_end));
}

std::tuple<std::string, std::string, int> parse_line(std::string line) {
    std::string name = parse_name(line);
    std::string kind = parse_kind(line);
    int size = (kind == "file") ? parse_size(line) : 0;
    return std::make_tuple(name, kind, size);
}



int main() {
    std::string str;
    int lineno = 0;
    int total_size = 0;
    std::stack<std::string> cwd;
    while (std::getline(std::cin, str)) {
        std::cout << str << std::endl;
        lineno++;
    }
    std::cout << "total size: " << total_size << std::endl;
}

