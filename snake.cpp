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
  Map() {
    food = new Food(5,5);
    Snake *new_snake = new Snake(10,10);
    first_snake = new_snake;
    last_snake = new_snake;

    for (int i = 0; i < WIGHT; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        if (i == 0 || i == WIGHT - 1 || j == 0 || j == HEIGHT - 1)
          map[i][j] = WALL;
        else
          map[i][j] = BLINKER;
      }
    }
    update_map();
  }

  void print_map() {
    update_map();
    for (int i = 0; i < WIGHT; i++) {
      cout << endl;
      for (int j = 0; j < HEIGHT; j++) {
        cout << map[i][j] << ' ';
      }
    }
    cout << endl;
  }

  void add_snake(int x, int y) {
    Snake *new_snake = new Snake(x, y);
    last_snake->next = new_snake;
    new_snake->prev = last_snake;
    last_snake = new_snake;
  }

  void update_map() {
    map[food->x][food->y] = food->food;
    Snake *current = first_snake;
    while (current != NULL) {
      map[current->x][current->y] = current->snake_head;
      current = current->next;
    }
  }

private:
  class Snake {
  public:
    Snake(int _x, int _y) {
      x = _x;
      y = _y;
      next = NULL;
      prev = NULL;
    }

    int x;
    int y;
    char snake_head = SNAKE;
    Snake *next;
    Snake *prev;
  };

  class Food {
  public:
    Food(int _x, int _y) {
      x = _x;
      y = _y;
    }
    char food = FOOD;
    int x;
    int y;
  };

  char map[WIGHT][HEIGHT];
  Snake *first_snake;
  Snake *last_snake;
  Food *food;

};

int main(int argc, char const *argv[]) {
  Map map;
  map.print_map();
  return 0;
}
