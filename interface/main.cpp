#include <iostream>

class TaxCalcInterface {
public:
  virtual double calculateTaxes(int ammount = 500) = 0;
};

class TaxCalcEurope : public TaxCalcInterface {
public:
  double calculateTaxes(int ammount = 500) { return ammount * 1.1; }
};

class TaxCalcUsa : public TaxCalcInterface {
public:
  double calculateTaxes(int ammount = 500) { return ammount * 1.3; }
};

int main(int argc, char const *argv[]) {
  TaxCalcUsa taxusa;
  std::cout << taxusa.calculateTaxes(100) << std::endl;
  TaxCalcEurope taxeurope;
  std::cout << taxeurope.calculateTaxes() << std::endl;
  return 0;
}
