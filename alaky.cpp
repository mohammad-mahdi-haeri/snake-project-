#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

#define WIGHT   20
#define HEIGHT  20

#define SNAKE_BODY  'S'
#define FOOD    'F'
#define WALL    '0'
#define BLINKER '.'

#define UP 65
#define	DOWN 66
#define LEFT 68
#define RIGHT 67

void gotoxy(int x,int y)
{
  printf("%c[%d;%df",0x1B,y,x);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <sys/ioctl.h>
#include <termios.h>

bool kbhit()
{
  termios term;
  tcgetattr(0, &term);

  termios term2 = term;
  term2.c_lflag &= ~ICANON;
  tcsetattr(0, TCSANOW, &term2);

  int byteswaiting;
  ioctl(0, FIONREAD, &byteswaiting);

  tcsetattr(0, TCSANOW, &term);

  return byteswaiting > 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Map {
private:
  class Snake {
  public:
    Snake(int _x, int _y) : x (_x), y(_y) {}

    void move(int input) {
      switch (input) {
        case UP:
        --x;
          break;
        case DOWN:
        ++x;
          break;
        case LEFT:
          --y;
          break;
        case RIGHT:
          ++y;
          break;
        default:
          return;
      }
    }
  public:
    int x;
    int y;
    char body = SNAKE_BODY;
  };

  class Food {
  public:
    Food(int _x, int _y) : x (_x), y(_y) {}
  public:
    int x;
    int y;
    char food = FOOD;
  };
public:
  Map() {
    food = new Food(5,5);
    snake = new Snake(10,10);

    for (int i = 0; i < WIGHT; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        if (i == 0 || i == WIGHT - 1 || j == 0 || j == HEIGHT - 1)
          map[i][j] = wall;
        else
          map[i][j] = blinker;
      }
    }
  }

  void update_map() {
    map[food->x][food->y] = food->food;
    map[snake->x][snake->y] = snake->body;
  }

  void print_map() {
    update_map();
    gotoxy(0,0);
    for (int i = 0; i < WIGHT; i++) {
      cout << endl;
      for (int j = 0; j < HEIGHT; j++) {
        cout << map[i][j] << ' ';
      }
    }
    cout << endl;
  }

  void move_in_map(int input) {
    snake->move(input);
    reset_map();
    print_map();
  }

  void reset_map() {
    for (int i = 0; i < WIGHT; i++) {
      for (int j = 0; j < HEIGHT; j++) {
        if (i == 0 || i == WIGHT - 1 || j == 0 || j == HEIGHT - 1)
          map[i][j] = wall;
        else
          map[i][j] = blinker;
      }
    }
  }

public:
  char map[WIGHT][HEIGHT];
  char wall = WALL;
  char blinker = BLINKER;
  Snake *snake;
  Food *food;
};

int main(int argc, char const *argv[]) {
  Map map;
  map.print_map();

  int input;


  return 0;
}
