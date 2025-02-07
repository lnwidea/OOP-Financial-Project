#include "Fiveforce.hpp"
#include "FundamentalsCalc.hpp"
#include "MACalculator.hpp"
#include "VolatilityCalculator.hpp"
#include "Calc.hpp"
#include "question.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
  while (1) {
    int choice;
    cout << ("\n\nWelcome to Finanacial Tools System\n\n");
    cout << " 1) EMA" << endl;
    cout << " 2) Volatility" << endl;
    cout << " 3) Fundamental Analysis" << endl;
    cout << " 4) Smart Stock filter using five force model" << endl;
    cout << " 5) Quit\n\n";
    cout << "Enter your choice(number only): ";
    cin >> choice;
    switch (choice) {
    case 1: {
      cout << "\nEMA\n";
      int num_periods;
      cout << "How many points that you want to calculate the moving average: ";
      cin >> num_periods;
      double price_1;
      MaCal calculator(num_periods);
      cout << "Please input the price of your stock at the moment and inuput -1 when finish" << endl << endl;
      for (;;) {
        cin >> price_1;
        if (price_1 == -1)
          break;
        calculator.addPrice(price_1);
      }
      vector<double> ma = calculator.calculateMA();
      for (int i = 0; i < ma.size(); ++i) {
        cout << "Average value " << i << " = " << ma[i] << endl;
      }
      vector<double> ema = calculator.calculateEMA();
      for (int i = 0; i < ema.size(); ++i) {
        cout << "Exponential average value " << i << " = " << ema[i] << endl;
      }
      break;
    }
    case 2: {
      cout << "\nVolatility\n";
      double price;
      Volcal vc;
      cout << "Please input the price of your stock at the moment and inuput -1 when finish" << endl;
      for (;;) {
        cin >> price;
        if (price == -1) {
          break;
        }
        vc.addPrice(price);
      }
      cout << "Range volatility is " << vc.rangeVolatility() << endl;
      cout << "Average daily range is " << vc.avgDailyRange() << endl;
      cout << "Standard deviation is " << vc.stdDev() << endl;
      break;
    }
    case 3: {
      cout << "\nFundamental Analysis\n";
      string name;
      double money, dividend;
      cout << "Input stock name: ";
      cin >> name;
      cin.clear();
      cout << "Input current price: ";
      cin >> money;
      cout << "Input dividend: ";
      cin >> dividend;
      FundamentalsCalculator fc(name, money, dividend);
      fc.setAssets();
      fc.setBookValue();
      fc.setEarnings();
      fc.setEpsGrowth();
      fc.setExpectedEarnings();
      fc.setLiabilitiesAndIntangibles();
      fc.setNetIncome();
      fc.setNumOfShares();
      fc.setShareHoldersEquity();
      cout << "\n\n";
      cout << "P/E: " << fc.PE() / 1000 << endl;
      cout << "Forward P/E: " << fc.forwardPE() / 1000 << endl;
      cout << "Book value: " << fc.bookValue() << endl;
      cout << "Price to book: " << fc.priceToBookRatio() << endl;
      cout << "Price earnings to growth: " << fc.priceEarningsToGrowth() << endl;
      cout << "Return on equity: " << fc.returnOnEquity() << endl;
      cout << "Dividend: " << fc.getDividend() << endl;
      break;
    }
    case 4: {
      cout << "\nSmart Stock filter using five force model\n";
      float q1,q2,q3,q4,q5,q6;
      int h,c;
      cout <<"Answer the following question\n";
      cout <<"If the company the following citeria enter (1) if not enter (0)\n";
      while(true)
      {
        cout << "\n1.Does the company have bargaining power aginst customers: ";
        cin >> q1;
        if (q1 <= 1)
        {
          break;
        }
        cout << "Invalid numbers, try again.";
      }
      while(true)
      {
        cout << "\n2.Does the company have bargaining power against supplier: ";
        cin >> q2;
        if (q2 <= 1)
        {
          break;
        }
        cout << "Invalid numbers, try again.";
      }
      while(true)
      {
        cout <<"\n3.Does business have high barrier of entry: " ;
        cin >> q3;
        if (q3 <= 1)
        {
          break;
        }
        cout << "Invalid numbers, try again.";
      }
      while(true)
      {
        cout << "\n4.The company doesn't got threat from subtitude product: ";
        cin >> q4;
        if (q4 <= 1)
        {
          break;
        }
        cout << "Invalid numbers, try again.";
      }
      while(true)
      {
        cout << "\n5.Strong against industrial rivary: ";
        cin >> q5;
        if (q5 <= 1)
        {
          break;
        }
        cout << "Invalid numbers, try again.";
      }
      while(true)
      {
        cout <<"\n6.future opportunity: ";
        cin >> q6;
        if (q6 <= 1)
        {
          break;
        }
        cout << "Invalid numbers, try again.";
      }
      Fiveforce e(q1, q2, q3 , q4, q5, q6) ;
      cout << "\nThe total score is " << e.countscore() << endl;
      cout <<"Input highest price: ";
      cin >> h;
      cout <<"Input current price: ";
      cin >> c;
      e.evaluation(h, c);
      break;
    }
    case 5: {
        cout << "\nThe system already end\n";
        return 0;
      }
    default: {
      cout << "\nPlease Enter the valid choice\n" << endl;
      break;
    }
    }
  }

  return 0;
}