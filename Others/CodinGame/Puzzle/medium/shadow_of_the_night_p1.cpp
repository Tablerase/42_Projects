#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

class Batman 
{
public:
    int x;
    int y;
    int turn_left;
};

class Map
{
public:
    int width;
    int height;
    // x, y;
    pair<int, int> target_position;
    // y, x;
    vector< vector<bool> > building;

    // limits
    int x_min;
    int x_max;
    int y_min;
    int y_max;

    void PrintBuilding(Batman player){
        for (int i = 0; i < x_max; i++){
            cerr << "| ";
            for (int j = 0; j < y_max; j++){
                if (player.x == j && player.y == i){
                    cerr << "P ";
                } else {
                  if (i <= y_min || i >= y_max || j <= x_min || j >= x_max){
                    cerr << "0 ";
                  } else {
                    cerr << "1 ";
                  }
                }
            }
            cerr << "|" << endl;
        }
    }

    int IndexDir(string bomb_dir){
        vector<string> dir = {
            "U", "UR", "R", "DR", "D", "DL", "L", "UL",
            "Unknown"
        };
        for (int i = 0; i < dir.size(); i++){
            if (bomb_dir == dir[i]){
                // cerr << "Found Dir: " << dir[i] << endl;
                return i; 
            }
        }
        return -1;
    }

    void UpMap(Batman player){
      cerr << "Up clear" << endl;
      y_max = player.y - 1;
    }

    void DownMap(Batman player){
      cerr << "Down clear" << endl;
      y_min = player.y + 1;
    }

    void LeftMap(Batman player){
      cerr << "Left clear" << endl;
      x_max = player.x - 1;
    }

    void RightMap(Batman player){
      cerr << "Right clear" << endl;
      x_min = player.x + 1;
    }

    // "U", "UR", "R", "DR", "D", "DL", "L", "UL"
    void UpdateMap(string bomb_dir, Batman player){
        switch (IndexDir(bomb_dir)){
            case 0:
                UpMap(player);
                return;
            case 1:
                UpMap(player);
                RightMap(player);
                return;
            case 2:
                RightMap(player);
                return;
            case 3:
                DownMap(player);
                RightMap(player);
                return;
            case 4:
                DownMap(player);
                return;
            case 5:
                DownMap(player);
                LeftMap(player);
                return;
            case 6:
                LeftMap(player);
            case 7:
                UpMap(player);
                LeftMap(player);
                return;
            default:
                return;
        }
    }

    void FindTarget(){
      float middle_row;
      float midlle_column;

      middle_row = ((float)y_min + (float)y_max) / 2;
      midlle_column = ((float)x_min + (float)x_max) / 2;
      target_position.first = ceil(midlle_column);
      target_position.second = ceil(middle_row);
      if (target_position.first >= width){
          target_position.first = width - 1;
      }
      if (target_position.second >= height){
        target_position.second = height - 1;
      }
    }
};

int main()
{
    // Init values;
    Batman player;
    Map area;

    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    // Assign value to player
    player.x = x0;
    player.y = y0;
    player.turn_left = n;
    // Assign value to map
    area.height = h;
    area.width = w;
    area.y_max = h;
    area.y_min = 0;
    area.x_max = w;
    area.x_min = 0;

    string last_output;
    int same_output = 0;

    // game loop
    while (1) {
        cerr 
            << "Building: w=" << w << " h=" << h << " "
            << "Player: x=" << player.x << " y=" << player.y << " "
            << "Turn left: " << player.turn_left << endl;
        // area.PrintBuilding(player);
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();
        cerr << "Bomb dir: " << bomb_dir << endl;

        // Update building search area
        area.UpdateMap(bomb_dir, player);
        area.FindTarget();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        // the location of the next window Batman should jump to.

        cout
            << area.target_position.first << " " 
            << area.target_position.second
            << endl;
        player.x = area.target_position.first;
        player.y = area.target_position.second;

        // reduce amount of turn left;
        player.turn_left--;
    }
}

/*
Coordinates:
w = 0 to w (left to right)
h = h to 0 (top to bottom)
*/