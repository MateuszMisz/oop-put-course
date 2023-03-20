// zad1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using namespace std;
class Computer {
    string type;
    string name;
public:
    int get_type(string type);
    int get_name(string name);
    int turning_on(int x);
    int turning_off(int x);
    int type_in();
    string print(string text);
    void connect(string ip);

};
class Window {

    float transparentness;
    int glass_layers;
    int is_openable;
    int glass_type;
    string color;
public:
    int open();
    int close();
    int get_transparentness(string t);
    int get_glass_layers(int amount);
    int get_is_openable(int x);
    int get_glass_type(string type);
};
class Mouse {
    int is_wireless;
    float length;
    float width;
    float height;
public:
    int send_move_signal();
    int send_click(int button);
};
class Human {
    float height;
    int age;
    string name;
public:
    int stand_up();
    int sit_down();
    int get_height(float height);
    int get_age(int age);
    int get_name(string name);

};
int main()
{
    string tekst;
    int z;
    float decimal;
    cout << "write name, heghtand age of the person";
    
    class Human person1;
    cin >> tekst >> decimal >> z;
    person1.get_name(tekst);
    person1.get_height(decimal);
    person1.get_age(z);
    
    cout << "write type(pc\\laptop) and serial number of the computer";
    class Computer comp1;
    cin >> tekst;
    comp1.get_type(tekst);
    cin >> tekst;
    comp1.get_name(tekst);
    cout << "do u want to open computer?(1-yes,0-no)";
    cin >> z;
    comp1.turning_on(z);


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
