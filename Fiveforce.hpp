#ifndef FIVEFORCE_HPP
#define FIVEFORCE_HPP
#include <string>
#include "question.hpp"
using namespace std;

class Fiveforce{
public:
  Fiveforce(float q1,  float q2, float q3 , float q4, float q5, float q6);
  double countscore();
  void evaluation(float x, float y);
  float sum;
private:
  float m_q1,m_q2,m_q3, m_q4 , m_q5, m_q6;
  float m_high,m_current;
  Count m_count;
};
#endif