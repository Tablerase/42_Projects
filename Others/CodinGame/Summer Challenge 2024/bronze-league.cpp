#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum class Games {
  HURDLE_RACE = 0,
};

enum class Direction {
  LEFT,
  DOWN,
  RIGHT,
  UP,
  STUN
};

string DirectionToString(Direction dir) {
  switch (dir) {
    case Direction::LEFT:
        return "LEFT";
    case Direction::DOWN:
        return "DOWN";
    case Direction::RIGHT:
        return "RIGHT";
    case Direction::UP:
        return "UP";
    case Direction::STUN:
        return "STUN";
    default:
        return "UNKNOWN DIRECTION";
  }
}

/**
 * Move the player according to the distance
 * @param Direction: the direction to move
 */
void Move(Direction dir) {
  switch (dir) {
    case Direction::LEFT:
      cout << "LEFT" << endl;
      break;
    case Direction::DOWN:
      cout << "DOWN" << endl;
      break;
    case Direction::RIGHT:
      cout << "RIGHT" << endl;
      break;
    case Direction::UP:
      cout << "UP" << endl;
      break;
    case Direction::STUN:
      cerr << "No move selected, STUNNING..." << endl;
      cout << "STUN" << endl;
      break;
  }
}

enum class Cell {
  EMPTY,
  HURDLE
};

class Track
{
public:
  bool game_over_;

  int track_id_;
  string track_ascii_;
  vector<Cell> track_;
  int player_penalty_;
  int player_pos_;
  int player_place_;
  vector<int> next_moves; // Score for each move(direction)

  map<Direction, int> move_score_ = {
    {Direction::LEFT, 1},
    {Direction::DOWN, 2},
    {Direction::RIGHT, 3},
    {Direction::UP, 2},
    {Direction::STUN, -6}
  };
  
  Track(int id) {
    game_over_ = false;

    track_id_ = id;
    track_ascii_ = "";
    player_pos_ = 0;
    player_penalty_ = 0;
    track_ = vector<Cell>(track_ascii_.size());
  }

  void update(string track_ascii, int player_pos, int player_penalty){
    track_ascii_ = track_ascii;
    player_pos_ = player_pos;
    player_penalty_ = player_penalty;
    track_ = vector<Cell>(track_ascii.size());
    for (int i = 0; i < track_ascii.size(); i++) {
      if (track_ascii[i] == '.')
        track_[i] = Cell::EMPTY;
      else
        track_[i] = Cell::HURDLE;
    }
    if (track_ascii == "GAME_OVER") {
      game_over_ = true;
      player_penalty_ = 1;
      player_pos_ = 0;
    } else {
      game_over_ = false;
    }
  }

  /**
   * Update player's place according to other players
   * @param player_2_pos: player 2 position
   * @param player_3_pos: player 3 position
   * @note 1 = 1st place, 2 = 2nd place, 3 = 3rd place
   */
  void update_place(int player_2_pos, int player_3_pos) {
    if (game_over_) {
      player_place_ = 1;
      return;
    }
    if (player_pos_ < player_2_pos && player_pos_ < player_3_pos)
      player_place_ = 3;
    else if (player_pos_ > player_2_pos && player_pos_ > player_3_pos)
      player_place_ = 1;
    else
      player_place_ = 2;
  }

  void Print() {
    if (game_over_) {
      cerr << "xxxxxxxxxxxxxxxx[GAME OVER]xxxxxxxxxxxxxxxx" << endl;
    }
    for (int i = 0; i < track_ascii_.size(); i++) {
      if (i == player_pos_ && player_penalty_ == 0) {
        cerr << 'P';
      } else if (i == player_pos_ && player_penalty_ > 0) {
        cerr << 'X';
      } else if (track_[i] == Cell::HURDLE) {
        cerr << '#';
      } else {
        cerr << '.';
      }
    }
    cerr << endl;
    cerr << "Next Hurdle: " << Next_Hurdle() << " | ";
    cerr << "Player Pos: " << player_pos_ << " | ";
    cerr << "Player Place: " << player_place_ << " | ";
    cerr << "Player Penalty: " << player_penalty_ ;
    cerr << endl;
    cerr << "Moves: ";
    for (auto it = next_moves.begin(); it != next_moves.end(); ++it) {
      cerr << DirectionToString(static_cast<Direction>(std::distance(next_moves.begin(), it))) << " ";
      cerr << *it << " ";
    }
    cerr << endl;
  }

  /**
   * Returns the next hurdle position from the player's current position
   * @return int: the next hurdle position, track_size if no hurdle is found
   */
  int Next_Hurdle(void) {
    for (int i = 0; this->player_pos_ + i < track_.size(); i++) {
      if (track_[this->player_pos_ + i] == Cell::HURDLE)
        return i;
    }
    return track_.size();
  }

  /**
   * Calculate the next moves for the player
   * @note calcul according to the least next hurdle,
   * also excludes the track with player's in penalty stun,
   * also takes into account the player's position
   */
  void calculate_moves(void) {
    // Reset the next moves
    next_moves.clear();
    // Loop through each move and calculate the next move score for each track
    for (Direction dir = Direction::LEFT; 
      dir != Direction::STUN; 
      dir = static_cast<Direction>(static_cast<int>(dir) + 1))
    {
      int total_score = 0;
      // Standard move
      if (player_penalty_ == 0 && dir != Direction::UP ) {
        if (Next_Hurdle() > move_score_[dir]){
          total_score += move_score_[dir];
        } else {
          total_score += move_score_[Direction::STUN];
        }
      } // Jump move
      else if (player_penalty_ == 0 && dir == Direction::UP ) {
        if (Next_Hurdle() == 1){
          total_score += move_score_[dir];
        } else if (Next_Hurdle() > 2) {
          total_score += move_score_[dir];
        } else {
          total_score += move_score_[Direction::STUN];
        }
      }
      next_moves.push_back(total_score);
    }
    // // Select the move with the highest score
    // auto max_score = max_element(next_moves.begin(), next_moves.end());
    // // find the index of the max score
    // auto max_index = distance(next_moves.begin(), max_score);
  };
};

int main()
{
  // Player ID
  int player_idx;
  cin >> player_idx; cin.ignore();
  // Number of mini-games running simultaneously
  int nb_games;
  cin >> nb_games; cin.ignore();

  // Init Objects
  Track track(0);

  // game loop
  while (1) {
    for (int i = 0; i < 3; i++) {
      // Current player's score: 
      string score_info; // final_score, nb_gold_medals, nb_silver_medals, nb_bronze_medals
      getline(cin, score_info);
    }
    for (int i = 0; i < nb_games; i++) {
      string gpu;
      int reg_0; 
      int reg_1; 
      int reg_2;
      int reg_3;
      int reg_4; 
      int reg_5;
      int reg_6;
      cin
        >> gpu
        >> reg_0 >> reg_1 >> reg_2 >> reg_3
        >> reg_4 >> reg_5 >> reg_6; cin.ignore();
      
      cerr << "-----------------------[Game " << i << " Infos]-----------------------" << endl;
      if (i == 0) {
        cerr << "====================[Hurdle Race]====================" << endl;
        track.update(gpu, reg_0, reg_3);
        track.update_place(reg_1, reg_2);
        track.calculate_moves();
        track.Print();
      }
    }
    /* =============[ End of Game Loop ]============= */

    // Select the move with the highest score
    auto max_score = max_element(track.next_moves.begin(), track.next_moves.end());
    // find the index of the max score
    auto max_index = distance(track.next_moves.begin(), max_score);
    Move(static_cast<Direction>(max_index));
  }
}

/* ============================ Game Rules ============================ */
/*
Actions: LEFT, DOWN, RIGHT, UP
- Write an action using cout. DON'T FORGET THE "<< endl"

Debug:
- To debug: cerr << "Debug messages..." << endl;
*/

/* ========================= Context of Hurdle Race ========================= */
/*
Play multiple runs of the Hurdle Race mini-game against two other players.
To play, print either LEFT, DOWN, RIGHT, UP on each turn.
- LEFT: Move forward by 1 cell
- DOWN: Move forward by 2 cells
- RIGHT: Move forward by 3 cells
- UP: jump over one space, 
  ignoring any hurdle on the next space and moving by 2 spaces total.

⚡ One Action is done in for every simultaneous games at the same time. ⚡

Params:
- Track: ASCII representation of the race track
- Player's position in the track
- Player's penalty: 0 = no stun, 1 = 1 turn stun, 2 = 2 turn stun, 3 = 3 turn stun

- string gpu : ASCII representation of race track : 
  .....#...#...#................
  '.' = empty cell, '#' = hurdle
  "GAME_OVER", reset of race

- line of 6 integers:
  Players' positions and penalties
  Unused register = -1
  int reg_0; // Player 1 position
  int reg_3; // Player 1 penalty

  int reg_1; // Player 2 position
  int reg_4; // Player 2 penalty

  int reg_2; // Player 3 position
  int reg_5; // Player 3 penalty

  int reg_6; // Unused

Constraints:
- 100 turns
- race track: 30 cells long
- Collision with a hurdle will result in a 3 turn penalty.
- 3 Players
- 1 to 4 Games running simultaneously

Environment:
- race track is 30 cells long
- player starts at cell 0
- when a player reaches cell 30, the race end - then the game restarts

Scoring:
- According to the position of the player at the end of each race for 100 turns
  TotalScore = nb_gold_medals * 3 + nb_silver_medals
*/