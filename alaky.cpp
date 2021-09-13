#include <iostream>

using namespace std;

#define WIDTH  20
#define HEIGHT 20

#define HEAD 'S'
#define BODY 'O'
#define WALL '0'
#define BLINKER '.'
#define FOOD 'F'

#define UP 65
#define	DOWN 66
#define LEFT 68
#define RIGHT 67

class Map {
public:
  Map() {}

  void print_map() {
    for (int i = 0; i < HEIGHT; i++) {
      cout << endl;
      for (int j = 0; j < WIDTH; j++) {
        cout << map[i][j] << ' ';
      }
    }
  }

private:
  char map[WIDTH][HEIGHT];
  char wall = WALL;
  char blinker = BLINKER;
};

class Map_cell {
public:
  Map_cell(int _x, int _y, char c) {
    x = _x;
    y = _y;
    character = c;
  }

private:
  int x;
  int y;
  char character;
};

class Snake {
public:
  Snake(int x, int y, Map *_map) : head(Map_cell(x, y, HEAD)), tail(Map_cell(x, y, BODY)) {
    map = _map;
  }
private:
  Map_cell head;
  Map_cell tail;
  Map *map;
};

class Food {
public:
  Food(int x, int y, Map *_map) : food(Map_cell(x, y, FOOD)) {
    map = _map;
  }
private:
  Map_cell food;
  Map *map;
};

int main(int argc, char const *argv[]) {

  return 0;
}
