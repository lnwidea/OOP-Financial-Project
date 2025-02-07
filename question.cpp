#include "question.hpp"
#include "Fiveforce.hpp"
#include <iostream>

using namespace std;

void Count::count(float x, float y, float sum){
  m_high = x;
  m_current = y;
  
  if (m_high * (sum/10)  >=  m_current) 
  {
    cout << "\nBuy\n";
  } 
  else 
  {
    cout << "\nHold\n";
  }
}