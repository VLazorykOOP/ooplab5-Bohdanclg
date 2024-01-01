/*Задача 2.1. Створити клас кімната, що має площа. Визначити конструктор і метод
доступу. Створити клас однокімнатних квартира, що містить кімнату й кухню (її
площа), поверх (кімната втримується в класі однокімнатна квартира). Визначити
конструктори, методи доступу. Визначити public-похідний клас однокімнатних
квартир різних міст ( додатковий параметр - назва міста). Визначити конструктори,
деструктор і функцію друку.*/

#include <iostream>
#include <string>

class Room{
    private:

    double area;

    public:

    Room(){
        area = 0;
    }

    Room(double a){
        area = a;
    }

    double getArea(){
        return area;
    }

};

class OneRoomApartament{
    private:
    double kitchenArea;
    Room room;
    int floor;

    public:

    OneRoomApartament() : room(){
        kitchenArea = 0;
        floor = 0;
    }

    OneRoomApartament(double roomArea, double kitchen, int f) : room(roomArea){
        kitchenArea = kitchen;
        floor = f;   
    }

    double getArea(){
        return room.getArea();
    }

    double getKitchenArea(){
        return kitchenArea;
    }

    int getFloor(){
        return floor;
    }

};

class CityApartament : public OneRoomApartament{
    private:
    std::string city;

    public:

    CityApartament() : OneRoomApartament(){
        city = "-";
    }

    CityApartament(double roomArea, double kitchen, int f, std::string c) : OneRoomApartament(roomArea, kitchen, f){
        city = c;
    }

    std::string getCity(){
        return city;
    }

    ~CityApartament() {
        std::cout << "CityApartment destructor." << std::endl;
    }    

    void PrintInfo(){
        std::cout << "City: " << city << ", Floor: " << getFloor() << ", Room Area: " << getArea() << " sq. m, Kitchen Area: " << getKitchenArea() << " sq. m" << std::endl;
    }

};


int main() {
    CityApartament apartment1(25.5, 10.2, 5, "Chernivtsi");

    std::cout << "Apartment 1 Information:" << std::endl;
    apartment1.PrintInfo();

    std::cout << "City: " << apartment1.getCity() << std::endl;
    std::cout << "Room Area: " << apartment1.getArea() << " sq. m" << std::endl;
    std::cout << "Kitchen Area: " << apartment1.getKitchenArea() << " sq. m" << std::endl;
    std::cout << "Floor: " << apartment1.getFloor() << std::endl;

    return 0;
}


