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
  Map() {

    for (int i = 0; i < WIDTH;  i++) {
      for (int j = 0; j < HEIGHT; j++) {
        if (i == 0 || i == WIDTH - 1 || j == 0 || j == HEIGHT - 1){
          map[i][j] = WALL;
        } else {
          map[i][j] = BLINKER;
        }
      }
    }
  }

  void print_map() {
    for (int i = 0; i < HEIGHT; i++) {
      cout << endl;
      for (int j = 0; j < WIDTH; j++) {
        cout << map[i][j] << ' ';
      }
    }
  }

public:
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

public:
  int x;
  int y;
  char character;
};


class Snake {
public:
  Snake(int x, int y, Map *_map) : head(Map_cell(x, y, HEAD)), tail(Map_cell(x, y, BODY)) {
    map = _map;
  }
  void update_snake() {
    map->map[tail.x][tail.y] = tail.character;
    map->map[head.x][head.y] = head.character;
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

  void update_food() {
    map->map[food.x][food.y] = food.character;
  }

private:
  Map_cell food;
  Map *map;
};

class Game_contorol {
public:
  Game_contorol(int x_snake, int y_snake, int x_food, int y_food) : snake(Snake(x_snake, y_snake, &map)), food(Food(x_food, y_food, &map)) {
    food.update_food();
    snake.update_snake();
    map.print_map();
  }


private:
  Map map;
  Snake snake;
  Food food;
};

int main(int argc, char const *argv[]) {
  Game_contorol game(10,10,5,5);
  return 0;
}
