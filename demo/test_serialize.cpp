//
// Created by mutalisk on 2016/12/3.
//

#include "serialize.hpp"

class TestClass
{
public:
    int test_int;
    std::string test_str;
    std::vector<int> test_vec;
};

void pack(std::stringstream& ss, const TestClass& data)
{
    pack(ss, data.test_int);
    pack(ss, data.test_str);
    pack(ss, data.test_vec);
}

void unpack(std::stringstream& ss, TestClass& data)
{
    unpack(ss, data.test_int);
    unpack(ss, data.test_str);
    unpack(ss, data.test_vec);
}

class TestInheritClass: public TestClass
{
public:
    double test_double;
    std::map<int, std::string> test_map;
};

void pack(std::stringstream& ss, const TestInheritClass& data)
{
    pack(ss, (TestClass)data);
    pack(ss, data.test_double);
    pack<int, std::string>(ss, data.test_map);
}

void unpack(std::stringstream& ss, TestInheritClass& data)
{
    TestClass base_data;
    unpack(ss, (TestClass&)data);
    unpack(ss, data.test_double);
    unpack<int, std::string>(ss, data.test_map);
}

enum TestEnum
{
    MONDAY, TUESDAY
};

int main()
{
    std::stringstream ss;

    bool b = 1;
    pack(ss, b);
    bool b1;
    unpack(ss, b1);
    std::cout << b1 << std::endl;

    unsigned char uc= 'a';
    pack(ss, uc);
    unsigned char uc1;
    unpack(ss, uc1);
    std::cout << uc1 << std::endl;

    char c = 'a';
    pack(ss, c);
    char c1;
    unpack(ss, c1);
    std::cout << c1 << std::endl;

    unsigned short us = 30;
    pack(ss, us);
    unsigned short us1;
    unpack(ss, us1);
    std::cout << us1 << std::endl;

    short s = -30;
    pack(ss, s);
    short s1;
    unpack(ss, s1);
    std::cout << s1 << std::endl;

    unsigned int ui = 100;
    pack(ss, ui);
    unsigned int ui1;
    unpack(ss, ui1);
    std::cout << ui1 << std::endl;

    int i = -100;
    pack(ss, i);
    int i1;
    unpack(ss, i1);
    std::cout << i1 << std::endl;

    unsigned long long ull = 10000000000;
    pack(ss, ull);
    unsigned long long ull1;
    unpack(ss, ull1);
    std::cout << ull1 << std::endl;

    long long ll = -10000000000;
    pack(ss, ll);
    long long ll1;
    unpack(ss, ll1);
    std::cout << ll1 << std::endl;

    float f = 3.14;
    pack(ss, f);
    float f1;
    unpack(ss, f1);
    std::cout << f1 << std::endl;

    double d = -3.1415926;
    pack(ss, d);
    double d1;
    unpack(ss, d1);
    std::cout << d1 << std::endl;

    char* c_str = (char*)"abcde";
    pack(ss, c_str);
    char str_array[100];
    char* c_str1 = str_array;
    unpack(ss, c_str1);
    std::cout << "[" << c_str1 << "]" << std::endl;

    std::string str = "abcde";
    std::cout << str.length() << std::endl;
    pack(ss, str);
    std::string str1;
    unpack(ss, str1);
    std::cout << "[" << str1 << "]" << std::endl;

    std::array<int, 10> array{1,2,3,4,5};
    pack(ss, array);
    std::array<int, 10> array1;
    unpack(ss, array1);
    std::cout << array1.size() << std::endl;
    for(auto item: array1)
        std::cout << item << " ";
    std::cout << std::endl;

    std::vector<std::vector<int>> vec{{1,2,3}, {4,5,6}, {7,8,9}};
    pack(ss, vec);
    std::vector<std::vector<int>> vec1;
    unpack(ss, vec1);
    std::cout << vec1.size() << std::endl;
    for(auto item: vec1)
        std::cout << item.size() << " ";
    std::cout << std::endl;

    std::deque<std::deque<int>> deq{{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    pack(ss, deq);
    std::deque<std::deque<int>> deq1;
    unpack(ss, deq1);
    std::cout << deq1.size() << std::endl;
    for(auto item: deq1)
        std::cout << item.size() << " ";
    std::cout << std::endl;

    std::list<std::string> list{"abc", "123", "kkk"};
    pack(ss, list);
    std::list<std::string> list1;
    unpack(ss, list1);
    std::cout << list1.size() << std::endl;
    for(auto item: list1)
        std::cout << item << " ";
    std::cout << std::endl;

    std::set<double> set{1.23, 2.34, -5.67, 3.14};
    pack(ss, set);
    std::set<double> set1;
    unpack(ss, set1);
    std::cout << set1.size() << std::endl;
    for(auto item: set1)
        std::cout << item << " ";
    std::cout << std::endl;

    std::multiset<double> multiset{1.23, 1.23, -5.67, 3.14, -5.67};
    pack(ss, multiset);
    std::multiset<double> multiset1;
    unpack(ss, multiset1);
    std::cout << multiset1.size() << std::endl;
    for(auto item: multiset1)
        std::cout << item << " ";
    std::cout << std::endl;

    std::unordered_set<double> unordered_set{1.23, 2.34, -5.67, 3.14};
    pack(ss, unordered_set);
    std::unordered_set<double> unordered_set1;
    unpack(ss, unordered_set1);
    std::cout << unordered_set1.size() << std::endl;
    for(auto item: unordered_set1)
        std::cout << item << " ";
    std::cout << std::endl;

    std::unordered_multiset<double> unordered_multiset{1.23, 1.23, -5.67, 3.14, -5.67};
    pack(ss, unordered_multiset);
    std::unordered_multiset<double> unordered_multiset1;
    unpack(ss, unordered_multiset1);
    std::cout << unordered_multiset1.size() << std::endl;
    for(auto item: unordered_multiset1)
        std::cout << item << " ";
    std::cout << std::endl;

    std::pair<std::string, std::string> pair = std::make_pair("abc", "123");
    pack(ss, pair);
    std::pair<std::string, std::string> pair1;
    unpack(ss, pair1);
    std::cout << pair1.first << "," << pair1.second << std::endl;

    std::map<int, std::string> map;
    map.insert(std::make_pair(1, "1"));
    map.insert(std::make_pair(2, "2"));
    map.insert(std::make_pair(3, "3"));
    pack<int, std::string>(ss, map);
    std::map<int, std::string> map1;
    unpack<int, std::string>(ss, map1);
    std::cout << map1.size() << std::endl;
    for (auto pair: map1)
        std::cout << pair.first << "," << pair.second << " ";
    std::cout << std::endl;

    std::multimap<int, std::string> multimap;
    multimap.insert(std::make_pair(1, "1"));
    multimap.insert(std::make_pair(2, "2"));
    multimap.insert(std::make_pair(3, "3"));
    multimap.insert(std::make_pair(1, "5"));
    multimap.insert(std::make_pair(2, "6"));
    pack<int, std::string>(ss, multimap);
    std::multimap<int, std::string> multimap1;
    unpack<int, std::string>(ss, multimap1);
    std::cout << multimap1.size() << std::endl;
    for (auto pair: multimap1)
        std::cout << pair.first << "," << pair.second << " ";
    std::cout << std::endl;

    std::unordered_map<int, std::string> unordered_map;
    unordered_map.insert(std::make_pair(1, "1"));
    unordered_map.insert(std::make_pair(2, "2"));
    unordered_map.insert(std::make_pair(3, "3"));
    pack<int, std::string>(ss, unordered_map);
    std::map<int, std::string> unordered_map1;
    unpack<int, std::string>(ss, unordered_map1);
    std::cout << unordered_map1.size() << std::endl;
    for (auto pair: unordered_map1)
        std::cout << pair.first << "," << pair.second << " ";
    std::cout << std::endl;

    std::unordered_multimap<int, std::string> unordered_multimap;
    unordered_multimap.insert(std::make_pair(1, "1"));
    unordered_multimap.insert(std::make_pair(2, "2"));
    unordered_multimap.insert(std::make_pair(3, "3"));
    unordered_multimap.insert(std::make_pair(1, "5"));
    unordered_multimap.insert(std::make_pair(2, "6"));
    pack<int, std::string>(ss, unordered_multimap);
    std::multimap<int, std::string> unordered_multimap1;
    unpack<int, std::string>(ss, unordered_multimap1);
    std::cout << unordered_multimap1.size() << std::endl;
    for (auto pair: unordered_multimap1)
        std::cout << pair.first << "," << pair.second << " ";
    std::cout << std::endl;

    TestClass test_class;
    test_class.test_int = 1;
    test_class.test_str = "hello";
    test_class.test_vec = {1,2,3};
    pack(ss, test_class);
    TestClass test_class1;
    unpack(ss, test_class1);
    std::cout << test_class1.test_int << " " << test_class1.test_str << " " \
            << test_class1.test_vec.size() << std::endl;

    enumWrapper<TestEnum> test_enum = TUESDAY;
    pack(ss, test_enum);
    enumWrapper<TestEnum> test_enum1;
    unpack(ss, test_enum1);
    std::cout << test_enum1.value << std::endl;

    TestInheritClass test_inherit_class;
    test_inherit_class.test_int = 1;
    test_inherit_class.test_str = "hello";
    test_inherit_class.test_vec = {1,2,3};
    test_inherit_class.test_double = 3.1415;
    test_inherit_class.test_map.insert(std::make_pair(1, "hello"));
    test_inherit_class.test_map.insert(std::make_pair(2, "world"));
    pack(ss, test_inherit_class);
    TestInheritClass test_inherit_class1;
    unpack(ss, test_inherit_class1);
    std::cout << test_inherit_class1.test_int << " " << test_inherit_class1.test_str << " " \
            << test_inherit_class1.test_vec.size() << " " << test_inherit_class1.test_double << " " \
            << test_inherit_class1.test_map.size();

    return 0;
}

