#pragma once
#include "vector"

// Заголовочный файл с объявлением структуры данных

namespace itis {

  struct point
  {
    int x,y;
    point(){}
    explicit point(int coord_x, int coord_y)
    {
      x = coord_x;
      y = coord_y;
    }
  };

  std::vector<point> Jarvis(std::vector<point> input_data, int n);

}  // namespace itis