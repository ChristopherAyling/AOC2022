#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <tuple>
#include <cassert>

int cols2rows(int cols) {
    if (cols == 5) return 5;
    if (cols == 99) return 99;
    throw std::invalid_argument("what is going on lol");
}

int count_visible(int *heights, int rows, int cols) {
    std::cout << "in count visible" << std::endl;
    int visible_trees = 0;
    int edge_trees = rows*2+cols*2-4;
    // for all cols
    for(int col=1; col<cols-1; col++) {
        std::cout << "doing col " << col << std::endl;
        // top to bottom
        int top_max = heights[0*cols+col];
        for(int row=1; row<rows-1; row++) {
            int height = heights[row*cols+col];
            if (height > top_max) {
                top_max = height;
                visible_trees++;
            }
        }
        
        // bottom to top
        int bottom_max = heights[rows*cols+col];
        for(int row=rows-1; row>1; row++) {
            int height = heights[row*cols+col];
            if (height > bottom_max) {
                bottom_max = height;
                visible_trees++;
            }
        }
        std::cout << "done col " << col << std::endl;
    }
    // for all rows
    for(int row=1; row<rows-1; row++) {
        // left to right
        int left_max = heights[row*cols+0];
        for(int col=1; col<cols-1; col++) {
            int height = heights[row*cols+col];
            if (height > left_max) {
                left_max = height;
                visible_trees++;
            }
        }
        // right to left
        int right_max = heights[row*cols+cols];
        for(int col=cols-1; col>1; col--) {
            int height = heights[row*cols+col];
            if (height > right_max) {
                right_max = height;
                visible_trees++;
            }
        }

    }
    //visible_trees -= edge_trees;
    std::cout << "done counting things" << std::endl;
    return visible_trees;
}

int main() {
    std::string str;
    int rows;
    int cols;
    int row = 0;
    int *heights;
    while (std::getline(std::cin, str)) {
        if (row == 0) {
            // initialise heights
            cols = str.length();
            rows = cols2rows(cols);
            heights = (int*)malloc(cols*rows*sizeof(int));
        }

        int col = 0;
        for (char c : str) {
            int height = c - '0';
            heights[row*cols+col] = height;
            col += 1;
        }
        row++;
    }

    assert(rows==row); // belts and braces

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            std::cout << heights[i*cols+j];
        }
        std::cout << std::endl;
    }

    int visible_trees = count_visible(heights, rows, cols);

    std::cout << "visible trees: " << visible_trees << std::endl;
}

