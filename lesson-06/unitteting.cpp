// unitteting.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <memory>
#include <sstream>
#include<cassert>
class Sequence {
 public:

  virtual int Length() = 0;
};
class FakeSequence : public Sequence {
  std::string seq;
 public:
     int Length() override { return 100;
  }
};
class Gene {
  Sequence* sequence;
  std::string name;

 public:
  Gene(Sequence* sequence, std::string name) {
    this->sequence = sequence;
    this->name = name;
  }
    std::string JSON() { std::stringstream ss;
      ss << "{"
         << "\"name\:" << name << "\", \"length\": " << sequence->Length()
         << "}";
      return ss.str();
      
    }
  
};
int main()
{
  Sequence* sequence = new FakeSequence;

  Gene gene(sequence, "BALF5");
  std::cout << gene.JSON() << std::endl;
  assert(sequence->Length() == 100);

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
