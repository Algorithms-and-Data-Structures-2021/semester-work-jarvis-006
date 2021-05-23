#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>
#include <vector>

// подключаем вашу структуру данных
#include "algorithm.hpp"

using namespace std;
using namespace itis;

// Ваш путь до проекта
const string path_to_project = "C:\\Users\\Mapct\\project\\Study\\semester-work-jarvis-006";

// абсолютный путь до набора данных и папки проекта
static const auto kDatasetPathAdd = path_to_project + "\\dataset\\data\\";


//100, 1000, 5000, 10000, 25000, 50000, 100000, 300000, 600000, 1000000
static const int kSizeDataset = 100;


int main() {
  // работа с набором данных
  string path = kDatasetPathAdd;

  int dataset_array[10] = {100, 1000, 5000, 10000, 25000, 50000, 100000, 300000, 600000, 1000000};

  for (int data: dataset_array) {
    cout << "=============================== " <<"size: " << data << " ============================" << endl;
    for(int iter = 0; iter < 10; iter++) {
      for (int i = 1; i <= 10; i++) { // для каждого из 10 наборов(папки: 01, 02, 03 и т.д.)
        auto input_file = ifstream(path + "data_" + to_string(i) + "\\" + to_string(data) + ".csv");
        if (!input_file.is_open()) {
          cout << "open " << path + "data_" + to_string(i) + "\\" + to_string(data) + ".csv"
               << " error!" << endl;
          return -1;  // если файл не открылся, выводим ошибку
        }

        vector<point> input_;
        while (!input_file.eof()) {
          string line;
          input_file >> line;

          if (line.size() == 0)
            break;

          int n = line.find(",");

          int x_coord = stoi(line.substr(0, n));
          int y_coord = stoi(line.substr(n + 1));

          point p = point(x_coord, y_coord);
          input_.push_back(p);
        }

        //======================================Алгоритм=======================================================
        auto time_point_before = chrono::steady_clock::now();
        vector<point> ans;
        ans = Jarvis(input_, data);
        auto time_point_after = chrono::steady_clock::now();
        auto time_diff = time_point_after - time_point_before;
        long long time_elapsed_ns_search = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
        //===================================================================================================
        cout << time_elapsed_ns_search << "\n";

      }
    }
  }
  return 0;

}