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
const string path_to_project = "K:\\c++ projects\\semester-work-jarvis-006";

// абсолютный путь до набора данных и папки проекта
static const auto kDatasetPathAdd = path_to_project + "\\dataset\\data\\";


//100, 1000, 5000, 10000, 25000, 50000, 100000, 300000, 600000, 1000000
static const int kSizeDataset = 1000;


int main() {
  // работа с набором данных
  string path = kDatasetPathAdd;

  for (int i = 1; i <= 10; i++) { // для каждого из 10 наборов(папки: 01, 02, 03 и т.д.)

    auto input_file = ifstream(path + "data_" + to_string(i) + "\\" + to_string(kSizeDataset) + ".csv");
    if (!input_file.is_open()) {
      cout << "open " << path + "data_" + to_string(i) + "\\" + to_string(kSizeDataset) + ".csv"
           << " error!" << endl;
      return -1;  // если файл не открылся, выводим ошибку
    }

    vector<point> input_{kSizeDataset};
    int j = 0;
    while (!input_file.eof()) {
      string line;
      input_file >> line;
      vector<int> vect;

      std::stringstream ss(line);
      if (line.size() == 0)
        break;
      for (int k; ss >> k;) {
        vect.push_back(k);
        if (ss.peek() == ',')
          ss.ignore();
      }
      input_[j].x = vect[0];
      input_[j].y = vect[1];
      j += 1;
    }
    //======================================Алгоритм=======================================================
    vector<point> ans;
    auto time_point_before = chrono::steady_clock::now();

    ans = Jarvis(input_, kSizeDataset);

    auto time_point_after = chrono::steady_clock::now();
    auto time_diff = time_point_after - time_point_before;
    long long time_elapsed_ns_search = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
//    cout << ans.size() << '\n';
    //===================================================================================================
    cout << time_elapsed_ns_search << "\n";
  }
  return 0;

}

