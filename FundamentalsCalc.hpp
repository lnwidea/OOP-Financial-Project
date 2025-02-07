#ifndef FUNDAMENTALSCALC_HPP
#define FUNDAMENTALSCALC_HPP
#include <string>
using namespace std;

class FundamentalsCalculator {
   
public:
    FundamentalsCalculator(const string &ticker, double price, double 
dividend);
    ~FundamentalsCalculator();
    FundamentalsCalculator(const FundamentalsCalculator &);
    FundamentalsCalculator &operator=(const FundamentalsCalculator&);

    void setNumOfShares();
    void setEarnings();
    void setExpectedEarnings();
    void setBookValue();
    void setAssets();
    void setLiabilitiesAndIntangibles();
    void setEpsGrowth();
    void setNetIncome();
    void setShareHoldersEquity();
    double PE();
    double forwardPE();
    double bookValue();
    double priceToBookRatio();
    double priceEarningsToGrowth();
    double returnOnEquity();
    double getDividend();
private:
    string m_ticker;
    double m_price;
    double m_dividend;
    double m_earningsEstimate;
    int m_numShares;
    double m_earnings;
    double m_bookValue;
    double m_assets;
    double m_liabilitiesAndIntangibles;
    double m_epsGrowth;
    double m_netIncome;
    double m_shareholdersEquity;
};
#endif \\FundamentalsCalc_hpp