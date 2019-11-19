#include <iostream>
#include <string>
using namespace std;

 class Instrument{
 public:
     string *manufacturer;
     int price;
     Instrument(){}
     virtual void show() = 0;
     virtual void playSound() = 0;
      ~Instrument(){
         delete []manufacturer;
     }
 };

class Metal: virtual public Instrument{
protected:
    string *typeOfMetal;
public:
    Metal(){}
    Metal(string m, string t, int p){
        this->manufacturer = &m;
        this->typeOfMetal = &t;
        this->price = p;
    }
    void show(){
        std::cout << "manufacturer: " << *this->manufacturer << "\n";
        std::cout << "type of metal: " << *this->typeOfMetal << "\n";
        std::cout << "price: " << this->price << "\n";
    }
     void playSound(){std::cout << "metal fiufiufiu\n";}
     ~Metal(){delete []typeOfMetal;}
};

class Wooden: virtual public Instrument{
protected:
    string *typeOfWood;
public:
    Wooden(){}
    Wooden(string m, string t, int p){
        this->manufacturer = &m;
        this->typeOfWood = & t;
        this->price = p;
    }
    void show(){
        std::cout << "manufacturer: " << *this->manufacturer << "\n";
        std::cout << "type of wood: " << *this->typeOfWood << "\n";
        std::cout << "price: " << this->price << "\n";
    }
     void playSound(){std::cout << "wooden fiufiufiu\n";}
//    virtual void playSound() = 0;
     ~Wooden(){delete [] typeOfWood;}
};

class Wind final: public Metal, public Wooden{
protected:
    bool hasZip;
public:
    Wind(){}
    Wind(string type, string m, bool zip, int p, string materialType){
        this->manufacturer = &m;
        this->hasZip = zip;
        this->price = p;
        if(type == "metal"){
            Metal::typeOfMetal = &materialType;
        } else{
            Wooden::typeOfWood = &materialType;
        }
    }
    void show(){
        std::cout << "manufacturer: " << *this->manufacturer << "\n";
        std::cout << "haz zip: " << this->hasZip << "\n";
        std::cout << "price: " << this->price << "\n";
        if(this->typeOfWood != nullptr){
            std::cout << "material: " << *this->typeOfWood << "\n";
        } else{
            std::cout << "material: " << *this->typeOfMetal << "\n";
        }
    }
    void playSound(){
        if(this->typeOfWood == nullptr){
            std::cout << "metal fiufiufiu\n";
        } else{
            std::cout << "wooden fiuiufiu\n";
        }
    }
    ~Wind(){}
};

class Keyboard final: virtual public Wooden{
protected:
    int numOfKeys;
public:
    Keyboard(){}
    Keyboard(string m, int n, int p){
        this->manufacturer = &m;
        this->numOfKeys = n;
        this->price = p;
    }
    void show(){
        std::cout << "manufacturer: " << *this->manufacturer << "\n";
        std::cout << "number of keys: " << numOfKeys << "\n";
        std::cout << "price: " << this->price << "\n";
    }
    void playSound(){std::cout << "rampampampam\n";}
    ~Keyboard(){}
};

int main(){

    Wooden* piano = new Keyboard("fazioli", 96, 1000);
    piano->show();
    piano->playSound();

    std::cout << "\n";

    Metal* trumpet = new Wind("metal", "wind manufacturer", false, 100, "aluminium");
    trumpet->show();
    trumpet->playSound();

    std::cout << "\n";


    Wooden* flute = new Wind("wooden", "flute manufacturer", false, 1240, "aluminium");
    flute->show();
    flute->playSound();

    std::cout << "\n";

    Metal* trombone = new Wind("metal", "trombone manufacturer", true, 9, "trombone metal");
    trombone->show();
    trombone->playSound();

    delete piano;
    delete trumpet;
    delete flute;

    return 0;
}