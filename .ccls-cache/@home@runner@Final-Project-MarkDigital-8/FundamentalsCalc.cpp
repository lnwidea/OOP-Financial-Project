#include "FundamentalsCalc.hpp"
#include <iostream>
using namespace std;

FundamentalsCalculator::FundamentalsCalculator(const string &ticker, double price, double dividend)
  : m_ticker(ticker), m_price(price), m_dividend(dividend),
    m_earningsEstimate(0), m_numShares(0), m_bookValue(0), m_assets(0),
    m_liabilitiesAndIntangibles(0), m_epsGrowth(0), m_netIncome(0),
    m_shareholdersEquity(0) 
{
}

FundamentalsCalculator::FundamentalsCalculator(const FundamentalsCalculator &v)
    : m_ticker(v.m_ticker), m_price(v.m_price), m_dividend(v.m_dividend),
      m_earningsEstimate(v.m_earningsEstimate), m_numShares(v.m_numShares),
      m_bookValue(v.m_bookValue), m_assets(v.m_assets),
      m_liabilitiesAndIntangibles(v.m_liabilitiesAndIntangibles),
      m_epsGrowth(v.m_epsGrowth), m_netIncome(v.m_netIncome),
      m_shareholdersEquity(v.m_shareholdersEquity) 
{
}

FundamentalsCalculator::~FundamentalsCalculator() 
{
}

FundamentalsCalculator &
FundamentalsCalculator::operator=(const FundamentalsCalculator &v) 
{
  if (this != &v) 
  {
    m_ticker = v.m_ticker;
    m_price = v.m_price;
    m_dividend = v.m_dividend;
    m_earningsEstimate = v.m_earningsEstimate;
    m_numShares = v.m_numShares;
    m_bookValue = v.m_bookValue;
    m_assets = v.m_assets;
    m_liabilitiesAndIntangibles = v.m_liabilitiesAndIntangibles;
    m_epsGrowth = v.m_epsGrowth;
    m_netIncome = v.m_netIncome;
    m_shareholdersEquity = v.m_shareholdersEquity;
  }
  return *this;
}

double FundamentalsCalculator::PE() 
{
  return (m_price * m_numShares) / m_earnings;
}

double FundamentalsCalculator::forwardPE() 
{
  return (m_price * m_numShares) / m_earningsEstimate;
}

double FundamentalsCalculator::returnOnEquity() 
{
  return m_netIncome / m_shareholdersEquity;
}

double FundamentalsCalculator::getDividend() 
{ 
  return m_dividend; 
}

double FundamentalsCalculator::bookValue() 
{ 
  return m_bookValue; 
}

double FundamentalsCalculator::priceToBookRatio() 
{
  return (m_price * m_numShares) / (m_assets - m_liabilitiesAndIntangibles);
}

double FundamentalsCalculator::priceEarningsToGrowth() 
{
  return PE() / m_epsGrowth;
}

void FundamentalsCalculator::setNumOfShares() 
{ 
  int n;
  cout << "Input number of shares: ";
  cin >> n;
  m_numShares = n; 
}

void FundamentalsCalculator::setEarnings() 
{ 
  double val;
  cout << "Input earnings: ";
  cin >> val;
  m_earnings = val; 
}

void FundamentalsCalculator::setExpectedEarnings() 
{
  double val;
  cout << "Input earnings estimate: ";
  cin >> val;
  m_earningsEstimate = val;
}

void FundamentalsCalculator::setBookValue() 
{ 
  double val;
  cout << "Input book value: ";
  cin >> val;
  m_bookValue = val; 
}

void FundamentalsCalculator::setEpsGrowth() 
{ 
  double val;
  cout << "Input Earnings Per Share Growth: ";
  cin >> val;
  m_epsGrowth = val; 
}

void FundamentalsCalculator::setNetIncome() 
{ 
  double val;
  cout << "Input net income: ";
  cin >> val;
  m_netIncome = val; 
}

void FundamentalsCalculator::setShareHoldersEquity() 
{
  double val;
  cout << "Input shareholders equity: ";
  cin >> val;
  m_shareholdersEquity = val;
}

void FundamentalsCalculator::setLiabilitiesAndIntangibles() 
{
  double val;
  cout << "Input liabilities and intangibles: ";
  cin >> val;
  m_liabilitiesAndIntangibles = val;
}

void FundamentalsCalculator::setAssets() 
{ 
  double val;
  cout << "Input assets: ";
  cin >> val;
  m_assets = val; 
}
