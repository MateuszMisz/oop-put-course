#include <iostream>
#include <map>
using namespace std;
class Cantor {
 public:
  Cantor() = default;
  virtual ~Cantor() = default;

  virtual double Rate(const string& abbreviation) const = 0;
};
class Currency {
 public:
  Currency() = default;
  virtual ~Currency() = default;

  virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
  virtual string Abbreviation() const = 0;
  virtual double Amount() const = 0;
};



class FakeUsdCantor : public Cantor {
 public:
  FakeUsdCantor() {
    // rates_ map with values for ten most popular currencies relative to USD
    rates_ = {{"EUR", 0.85}, {"JPY", 110.66}, {"GBP", 0.73}, {"CHF", 0.91},
              {"CAD", 1.25}, {"AUD", 1.34},   {"CNY", 6.47}, {"HKD", 7.78},
              {"NZD", 1.44}, {"KRW", 1153.89}};
  }

  double Rate(const string& abbreviation) const override {
    auto it = rates_.find(abbreviation);
    if (it != rates_.end()) {
      return it->second;
    }
    // Handle error case when currency abbreviation is not found
    return 0.0;
  }

 private:
  map<string, double> rates_;
};
class Euro : public Currency{
  double amount;
  string abr;
  public:
  Euro() {
    amount = 0;
    abr = "EUR";
  }
  Euro(double amount, string abr) {
    this->amount = amount;
    this->abr = abr;
  }
  double ConvertedToDollars(const Cantor& cantor) const override {
    return this->amount / cantor.Rate(this->abr);
  }
  string Abbreviation()const override { return this->abr;
  }
  double Amount()const override { return this->amount;
  }
  void PrintCmpDollars(Cantor&cantor) {


    cout << Amount() << Abbreviation() << " - " << ConvertedToDollars(cantor)
         << "USD"<<endl;
  }

};
int main() {
FakeUsdCantor cantor;
Euro e1(100,"EUR");
e1.Abbreviation();
e1.Amount();
e1.PrintCmpDollars(cantor);
  return 0;
}
