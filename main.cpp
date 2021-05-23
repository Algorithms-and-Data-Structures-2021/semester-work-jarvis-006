#include <iostream>
#include "vector"
#include "cstdio"
#include "algorithm.hpp"

using namespace std;
using namespace itis;

int main(){
  vector<point> input_;
    input_.resize(5);
    vector<point> ans;
    input_[0].x = 0;
  input_[1].x = 1;
  input_[2].x = 2;
  input_[3].x = 3;
  input_[4].x = 2;
  input_[0].y = 0;
  input_[1].y = 1;
  input_[2].y = 2;
  input_[3].y = 0;
  input_[4].y = -1;
    ans = itis::Jarvis(input_, 5);
    ans.pop_back();
    for (point i: ans){
      cout << i.x << '\t' << i.y << '\n';
    }


    return 0;
}