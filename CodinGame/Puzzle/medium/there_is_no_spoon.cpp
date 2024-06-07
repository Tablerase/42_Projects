#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

// table of node - true if present, false if empty

string full = "0";
string empty = ".";

void Error(){
  std::cout << "-1 -1";
}

int findNextTrueInRow(const vector<vector<bool>>& table, int row, int startCol) {
    for (int col = startCol + 1; col < table[row].size(); ++col) {
        if (table[row][col]) {
            return col;
        }
    }
    return -1; // Return -1 if no true value is found
}

int findNextTrueInCol(const vector<vector<bool>>& table, int startRow, int col) {
    for (int row = startRow + 1; row < table.size(); ++row) {
        if (table[row][col]) {
            return row;
        }
    }
    return -1; // Return -1 if no true value is found
}

void OutputRightNode(vector<vector<bool>> table, int node_x, int node_y){
  int node;
  if (node_x + 1 >= table[node_y].size()){
    Error();
  } else {
    node = findNextTrueInRow(table, node_y, node_x);
    if (node == -1){
      // std::cerr << "right empty" << std::endl;
      Error(); 
      } else {
      // std::cerr << "right found" << std::endl;
      std::cout << node << " " << node_y;
    }
  }
}

void OutputBottomNode(vector<vector<bool>> table, int node_x, int node_y){
  int node;
  if (node_y + 1 >= table.size()){
    Error();
  } else {
    node = findNextTrueInCol(table, node_y, node_x);
    if (node == -1){
      // std::cerr << "bot empty" << std::endl;
      Error();
      } else {
      // std::cerr << "bot found" << std::endl;
      std::cout << node_x << " " << node;
    }
  }
}

void OutputNode(vector<vector<bool>> table, int node_x, int node_y){
  // std::cerr << "Node: " << node_x << " " << node_y << std::endl;
  if (table[node_y][node_x] == true){
    std::cout << node_x << " " << node_y;
    std::cout << " ";
    OutputRightNode(table, node_x, node_y);
    std::cout << " ";
    OutputBottomNode(table, node_x, node_y);
    std::cout << std::endl;
  }
}

int main()
{
    int width; // the number of cells on the X axis
    std::cin >> width; std::cin.ignore();
    int height; // the number of cells on the Y axis
    std::cin >> height; std::cin.ignore();
    std::cerr << "X axis lenght: " << width << std::endl;
    std::cerr << "Y axis height: " << height << std::endl;

    // Create a 2D vector with 'height' rows and 'width' columns, initialized with 0
    std::vector<std::vector<bool>> table(height, std::vector<bool>(width, false));
    for (int i = 0; i < height; i++) {
      std::string line;
      std::getline(std::cin, line); // width characters, each either 0 or .
      std::cerr << "Row[" << i << "]: " << line << std::endl;
      for (int x = 0; x < width; x++){
        if (line[x] == full[0]){
          // std::cerr << "Test" << table[height][x] << std::endl;
          table[i][x] = true;
          } else {
          table[i][x] = false;
        }
      }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (int y = 0; y < height; y++) {
      std::cerr << " [ ";
      for (int x = 0; x < width; x++){
        std::cerr << (table[y][x] == true) ? "0" : ".";
        std::cerr << " ";
      }
      std::cerr << "]" << std::endl;
    }

    // Three coordinates: a node, its right neighbor, its bottom neighbor
    // cout << "0 0 1 0 0 1" << endl;
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++){
        OutputNode(table, x, y);
      }
    }
}