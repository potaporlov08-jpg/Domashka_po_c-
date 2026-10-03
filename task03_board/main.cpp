#include <cstring>
#include <iostream>

const int cR = 5;
const int cC = 10;

char board[cR][cC];

void clear_board() {
  for (int y = 0; y < cR; ++y) {
    for (int x = 0; x < cC; ++x) {
      board[y][x] = ' ';
    }
  }
}

bool put(int x, int y, char c) {
  if (x < 0 || x >= cC || y < 0 || y >= cR) {
    return false;
  }
  board[y][x] = c;
  return true;
}

bool text(int x, int y, const char* w) {
  int len = std::strlen(w);
  if (y < 0 || y >= cR || x < 0 || x + len > cC) {
    return false;
  }
  for (int i = 0; i < len; ++i) {
    board[y][x + i] = w[i];
  }
  return true;
}

void print_board() {
  for (int y = 0; y < cR; ++y) {
    for (int x = 0; x < cC; ++x) {
      std::cout << board[y][x];
    }
    std::cout << "\n";
  }
}

int main() {
  clear_board();
  char comands[32];
  while (std::cin >> comands) {
    if (std::strcmp(comands, "quit") == 0) {
      break;
    } else if (std::strcmp(comands, "clear") == 0) {
      clear_board();
    } else if (std::strcmp(comands, "print") == 0) {
      print_board();
    } else if (std::strcmp(comands, "put") == 0) {
      int x, y;
      char c;
      std::cin >> x >> y >> c;
      if (put(x, y, c) == false) {
        std::cout << "error\n";
      }
    } else if (std::strcmp(comands, "text") == 0) {
      int x, y;
      char w[32];
      std::cin >> x >> y >> w;
      if (text(x, y, w) == false) {
        std::cout << "error\n";
      }
    }
  }
  return 0;
}