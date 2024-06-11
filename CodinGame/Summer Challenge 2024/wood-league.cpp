#include <iostream>
#include <string>
#include <vector>
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
  UP
};

enum class Cell {
  EMPTY,
  HURDLE
};

class Track
{
public:
  int track_id_;
  string track_ascii_;
  vector<Cell> track_;
  int player_penalty_;
  int player_pos_;
  int player_place_;
  
  Track(int id) {
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
  }

  /**
   * Update player's place according to other players
   * @param player_2_pos: player 2 position
   * @param player_3_pos: player 3 position
   * @note 1 = 1st place, 2 = 2nd place, 3 = 3rd place
   */
  void update_place(int player_2_pos, int player_3_pos) {
    if (player_pos_ < player_2_pos && player_pos_ < player_3_pos)
      player_place_ = 3;
    else if (player_pos_ > player_2_pos && player_pos_ > player_3_pos)
      player_place_ = 1;
    else
      player_place_ = 2;
  }

  void Print() {
    cerr << "===========[Track " << track_id_ << "]===========" << endl;
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
    cerr << "Player Pos: " << player_place_ << " | ";
    cerr << "Player Penalty: " << player_penalty_ ;
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
   * Move the player according to the distance
   * @param distance: the distance to move
   */
  static void Move(int distance){
    switch (distance) {
      case 0:
        cout << "UP" << endl;
        break;
      case 1:
        cout << "UP" << endl;
        break;
      case 2:
        cout << "LEFT" << endl;
        break;
      case 3:
        cout << "DOWN" << endl;
        break;
      default:
        cout << "RIGHT" << endl;
        break;
    }
  }

  // Help choose between tracks which one to prioritize based on next hurdle
  /**
   * Choose which track to priority
   * @param tracks: the list of tracks to choose from
   * @note choose the track with the least next hurdle,
   *      also excludes the track with player's in penalty stun,
   *      also takes into account the player's position
   * !TODO: Update to take into account the player's position and other parameters
   * !TODO: Make move from this function
   */
  static int Priority_Direction(vector<Track> tracks) {
    vector<int> next_hurdles;
    for (auto &track : tracks) {
      if (track.player_penalty_ > 0)
        continue;
      next_hurdles.push_back(track.Next_Hurdle());
    }
    return distance(next_hurdles.begin(), min_element(next_hurdles.begin(), next_hurdles.end()));
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
  vector<Track> tracks;
  for (int i = 0; i < nb_games; i++) {
    tracks.push_back(Track(i));
  }

  // game loop
  while (1) {
    for (int i = 0; i < 3; i++) {
      // Current player's score: 
      // final_score, nb_gold_medals, nb_silver_medals, nb_bronze_medals
      string score_info;
      getline(cin, score_info);
    }
    for (int i = 0; i < nb_games; i++) {
      // RaceTrack in ASCII representation: .....#...#...#................
      // '.' = empty cell, '#' = hurdle
      // "GAME_OVER", reset of race
      string gpu;

      // Players' positions and penalties
      // Stun: 0 = no stun, 1 = 1 turn stun, 2 = 2 turn stun, 3 = 3 turn stun
      // Unused register = -1
      int reg_0; // Player 1 position
      int reg_3; // Player 1 penalty

      int reg_1; // Player 2 position
      int reg_4; // Player 2 penalty

      int reg_2; // Player 3 position
      int reg_5; // Player 3 penalty

      int reg_6; // Unused
      cin
        >> gpu
        >> reg_0 >> reg_1 >> reg_2 >> reg_3
        >> reg_4 >> reg_5 >> reg_6; cin.ignore();
      auto &track = tracks[i];
      track.update(gpu, reg_0, reg_3);
      track.update_place(reg_1, reg_2);
      track.Print();
    }
    Track::Move(Track::Priority_Direction(tracks));
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
  }
}

/* ========================= Context of Wood League ========================= */
/*
Play multiple runs of the Hurdle Race mini-game against two other players.
To play, print either LEFT, DOWN, RIGHT, UP on each turn.
- LEFT: Move forward by 1 cell
- DOWN: Move forward by 2 cells
- RIGHT: Move forward by 3 cells
- UP: jump over one space, 
  ignoring any hurdle on the next space and moving by 2 spaces total.

⚡ One Action is done in for every simultaneous games at the same time. ⚡

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
