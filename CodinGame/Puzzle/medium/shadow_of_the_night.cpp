#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

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

    void PrintBuilding(Batman player){
        for (int i = 0; i < building.size(); i++){
            cerr << "| ";
            for (int j = 0; j < building.at(i).size(); j++){
                if (player.x == j && player.y == i){
                    cerr << "P ";
                } else {
                    cerr << building.at(i).at(j) << " ";
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
      for (auto it = building.begin(); it != building.end(); ++it){
        for (auto jt = it->begin(); jt != it->end(); ++jt){
          if (std::distance(building.begin(), it) >= player.y){
            *jt = false;
          }
        }
      }
    }

    void DownMap(Batman player){
      cerr << "Down clear" << endl;
      for (auto it = building.begin(); it != building.end(); ++it){
        for (auto jt = it->begin(); jt != it->end(); ++jt){
          if (std::distance(building.begin(), it) <= player.y){
            *jt = false;
          }
        }
      }
    }

    void LeftMap(Batman player){
      cerr << "Left clear" << endl;
      for (auto it = building.begin(); it != building.end(); ++it){
        for (auto jt = it->begin(); jt != it->end(); ++jt){
          if (std::distance(it->begin(), jt) >= player.x){
            *jt = false;
          }
        }
      }
    }

    void RightMap(Batman player){
      cerr << "Right clear" << endl;
      for (auto it = building.begin(); it != building.end(); ++it){
        for (auto jt = it->begin(); jt != it->end(); ++jt){
          if (std::distance(it->begin(), jt) <= player.x){
            *jt = false;
          }
        }
      }
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
      int middle_row;
      int midlle_column;

      int valueToFind = 1;
      int min_row;
      int min_column;
      int max_column;
      for (int i = 0; i < building.size(); i++){
        auto first = std::find(building.at(i).begin(), building.at(i).end(),
          valueToFind);
        auto last = std::find_end(building.at(i).begin(), building.at(i).end(), 
          &valueToFind, &valueToFind + 1);
        if (first != building.at(i).end() && last != building.at(i).end()){
          min_column = std::distance(building.at(i).begin(), first);
          max_column = std::distance(building.at(i).begin(), last);
          min_row = i;
          break;
        }
      }

      int max_row;
      for (int i = building.size() - 1; i != 0; i--){
        auto it = std::find(building.at(i).begin(), building.at(i).end(),
        true);
        if (it != building.at(i).end()){
          max_row = i;
          break;
        }
      }

      middle_row = (min_row + max_row) / 2;
      midlle_column = (min_column + max_column) / 2;
      target_position.first = midlle_column;
      target_position.second = middle_row;
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

    for (int i = 0; i < h; i++){
        vector<bool> floor;
        for (int j = 0; j < w; j++){
            floor.push_back(true);
        }
        area.building.push_back(floor);
    }
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