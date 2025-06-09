// orderi429@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <sstream>
#include <vector>
#include <stdexcept>
#include <string.h>
using namespace container;



TEST_CASE("add ") {
    MyContainer<int> c;
    CHECK(c.size() == 0);

    c.add(7);
    CHECK(c.size() == 1);
    c.add(9);
    CHECK(c.size() == 2);
    c.add(3);
    CHECK(c.size() == 3);
}

TEST_CASE("remove") {
    MyContainer<std::string> c;
    CHECK(c.size() == 0);

    c.add("AA");
    CHECK(c.size() == 1);
    c.remove("AA");
    CHECK(c.size() == 0);
}

TEST_CASE("remove from an empty container") {
    MyContainer<std::string> c;
    
    CHECK(c.size() == 0);
    CHECK_THROWS(c.remove("AA"));
}

TEST_CASE("remove object does not exist") {
    MyContainer<char> c;
    
    c.add('a');
    c.add('b');

    CHECK_THROWS(c.remove('c'));
}

TEST_CASE("remove object found several times") {
    MyContainer<int> c;
    
    c.add(8);
    c.add(8);
    c.add(8);

    CHECK(c.size() == 3);

    c.remove(8);
    CHECK(c.size() == 0);
}

TEST_CASE("size") {
    MyContainer<double> c;
    
    CHECK(c.size() == 0);

    c.add(1.1);
    CHECK(c.size() == 1);
    
    c.add(9.5);
    CHECK(c.size() == 2);
    
    c.add(3.7);
    CHECK(c.size() == 3);

    c.remove(9.5);
    CHECK(c.size() == 2);
}

TEST_CASE("operator <<") {
    MyContainer<int> c;
    c.add(6);
    c.add(11);
    c.add(2);

    std::ostringstream o;
    o << c;
    CHECK(o.str() == "[6, 11, 2]");
}


TEST_CASE("AscendingOrder for int") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> x;
    for (auto it = MyContainer<int>::AscendingOrder::begin(c); it != MyContainer<int>::AscendingOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<int>{1, 2, 6, 7, 15});
}
TEST_CASE("AscendingOrder for string") {
    MyContainer<std::string> c;
    c.add("AA");
    c.add("BB");
    c.add("CC");
    c.add("DD");
    c.add("EE");

    std::vector<std::string> x;
    for (auto it = MyContainer<std::string>::AscendingOrder::begin(c); it != MyContainer<std::string>::AscendingOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<std::string>{"AA", "BB", "CC", "DD", "EE"});
}

TEST_CASE("DescendingOrder for int") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> x;
    for (auto it = MyContainer<int>::DescendingOrder::begin(c); it != MyContainer<int>::DescendingOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<int>{15, 7, 6, 2, 1});
}

TEST_CASE("DescendingOrder for string") {
    MyContainer<std::string> c;
    c.add("AA");
    c.add("BB");
    c.add("CC");
    c.add("DD");
    c.add("EE");

    std::vector<std::string> x;
    for (auto it = MyContainer<std::string>::DescendingOrder::begin(c); it != MyContainer<std::string>::DescendingOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<std::string>{"EE", "DD", "CC", "BB", "AA"});
}

TEST_CASE("SideCrossOrder for int") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> x;
    for (auto it = MyContainer<int>::SideCrossOrder::begin(c); it != MyContainer<int>::SideCrossOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<int>{1, 15, 2, 7, 6});
}

TEST_CASE("SideCrossOrder for double") {
    MyContainer<double> c;
    c.add(7.7);
    c.add(15.6);
    c.add(6.8);
    c.add(1.3);
    c.add(2.2);

    std::vector<double> x;
    for (auto it = MyContainer<double>::SideCrossOrder::begin(c); it != MyContainer<double>::SideCrossOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<double>{1.3, 15.6, 2.2, 7.7, 6.8});
}

TEST_CASE("ReverseOrder for int"){
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> x;
    for (auto it = MyContainer<int>::ReverseOrder::begin(c); it != MyContainer<int>::ReverseOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<int>{2, 1, 6, 15, 7});
}

TEST_CASE("Order for int") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> x;
    for (auto it = MyContainer<int>::Order::begin(c); it != MyContainer<int>::Order::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<int>{7, 15, 6, 1, 2});
}

TEST_CASE("Order for char") {
    MyContainer<char> c;
    c.add('A');
    c.add('B');
    c.add('C');
    c.add('D');
    c.add('E');

    std::vector<char> x;
    for (auto it = MyContainer<char>::Order::begin(c); it != MyContainer<char>::Order::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<char>{'A', 'B', 'C', 'D', 'E'});
}

TEST_CASE("MiddleOutOrder for int") {
    MyContainer<int> c;
    c.add(7);
    c.add(15);
    c.add(6);
    c.add(1);
    c.add(2);

    std::vector<int> x;
    for (auto it = MyContainer<int>::MiddleOutOrder::begin(c); it != MyContainer<int>::MiddleOutOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<int>{6, 15, 1, 7, 2});
}

TEST_CASE("MiddleOutOrder for double") {
    MyContainer<double> c;
    c.add(9.9);
    c.add(17.5);
    c.add(8.2);
    c.add(0.4);

    std::vector<double> x;
    for (auto it = MyContainer<double>::MiddleOutOrder::begin(c); it != MyContainer<double>::MiddleOutOrder::end(c); ++it){
        x.push_back(*it);
    }
    CHECK(x == std::vector<double>{8.2, 17.5, 0.4, 9.9});
}

TEST_CASE("operator* when container is empty"){
    
    MyContainer<int> c;  
    

    SUBCASE("AscendingOrder"){
        auto it = MyContainer<int>::AscendingOrder::begin(c);    
        CHECK_THROWS(*it);
    }

    SUBCASE("DescendingOrder"){
        auto it = MyContainer<int>::DescendingOrder::begin(c);
        CHECK_THROWS(*it);
    }

    SUBCASE("SideCrossOrder"){
        auto it = MyContainer<int>::SideCrossOrder::begin(c);
        CHECK_THROWS(*it);
    }

    SUBCASE("ReverseOrder"){
        auto it = MyContainer<int>::ReverseOrder::begin(c);
        CHECK_THROWS(*it);
    }

    SUBCASE("Order"){
        auto it = MyContainer<int>::Order::begin(c);
        CHECK_THROWS(*it);
    }

    SUBCASE("MiddleOutOrder"){
        auto it = MyContainer<int>::MiddleOutOrder::begin(c);
        CHECK_THROWS(*it);
    }
}


TEST_CASE("operator++ when increment past end"){
    
    MyContainer<int> c;
    c.add(5);  // size = 1
    

    SUBCASE("AscendingOrder"){
        auto it = MyContainer<int>::AscendingOrder::begin(c);
        ++it;       
        CHECK_THROWS(++it);
    }

    SUBCASE("DescendingOrder"){
        auto it = MyContainer<int>::DescendingOrder::begin(c);
        ++it;       
        CHECK_THROWS(++it);
    }

    SUBCASE("SideCrossOrder"){
        auto it = MyContainer<int>::SideCrossOrder::begin(c);
        ++it;       
        CHECK_THROWS(++it);
    }

    SUBCASE("ReverseOrder"){
        auto it = MyContainer<int>::ReverseOrder::begin(c);
        ++it;       
        CHECK_THROWS(++it);
    }

    SUBCASE("Order"){
        auto it = MyContainer<int>::Order::begin(c);
        ++it;       
        CHECK_THROWS(++it);
    }

    SUBCASE("MiddleOutOrder"){
        auto it = MyContainer<int>::MiddleOutOrder::begin(c);
        ++it;       
        CHECK_THROWS(++it);
    }
}