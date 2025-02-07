#ifndef MACALCULATOR_HPP
#define MACALCULATOR_HPP
#include <vector>
#include "Calc.hpp"
using namespace std;

class MaCal : public Calc {
public:
    MaCal(int period);
    MaCal(const MaCal &);
    MaCal &operator = (const MaCal &);
    ~MaCal();
    void addPrice(double close);
    vector<double> calculateMA();
    vector<double> calculateEMA();

private:
    int m_numPeriods;
    vector<double> m_prices;
};
#endif // MACalculator_hpp