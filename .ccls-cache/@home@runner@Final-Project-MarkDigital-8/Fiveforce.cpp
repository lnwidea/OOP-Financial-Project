#include "Fiveforce.hpp"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

Fiveforce::Fiveforce(float q1,  float q2, float q3 , float q4, float q5, float q6):
  m_q1(q1),
  m_q2(q2),
  m_q3(q3),
  m_q4(q4),
  m_q5(q5),
  m_q6(q6)
{
}

double Fiveforce::countscore() 
{
  sum = m_q1 + m_q2 + m_q3 + m_q4 + m_q5 + m_q6;
  return sum;
}

void Fiveforce::evaluation(float x, float y) 
{
  m_count.count(x, y, sum);
  
}

