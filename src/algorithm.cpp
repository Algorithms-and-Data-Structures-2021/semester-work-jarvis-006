#include "algorithm.hpp"

// файл с определениями
using namespace std;
namespace itis {

  vector<point> Jarvis(vector<point> input_data, int n) {
    vector<point> picked_points;
    // находим самую левую из самых нижних
    int base = 0;
    for (int i = 1; i < n; i++) {
      if (input_data[i].y < input_data[base].y) {
        base = i;
      } else if (input_data[i].y == input_data[base].y && input_data[i].x < input_data[base].x)
        base = i;
    }
    // по смыслу алгоритма она обязательно входит в оболочку
    picked_points.push_back(input_data[base]);

    int cur = base;
    do {
      int next = (cur + 1) % n;
      for (int i = 0; i < n; i++) {
        int sign = input_data[cur].x * (input_data[next].y - input_data[i].y)
                   + input_data[next].x * (input_data[i].y - input_data[cur].y)
                   + input_data[i].x * (input_data[cur].y - input_data[next].y);

        // точка i находится левее прямой cur, next
        if (sign < 0)
          next = i;
        // точка лежит на прямой, образованной точками cur, next
        else if (sign == 0) {
          // точка i находится дальше, next от cur
          if (input_data[cur].x <= input_data[next].x && input_data[next].x <= input_data[i].x
              && input_data[cur].y <= input_data[next].y && input_data[next].y <= input_data[i].y)
            next = i;
        }
        // точки лежащие правее прямой cur - next нас не интересуют, так как обоболочка становится не
        // выпуклой
      }
      cur = next;
      picked_points.push_back(input_data[next]);
    } while (cur != base);

    return picked_points;
  }
}// namespace itis