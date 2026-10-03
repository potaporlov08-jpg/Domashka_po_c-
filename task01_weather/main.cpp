#include <iostream>
#include <iomanip>

double midle_temp(const int* arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += arr[i];
  }
  return static_cast<double>(sum) / n;
}

void minmax(const int* arr, int n, int& mi, int& ma) {
  mi = arr[0];
  ma = arr[0];
  for (int i = 1; i < n; ++i) {
    if (arr[i] < mi) {
      mi = arr[i];
    }
    if (arr[i] > ma) {
      ma = arr[i];
    }
  }
}

int cold_days(const int* arr, int n) {
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      ++c;
    }
  }
  return c;
}



int main() {
  int n;
  std::cin >> n;
  int* temp = new int[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> temp[i];
  }

  std::cout << std::fixed << std::setprecision(1) << midle_temp(temp, n) << "\n";
  int mi;
  int ma;
  minmax(temp, n, mi, ma);
  std::cout << mi << " " << ma << "\n";
  std::cout << cold_days(temp, n) << "\n";


  delete[] temp;
  return 0;
}
