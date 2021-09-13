#include <iostream>

using namespace std;

#define WIGHT   20
#define HEIGHT  20

#define SNAKE   'S'
#define FOOD    'F'
#define WALL    '0'
#define BLINKER '.'

#define UP 65
#define	DOWN 66
#define LEFT 68
#define RIGHT 67

class Map {
public:
  Map() {}

  void print_map() {
    for (int i = 0; i < height; i++) {
      cout << endl;
      for (int j = 0; j < width; j++) {
        cout << map[i][j] << ' ';
      }
    }
  }

private:
  char map[WIDTH][HEIGHT];
  char wall = WALL;
  char blinker = BLINKER;
};

int main(int argc, char const *argv[]) {

  return 0;
}
