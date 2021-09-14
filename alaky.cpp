#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WIDTH  30
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


void gotoxy(int x,int y) {
  printf("%c[%d;%df",0x1B,y,x);
}


class Map {
public:
  Map() {

    for (int i = 0; i < HEIGHT;  i++) {
      for (int j = 0; j < WIDTH; j++) {
        if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
          map[i][j] = WALL;
        } else {
          map[i][j] = BLINKER;
        }
      }
    }
  }

  void print_map() {
    gotoxy(0,0);
    for (int i = 0; i < HEIGHT; i++) {
      cout << endl;
      for (int j = 0; j < WIDTH; j++) {
        cout << map[i][j] << ' ';
      }
    }
    cout << endl;
  }

public:
  char map[HEIGHT][WIDTH];
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
    map->map[tail.y][tail.x] = tail.character;
    map->map[head.y][head.x] = head.character;
  }

  void move_head(int direction) {
    map->map[head.y][head.x] = tail.character;
    xy_repository.push({head.x, head.y});
    switch (direction) {
      case UP: --head.y;
        break;
      case DOWN: ++head.y;
        break;
      case RIGHT: ++head.x;
        break;
      case LEFT: --head.x;
        break;
      default:
        return;
        break;
    }
    map->map[head.y][head.x] = head.character;
  }

  void move_tail() {
    int _x = xy_repository.front().first;
    int _y = xy_repository.front().second;
    xy_repository.pop();
    map->map[_y][_x] = BLINKER;
  }

private:
  Map_cell head;
  Map_cell tail;
  Map *map;
  queue<pair<int, int>> xy_repository;
};


class Food {
public:
  Food(int x, int y, Map *_map) : food(Map_cell(x, y, FOOD)) {
    map = _map;
  }

  void update_food() {
    map->map[food.y][food.x] = food.character;
  }

private:
  Map_cell food;
  Map *map;
};

class Game_contorol {
public:
  Game_contorol(int x_snake, int y_snake, int x_food, int y_food) : snake(Snake(x_snake, y_snake, &map)), food(Food(x_food, y_food, &map)) {
    food.update_food();
    snake.move_head(LEFT);
    snake.move_head(UP);
    snake.move_tail();
    snake.move_head(UP);
    snake.move_tail();
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
