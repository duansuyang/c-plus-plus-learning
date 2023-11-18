#include <iostream>
#include <typeinfo>

enum class Season {
    Spring,
    Summer,
    Autumn,
    Winter
};

int main() {
    Season currentSeason = Season::Winter;
    std::cout << "Type of currentSeason is: " << typeid(currentSeason).name() << std::endl;
    std::cout << static_cast<int>(currentSeason) << std::endl;

    int a = 6;
    std::cout << "Type of a is: " << typeid(a).name() << std::endl;

    float b = 6.3;
    std::cout << "Type of b is: " << typeid(b).name() << std::endl;



    return 0;
}
