#include "iostream"

auto Factory() {
    auto counter = 0;
    return [counter]() mutable {
        int count = counter++;
        return [count]() mutable {
            return count++;
        };
    };
}

int main() {
    auto makeCounter = Factory();
    auto Counter1 = makeCounter();
    std::cout << Counter1() << std::endl;
    std::cout << Counter1() << std::endl;
    auto Counter2 = makeCounter();
    std::cout << Counter2() << std::endl;
    std::cout << Counter2() << std::endl;
    auto Counter3 = makeCounter();
    std::cout << Counter3() << std::endl;
    std::cout << Counter3() << std::endl;
    std::cout << Counter3() << std::endl;
    return 0;
}
