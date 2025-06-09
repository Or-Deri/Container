//orderi429@gmail.com
#include <iostream>
#include "MyContainer.hpp"

using namespace container;
int main() {

    MyContainer<int> c;   // Create a container for int
    
    // Add some values
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::cout << "Container contents: " << c << "\n\n";   // Print the container

    
    std::cout << "AscendingOrder: ";
    for (auto it = MyContainer<int>::AscendingOrder::begin(c); it !=  MyContainer<int>::AscendingOrder::end(c); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";


    std::cout << "DescendingOrder: ";
    for (auto it = MyContainer<int>::DescendingOrder::begin(c); it !=  MyContainer<int>::DescendingOrder::end(c); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "SideCrossOrder: ";
    for (auto it = MyContainer<int>::SideCrossOrder::begin(c); it !=  MyContainer<int>::SideCrossOrder::end(c); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "ReverseOrder: ";
    for (auto it = MyContainer<int>::ReverseOrder::begin(c); it !=  MyContainer<int>::ReverseOrder::end(c); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "Order: ";
    for (auto it = MyContainer<int>::Order::begin(c); it !=  MyContainer<int>::Order::end(c); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "MiddleOutOrder: ";
    for (auto it = MyContainer<int>::MiddleOutOrder::begin(c); it !=  MyContainer<int>::MiddleOutOrder::end(c); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";


    MyContainer<char> chars; // Create a container for chars
    chars.add('a');
    chars.add('b');
    chars.add('c');
    chars.add('d');
    chars.add('e');
    chars.add('h');
    std::cout << "Container contents: " << chars << "\n\n";   // Print the container


    std::cout << "AscendingOrder: ";
    for (auto it = MyContainer<char>::AscendingOrder::begin(chars); it !=  MyContainer<char>::AscendingOrder::end(chars); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";


    std::cout << "DescendingOrder: ";
    for (auto it = MyContainer<char>::DescendingOrder::begin(chars); it !=  MyContainer<char>::DescendingOrder::end(chars); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "SideCrossOrder: ";
    for (auto it = MyContainer<char>::SideCrossOrder::begin(chars); it !=  MyContainer<char>::SideCrossOrder::end(chars); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "ReverseOrder: ";
    for (auto it = MyContainer<char>::ReverseOrder::begin(chars); it !=  MyContainer<char>::ReverseOrder::end(chars); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "Order: ";
    for (auto it = MyContainer<char>::Order::begin(chars); it !=  MyContainer<char>::Order::end(chars); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";
    

    std::cout << "MiddleOutOrder: ";
    for (auto it = MyContainer<char>::MiddleOutOrder::begin(chars); it !=  MyContainer<char>::MiddleOutOrder::end(chars); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << "\n\n";

    return 0;
}