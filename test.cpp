#include <iostream>
#include <typeinfo>

enum class Season {
    Spring,
    Summer,
    Autumn,
    Winter
};


void switch_1 ()
{
    int a = 1;
    std::cout << "switch_1:" << std::endl;
    switch(a){
        case 0:
            std::cout << "0" << std::endl;
            break;
        case 1:
            std::cout << "1" << std::endl;
            break;
        case 2:
            std::cout << "2" << std::endl;
            break;
        case 3:
            std::cout << "3" << std::endl;
            break;
    }
}

int main() {
    Season currentSeason = Season::Winter;
    std::cout << "Type of currentSeason is: " << typeid(currentSeason).name() << std::endl;
    std::cout << static_cast<int>(currentSeason) << std::endl;

    int a = 6;
    std::cout << "Type of a is: " << typeid(a).name() << std::endl;

    float b = 6.3;
    std::cout << "Type of b is: " << typeid(b).name() << std::endl;

    switch_1 ();

    return 0;
}
