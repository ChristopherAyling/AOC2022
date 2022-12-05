#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <tuple>

const int LOAD = 0;
const int MOVE = 1;

typedef std::deque<char> containers_t;

void setup_stacks(std::string str, std::vector<containers_t> &stacks) {
        std::cout << "setting up stacks" << std::endl;
        if (str.length() == 35) {
                for (int i=0; i<9; i++) {
                        containers_t new_stack;
                        stacks.push_back(new_stack);
                }
        } else if (str.length() == 11) {
                for (int i=0; i<3; i++) {
                        containers_t new_stack;
                        stacks.push_back(new_stack);
                }
        } else {
                throw std::invalid_argument("what is going on lol");
        }
}

void parse_stack_line(std::string line, std::vector<containers_t> &stacks) {
    int current_stack = 0;
    for (int i=1; i<line.length(); i+=4) {
        if (line[i] != ' ') {
            stacks[current_stack].push_front(line[i]);
        }
        current_stack += 1;
    }
}

void show_stack_tops(std::vector<containers_t> stacks) {
    for (auto stack : stacks) {
        std::cout << stack.back();
    }
    std::cout << std::endl;
}

std::tuple<int, int, int> find_word_locations(std::string str) {
    int word1 = std::stoi(str.substr(str.find("move ") + 5, str.find(" from ")));
    int word2 = std::stoi(str.substr(str.find(" from ") + 6, str.find(" to ")));
    int word3 = std::stoi(str.substr(str.find(" to ") + 4, std::string::npos));
    return std::make_tuple(word1, word2, word3);
}


int main() {
    std::string str;
    std::vector<containers_t> stacks;
    int lineno = 0;
    int mode = LOAD;
    while (std::getline(std::cin, str)) {
        if (lineno == 0) {
            setup_stacks(str, stacks);
        }
        if (mode == LOAD) {
            if (str.substr(0, 2) == " 1") {
                std::getline(std::cin, str); // skip the empty line
                mode = MOVE;
            } else {
                parse_stack_line(str, stacks);
            }
        } else if (mode == MOVE) {
            std::cout << "instruction " << str << std::endl;
            auto [w1, w2, w3] = find_word_locations(str);
            std::cout << "w1:" << w1 << " w2:" << w2 << " w3:" << w3 << std::endl;

            
        } else {
            throw std::invalid_argument("what mode is this lol");
        }

        lineno++;
    }
    show_stack_tops(stacks);
}

