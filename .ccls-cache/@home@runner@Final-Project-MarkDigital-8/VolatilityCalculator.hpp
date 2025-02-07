#ifndef VOLATILITYCALCULATOR_HPP
#define VOLATILITYCALCULATOR_HPP
#include <vector>
#include "Calc.hpp"
using namespace std;


class Volcal : public Calc {
public:
 Volcal();
 ~Volcal();
 Volcal(const Volcal &);
 Volcal &operator=(const Volcal &);
 void addPrice(double price);
 double rangeVolatility();
 double stdDev();
 double mean();
 double avgDailyRange();

private:
 vector<double> m_prices;
};
#endif //Volcal_hpp