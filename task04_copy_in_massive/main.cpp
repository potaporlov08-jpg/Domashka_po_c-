/*
Программа хранит несколько игровых полей (2D-массивов) и копирует одно из них
в универсальное хранилище — как будто сохраняет в файл.

int*** нужен, чтобы держать массив 2D-массив: один массив — это int**,
а список таких карт — уже int***. Без трёх звёздочек пришлось бы
использовать трёхмерность через один массив с ручной индексацией.

void* нужен для сырого хранилища памяти.
*/

#include <iostream>

int main() {
  const int MAPS_COUNT = 2, ROWS = 2, COLS = 3;

  int*** maps = new int**[MAPS_COUNT];
  for (int m = 0; m < MAPS_COUNT; ++m) {
    maps[m] = new int*[ROWS];
    for (int r = 0; r < ROWS; ++r) {
      maps[m][r] = new int[COLS];
      for (int c = 0; c < COLS; ++c) {
        maps[m][r][c] = (m + 1) * 10 + r + c;
      }
    }
  }

  std::cout << "Исходное поле 0:" << "\n";
  for (int r = 0; r < ROWS; ++r) {
    for (int c = 0; c < COLS; ++c) std::cout << maps[0][r][c] << " ";
    std::cout << "\n";
  }

  size_t size = ROWS * COLS * sizeof(int);
  void* saving = new char[size];

  int* buffer_as_int = static_cast<int*>(saving);
  int idx = 0;
  for (int r = 0; r < ROWS; ++r)
    for (int c = 0; c < COLS; ++c) buffer_as_int[idx++] = maps[0][r][c];

  std::cout << "\n" << "Данные скопированы в void* хранилище" << "\n";
  std::cout << "Чтение из void* хранилища:" << "\n";

  const int* read_from_buffer = static_cast<const int*>(saving);
  for (int i = 0; i < ROWS * COLS; ++i) std::cout << read_from_buffer[i] << " ";
  std::cout << "\n";

  for (int m = 0; m < MAPS_COUNT; ++m) {
    for (int r = 0; r < ROWS; ++r) delete[] maps[m][r];
    delete[] maps[m];
  }
  delete[] maps;
  delete[] static_cast<char*>(saving);

  return 0;
}