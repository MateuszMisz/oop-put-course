// ConsoleApplication1.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
//

#include <iostream>
using namespace std;
class Temperature {
 private:
  double temp;
  string scale;

 public:
  Temperature() {
    this->temp = 0;
    this->scale = "C";
  };
  Temperature(double temp, string scale) {
    this->temp = temp;
    this->scale = scale;
  };
  Temperature(float temp, string scale)
      : Temperature(static_cast<double> (temp), scale){};
  Temperature(int temp, string scale)
      : Temperature(static_cast<double>(temp), scale){};
  Temperature(string temp, string scale) : Temperature(stod(temp), scale){};
  double Show_K_value() {
      if (this->scale == "C")
      cout<< this->temp + 273.15<<endl;
    else if (this->scale == "F")
      cout << this->temp * 5 / 9 + 459.67<<endl;
    else if (this->scale == "K")
      cout << this->temp<<endl;
  }
  double Show_C_value() {
    if (this->scale == "C")
      cout << this->temp<<endl;
    else if (this->scale == "F")
      cout << this->temp * 5 / 9 + 459.67 - 273.15<<endl;
    else if (this->scale == "K")
      cout << this->temp - 273.15<<endl;
  }
  double Show_F_value() {
    if (this->scale == "C")
      cout << this->temp * 9 / 5 + 32<<endl;
    else if (this->scale == "F")
      cout << this->temp<<endl;
    else if (this->scale == "K")
      cout << (this->temp - 273.15) * 9 / 5 + 32<<endl;
  }
};




int main()
{

  Temperature reading_1;
  Temperature reading_2(100.30,"K");
  Temperature reading_3(50.23f, "F");
  Temperature reading_4(109, "C");
  Temperature reading_5("130", "K");
  reading_1.Show_F_value();
  reading_3.Show_K_value();
  reading_5.Show_C_value();

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotycz¹ce rozpoczynania pracy:
//   1. U¿yj okna Eksploratora rozwi¹zañ, aby dodaæ pliki i zarz¹dzaæ nimi
//   2. U¿yj okna programu Team Explorer, aby nawi¹zaæ po³¹czenie z kontrol¹ Ÿród³a
//   3. U¿yj okna Dane wyjœciowe, aby sprawdziæ dane wyjœciowe kompilacji i inne komunikaty
//   4. U¿yj okna Lista b³êdów, aby zobaczyæ b³êdy
//   5. Wybierz pozycjê Projekt > Dodaj nowy element, aby utworzyæ nowe pliki kodu, lub wybierz pozycjê Projekt > Dodaj istniej¹cy element, aby dodaæ istniej¹ce pliku kodu do projektu
//   6. Aby w przysz³oœci ponownie otworzyæ ten projekt, przejdŸ do pozycji Plik > Otwórz > Projekt i wybierz plik sln
