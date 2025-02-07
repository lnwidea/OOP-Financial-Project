#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <string>
using namespace std;

class Count {
  public:
    void count(float x, float y, float sum);
  private:
    float m_high,m_current;
};

#endif //question_HPP