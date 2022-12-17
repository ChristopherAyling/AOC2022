#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <tuple>
#include <unordered_set>
#include <algorithm>
#include <map>

typedef std::vector<std::string> cwd_t;
typedef std::tuple<std::string, std::string, int> file_t; // (str(cwd_t), fname, size)
typedef std::vector<file_t> files_t;
typedef std::unordered_set<std::string> dirs_t;
typedef std::map<std::string, int> size_counts_t;

std::string CD = "$ cd";
std::string LS = "$ ls";

bool is_cmd(std::string line) {
    return line[0] == '$';
}

bool is_dir(std::string line) {
    return line.substr(0, 3) == "dir";
}

std::string cwd2string(cwd_t cwd) {
    std::string s;
    for (const auto &piece : cwd) s += (piece == "/") ? piece : piece + "/";
    return s;
}

void parse_cmd(std::string line, cwd_t &cwd) {
    if (line.substr(0, 4) == CD) {
        std::string name = line.substr(4, CD.length());
        if (name == " ..") {
            cwd.pop_back();
        } else {
            std::string dir_name = name.substr(1, std::string::npos);
            cwd.push_back(dir_name);
        }
        std::cout << "folder: " << cwd2string(cwd) << std::endl;
    } 
}

void record_file(std::string line, cwd_t &cwd, files_t &files) {
    if (is_dir(line)) {
        return;
    }
    int space_location = line.find(" ");
    std::string size_string = line.substr(0, space_location);
    std::string fname = line.substr(space_location+1, std::string::npos);
    std::cout << "size_string: " << size_string << std::endl;
    int size = std::stoi(size_string);
    file_t f = std::make_tuple(cwd2string(cwd), fname, size);
    files.push_back(f);
} 

void print_files(files_t files) {
    std::cout << "--- files ---" << std::endl;
    for (file_t f : files) {
        std::cout << std::get<0>(f) << " | " << std::get<1>(f) << " | " << std::get<2>(f) << std::endl;
    }
    std::cout << "-- end files ---" << std::endl;
}

dirs_t get_dirs(files_t files) {
    dirs_t dirs;
    for (file_t f : files) {
        dirs.insert(std::get<0>(f));
    }
    return dirs;
}

void print_dirs(dirs_t dirs) {
    std::cout << "--- dirs ---" << std::endl;
    for (auto d : dirs) {
        std::cout << d << std::endl;
    }
    std::cout << "--- end dirs ---" << std::endl;
}

size_counts_t calc_dir_sizes(files_t files) {
    dirs_t dirs = get_dirs(files);
    size_counts_t size_counts;
    for (std::string dir : dirs) {
        size_counts[dir] = 0;
        for (file_t file : files) {
            if (std::get<0>(file).rfind(dir, 0) == 0) {
                size_counts[dir] += std::get<2>(file);
            }
        }
    }
    return size_counts;
}


int main() {
    std::string str;
    cwd_t cwd;
    files_t files;
    while (std::getline(std::cin, str)) {
        std::cout << "line: " << str << std::endl;
        if (is_cmd(str)) {
            parse_cmd(str, cwd);
        } else {
            record_file(str, cwd, files); 
        }
    }
    print_files(files);
    dirs_t dirs = get_dirs(files);
    print_dirs(dirs);
    size_counts_t sizes = calc_dir_sizes(files);
    std::cout << "--- sizes (without subdirs) ---" << std::endl;
    int total_size = 0;
    for (auto &[key, value] : sizes) {
        std::cout << key << " " << value << std::endl;
        if (value < 100000) total_size += value;
    }
    std::cout << "--- end sizes ---" << std::endl;
    std::cout << "total size: " << total_size << std::endl;

}

