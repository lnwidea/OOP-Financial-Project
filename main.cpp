#include "VolatilityCalculator.hpp"
#include "MACalculator.hpp"
#include <iostream>
using namespace std;

// the main function receives parameters passed to the program
int main(int argc, const char *argv[]) {
  int choose;
  cout << "num";
  cin >> choose;
  if (choose == 1) {
    cout << "volatility";
    double price;
    VolatilityCalculator vc;
    for (;;) {
      cin >> price;
      if (price == -1) {
        break;
      }
      vc.addPrice(price);
    }
    cout << "range volatility is " << vc.rangeVolatility() << endl;
    cout << "average daily range is " << vc.avgDailyRange() << endl;
    cout << "standard deviation is " << vc.stdDev() << endl;
    return 0;
  } 
  else if (choose == 2) {
    cout << "MA";
    if (argc != 2) {
      std::cout << "usage: progName <num periods>" << std::endl;
      return 1;
    }
    int num_periods = atoi(argv[1]);
    double price;
    MACalculator calculator(num_periods);
    for (;;) {
      std::cin >> price;
      if (price == -1)
        break;
      calculator.addPriceQuote(price);
    }
    std::vector<double> ma = calculator.calculateMA();
    for (int i = 0; i < ma.size(); ++i) {
      std::cout << "average value " << i << " = " << ma[i] << std::endl;
    }
    std::vector<double> ema = calculator.calculateEMA();
    for (int i = 0; i < ema.size(); ++i) {
      std::cout << "exponential average value " << i << " = " << ema[i]
                << std::endl;
    }
    return 0;
  }
}
