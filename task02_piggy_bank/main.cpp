#include <iostream>
#include <cstring>

void deposit(int& balance, int k) {
  if (k > 0) {
    balance += k;
  }
  else {
    std::cout << "error\n";
  }
}
void withdraw(int& balance, int k) {
  if (k > 0 && balance >= k) {
    balance -= k;
  }
  else {
    std::cout << "error\n";
  }
}
void balance(int& balance, int) {
  std::cout << balance << "\n";
}
void reset(int& balance, int) {
  balance = 0;
}
void inc(int& balance, int) {
  balance += 1;
}
int main() {
  const char* names[] = { "deposit", "withdraw", "balance", "reset", "inc" };
  void (*funcs[])(int&, int) = { deposit, withdraw, balance, reset, inc };
  int size = 5;

  int balance = 0;
  char comands[32];
  while (std::cin >> comands) {
    if (std::strcmp(comands, "stop") == 0) {
      break;
    }
    int arg = 0;
    if (std::strcmp(comands, "deposit") == 0 || std::strcmp(comands, "withdraw") == 0) {
      std::cin >> arg;
    }
    bool found = false;
    for (int i = 0; i < size; ++i) {
      if (std::strcmp(comands, names[i]) == 0) {
        funcs[i](balance, arg);
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "error\n";
    }
  }
  return 0;
}