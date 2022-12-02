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

int calc_outcome(char opponent, char myself) {
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
    points += calc_outcome(opponent, myself); 
    return points;
}

char run_strat(char opponent, char outcome) {
    if (outcome == 'X') { // lose
        if (opponent == ROCK) return SCISSORS;
        if (opponent == PAPER) return ROCK;
        return PAPER;
    } else if (outcome == 'Y') { // draw
        if (opponent == ROCK) return ROCK;
        if (opponent == PAPER) return PAPER;
        return SCISSORS;
    } else if (outcome == 'Z') { // win
        if (opponent == ROCK) return PAPER;
        if (opponent == PAPER) return SCISSORS;
        return ROCK;
    }
    throw std::invalid_argument("what is this lol");
}

int main() {
    std::ifstream file("guide.txt");
    std::string str;
    int total_score = 0;
    while (std::getline(file, str)) {
        char opponent = letter2choice(str[0]);
        char myself = run_strat(opponent, str[2]);
        // std::cout << opponent << " vs " << myself << std::endl; 
        total_score += your_points(opponent, myself);
    }
    std::cout << "total score: " << total_score << std::endl;
}
