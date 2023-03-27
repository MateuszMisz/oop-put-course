// ConsoleApplication1.cpp : Ten plik zawiera funkcj� �main�. W nim rozpoczyna si� i ko�czy wykonywanie programu.
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

// Porady dotycz�ce rozpoczynania pracy:
//   1. U�yj okna Eksploratora rozwi�za�, aby doda� pliki i zarz�dza� nimi
//   2. U�yj okna programu Team Explorer, aby nawi�za� po��czenie z kontrol� �r�d�a
//   3. U�yj okna Dane wyj�ciowe, aby sprawdzi� dane wyj�ciowe kompilacji i inne komunikaty
//   4. U�yj okna Lista b��d�w, aby zobaczy� b��dy
//   5. Wybierz pozycj� Projekt > Dodaj nowy element, aby utworzy� nowe pliki kodu, lub wybierz pozycj� Projekt > Dodaj istniej�cy element, aby doda� istniej�ce pliku kodu do projektu
//   6. Aby w przysz�o�ci ponownie otworzy� ten projekt, przejd� do pozycji Plik > Otw�rz > Projekt i wybierz plik sln
