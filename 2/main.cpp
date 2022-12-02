#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

char ROCK='r';
char PAPER='p';
char SCISSORS='s';

char letter2choice(char str) {
    if (str == 'A' || str == 'X') {
        return ROCK;
    } else if (str == 'B' || str == 'Y') {
        return PAPER;
    } else if (str == 'C' || str == 'Z') {
        return SCISSORS;
    }
    throw std::invalid_argument("what is this lol");
}

int outcome(char opponent, char myself) {
    if (opponent == myself) return 3;
    if (opponent == ROCK && myself == SCISSORS) return 0;
    if (opponent == PAPER && myself == ROCK) return 0;
    if (opponent == SCISSORS && myself == PAPER) return 0;
    return 6;
}

int your_points(char opponent, char myself) {
    int points = 0;
    // points for shape you selected
    if (myself == ROCK) {
        points += 1;
    } else if (myself == PAPER) {
        points += 2;
    } else if (myself == SCISSORS) {
        points += 3;
    } else {
        throw std::invalid_argument("what is this lol");
    }
    // points for outcome of the round
    points += outcome(opponent, myself); 
    return points;
}

int main() {
    std::ifstream file("guide.txt");
    std::string str;
    int total_score = 0;
    while (std::getline(file, str)) {
        char opponent = letter2choice(str[0]);
        char myself = letter2choice(str[2]);
        // std::cout << opponent << " vs " << myself << std::endl; 
        total_score += your_points(opponent, myself);
    }
    std::cout << "total score: " << total_score << std::endl;
}
