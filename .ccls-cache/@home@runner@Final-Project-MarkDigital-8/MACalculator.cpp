#include "MACalculator.hpp"
#include <iostream>
using namespace std;
MaCal::MaCal(int numPeriods)
: m_numPeriods(numPeriods)
{
}
MaCal::~MaCal()
{
}
MaCal::MaCal(const MaCal &ma)
: m_numPeriods(ma.m_numPeriods)
{
}
MaCal &MaCal::operator = (const MaCal &ma)
{
  if (this != &ma)
  {
    m_numPeriods = ma.m_numPeriods;
    m_prices = ma.m_prices;
  }
  return *this;
}
vector<double> MaCal::calculateMA()
{
  vector<double> ma;
  double sum = 0;
  for (int i=0; i<m_prices.size(); ++i)
  {
    sum += m_prices[i];
    if (i >= m_numPeriods)
    {
      ma.push_back(sum / m_numPeriods);
      sum -= m_prices[i-m_numPeriods];
    }
  }
  return ma; 
}
vector<double> MaCal::calculateEMA()
{
  vector<double> ema;
  double sum = 0;
  double multiplier = 2.0 / (m_numPeriods + 1);
  for (int i=0; i<m_prices.size(); ++i)
  {
    sum += m_prices[i];
    if (i == m_numPeriods)
    {
      ema.push_back(sum / m_numPeriods);
      sum -= m_prices[i-m_numPeriods];
    }
    else if (i > m_numPeriods)
    {
      double val = (1-multiplier) * ema.back() + multiplier * m_prices[i];
      ema.push_back(val);
    } 
  }
  return ema; 
}
void MaCal::addPrice(double close)
{
    m_prices.push_back(close);
}