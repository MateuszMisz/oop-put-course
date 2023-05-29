#include<iostream>
#include <vector>
#include <optional>
class Pack {
  std::string text;
  int id;
  public:
  Pack(std::string txt) { this->text = std::move(txt); }
    void Print(){
      std::cout << this->text;
        
    }
  }
};

class Computer {
  std::string name;
  int serial_number;
  Pack* packs[10];
  int count;


  Computer(std::string name,int nr)
  { this->name = std::move(name);
    this->serial_number = nr;
    this->count = 0;
  }
 public:
     void Modify_data(Pack* pack) { 
       this->packs[count] = pack;
       count++;
  }
     Pack* Send_data(int nr) { return this->packs[count - 1];
     }
};
class Monitor {
  std::string name;
  std::string serie;
  Pack* file;
  Monitor(std::string name, std::string serie) {
    this->name=std::move(name);
    this->serie = std::move(serie);
  }
 public:
     void Print_file(Pack* pack) { 
         pack->Print();

     }

};
int main() {
  std::cout << "write text";
  std::string tmp;
  int nr;
  
  Pack file1(tmp);
  std::cout << "write computer name";
  std::cin>>tmp;
  std::cout << "write serial number";
  std::cin >> nr;
  Computer comp1

}