//
// Created by mutalisk on 2016/12/3.
//

#include <strings.h>
#include <cstdlib>
#include <sstream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>

#include <unordered_set>
#include <unordered_map>

#include <iostream>
#include <assert.h>


inline bool is_little_endian()
{
    static bool test_before = false;
    static bool test_result = false;

    if (not test_before) {
        uint16_t i = (0x01 << 8) + 0x02;
        uint8_t *p = (uint8_t *) (&i);
        if (*p == 0x02)
            test_result = true;
        test_before = true;
    }

    return test_result;
}


inline void pack(std::stringstream& ss, bool data)
{
    ss.write((char*)&data, 1);
}

inline void unpack(std::stringstream& ss, bool& data)
{
    ss.read((char*)&data, 1);
}

inline void pack(std::stringstream& ss, char data)
{
    ss.write(&data, 1);
}

inline void unpack(std::stringstream& ss, char& data)
{
    ss.read(&data, 1);
}

inline void pack(std::stringstream& ss, int8_t data)
{
    ss.write((char*)&data, 1);
}

inline void unpack(std::stringstream& ss, int8_t& data)
{
    ss.read((char*)&data, 1);
}

inline void pack(std::stringstream& ss, uint8_t data)
{
    pack(ss, (int8_t)data);
}

inline void unpack(std::stringstream& ss, uint8_t& data)
{
    unpack(ss, (int8_t&)data);
}

inline void pack(std::stringstream& ss, int16_t data)
{
    int8_t* p = (int8_t*)(&data);

    if(is_little_endian()) {
        pack(ss, *(p+1));
        pack(ss, *(p));
    }
    else {
        pack(ss, *(p));
        pack(ss, *(p+1));
    }
}

inline void unpack(std::stringstream& ss, int16_t& data)
{
    int8_t* p = (int8_t*)(&data);

    if(is_little_endian()) {
        unpack(ss, *(p+1));
        unpack(ss, *(p));
    }
    else {
        unpack(ss, *(p));
        unpack(ss, *(p+1));
    }
}

inline void pack(std::stringstream& ss, uint16_t data)
{
    pack(ss, (int16_t)data);
}

inline void unpack(std::stringstream& ss, uint16_t& data)
{
    unpack(ss, (int16_t&)data);
}

inline void pack(std::stringstream& ss, int32_t data)
{
    int16_t* p = (int16_t*)(&data);

    if(is_little_endian()) {
        pack(ss, *(p+1));
        pack(ss, *(p));
    }
    else {
        pack(ss, *(p));
        pack(ss, *(p+1));
    }
}

inline void unpack(std::stringstream& ss, int32_t& data)
{
    int16_t* p = (int16_t*)(&data);

    if(is_little_endian()) {
        unpack(ss, *(p+1));
        unpack(ss, *(p));
    }
    else {
        unpack(ss, *(p));
        unpack(ss, *(p+1));
    }
}

inline void pack(std::stringstream& ss, uint32_t data)
{
    pack(ss, (int32_t)data);
}

inline void unpack(std::stringstream& ss, uint32_t& data)
{
    unpack(ss, (int32_t&)data);
}

inline void pack(std::stringstream& ss, int64_t data)
{
    int32_t* p = (int32_t*)(&data);

    if(is_little_endian()) {
        pack(ss, *(p+1));
        pack(ss, *(p));
    }
    else {
        pack(ss, *(p));
        pack(ss, *(p+1));
    }
}

inline void unpack(std::stringstream& ss, int64_t& data)
{
    int32_t* p = (int32_t*)(&data);

    if(is_little_endian()) {
        unpack(ss, *(p+1));
        unpack(ss, *(p));
    }
    else {
        unpack(ss, *(p));
        unpack(ss, *(p+1));
    }
}

inline void pack(std::stringstream& ss, uint64_t data)
{
    pack(ss, (int64_t)data);
}

inline void unpack(std::stringstream& ss, uint64_t& data)
{
    unpack(ss, (int64_t&)data);
}

inline void pack(std::stringstream& ss, float data)
{
    uint8_t* p = (uint8_t*)&data;
    pack(ss, *(p+3));
    pack(ss, *(p+2));
    pack(ss, *(p+1));
    pack(ss, *(p));
}

inline void unpack(std::stringstream& ss, float& data)
{
    uint8_t* p = (uint8_t*)&data;
    unpack(ss, *(p+3));
    unpack(ss, *(p+2));
    unpack(ss, *(p+1));
    unpack(ss, *(p));
}

inline void pack(std::stringstream& ss, double data)
{
    uint8_t* p = (uint8_t*)&data;
    pack(ss, *(p+7));
    pack(ss, *(p+6));
    pack(ss, *(p+5));
    pack(ss, *(p+4));
    pack(ss, *(p+3));
    pack(ss, *(p+2));
    pack(ss, *(p+1));
    pack(ss, *(p));
}

inline void unpack(std::stringstream& ss, double& data)
{
    uint8_t* p = (uint8_t*)&data;
    unpack(ss, *(p+7));
    unpack(ss, *(p+6));
    unpack(ss, *(p+5));
    unpack(ss, *(p+4));
    unpack(ss, *(p+3));
    unpack(ss, *(p+2));
    unpack(ss, *(p+1));
    unpack(ss, *(p));
}

inline void pack(std::stringstream& ss, const char* str)
{
    unsigned int str_size = (unsigned int)strlen(str) + 1;
    pack(ss, str_size);
    ss.write(str, str_size);
}

inline void unpack(std::stringstream& ss, char* str)
{
    unsigned int str_size;
    unpack(ss, str_size);
    ss.read(str, str_size);
}

inline void pack(std::stringstream& ss, const unsigned char* str)
{
    pack(ss, (const char*)str);
}

inline void unpack(std::stringstream& ss, unsigned char* str)
{
    unpack(ss, (char*)str);
}

inline void pack(std::stringstream& ss, const char* oct_str, unsigned int len)
{
    pack(ss, len);
    ss.write(oct_str, len);
}

inline void unpack(std::stringstream& ss, char* oct_str, unsigned int& len)
{
    unpack(ss, len);
    ss.read(oct_str, len);
}

inline void pack(std::stringstream& ss, const unsigned char* oct_str, unsigned int len)
{
    pack(ss, (char*)oct_str, len);
}

inline void unpack(std::stringstream& ss, unsigned char* oct_str, unsigned int& len)
{
    unpack(ss, (char*)oct_str, len);
}

inline void pack(std::stringstream& ss, const std::string& str)
{
    unsigned int str_size = (unsigned int)strlen(str.data());
    pack(ss, str_size);
    ss.write(str.data(), str_size);
}

inline void unpack(std::stringstream& ss, std::string& str)
{
    unsigned int str_size;
    unpack(ss, str_size);
    str.resize(str_size);
    ss.read((char*)str.data(), str_size);
}

template <typename T, std::size_t S>
inline void pack(std::stringstream& ss, const std::array<T,S>& data_array)
{
    unsigned int array_size = (unsigned int)data_array.size();
    pack(ss, array_size);
    for(const auto& data: data_array)
        pack(ss, data);
}

template <typename T, std::size_t S>
inline void unpack(std::stringstream& ss, std::array<T,S>& data_array)
{
    unsigned int array_size;
    unpack(ss, array_size);
    assert(array_size == data_array.size());
    for(unsigned int i = 0; i < array_size; ++i) {
        unpack(ss, data_array[i]);
    }
}

template <typename T>
inline void pack(std::stringstream& ss, const std::vector<T>& data_vector)
{
    unsigned int vec_size = (unsigned int)data_vector.size();
    pack(ss, vec_size);
    for(auto data: data_vector)
        pack(ss, data);
}

template <typename T>
inline void unpack(std::stringstream& ss, std::vector<T>& data_vector)
{
    unsigned int vec_size;
    unpack(ss, vec_size);
    data_vector.resize(vec_size);
    for(unsigned int i = 0; i < vec_size; ++i) {
        unpack(ss, data_vector[i]);
    }
}

template<typename T>
inline void pack(std::stringstream& ss, const std::deque<T>& data_deque)
{
    unsigned int deque_size = (unsigned int)data_deque.size();
    pack(ss, deque_size);
    for(auto data: data_deque)
        pack(ss, data);
}

template<typename T>
inline void unpack(std::stringstream& ss, std::deque<T>& data_deque)
{
    unsigned int deque_size;
    unpack(ss, deque_size);
    data_deque.resize(deque_size);
    for(unsigned int i = 0; i < deque_size; ++i) {
        unpack(ss, (T&)data_deque[i]);
    }
}

template <typename T>
inline void pack(std::stringstream& ss, const std::list<T>& data_list)
{
    unsigned int list_size = (unsigned int)data_list.size();
    pack(ss, list_size);
    auto iter = data_list.begin();
    while(iter != data_list.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template <typename T>
inline void unpack(std::stringstream& ss, std::list<T>& data_list)
{
    unsigned int list_size;
    unpack(ss, list_size);
    for(unsigned int i = 0; i < list_size; ++i) {
        T data;
        unpack(ss, data);
        data_list.emplace_back(data);
    }
}

template <typename T>
inline void pack(std::stringstream& ss, const std::set<T>& data_set)
{
    unsigned int set_size = (unsigned int)data_set.size();
    pack(ss, set_size);
    auto iter = data_set.begin();
    while(iter != data_set.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template <typename T>
inline void unpack(std::stringstream& ss, std::set<T>& data_set)
{
    unsigned int set_size;
    unpack(ss, set_size);
    for(unsigned int i = 0; i < set_size; ++i) {
        T data;
        unpack(ss, data);
        data_set.insert(data);
    }
}

template<typename T>
inline void pack(std::stringstream& ss, const std::multiset<T>& data_multiset)
{
    unsigned int multiset_size = (unsigned int)data_multiset.size();
    pack(ss, multiset_size);
    auto iter = data_multiset.begin();
    while(iter != data_multiset.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template<typename T>
inline void unpack(std::stringstream& ss, std::multiset<T>& data_multiset)
{
    unsigned int multiset_size;
    unpack(ss, multiset_size);
    for(unsigned int i = 0; i < multiset_size; ++i) {
        T data;
        unpack(ss, data);
        data_multiset.insert(data);
    }
}

template<typename T>
inline void pack(std::stringstream& ss, const std::unordered_set<T>& data_unordered_set)
{
    unsigned int unordered_set_size = (unsigned int)data_unordered_set.size();
    pack(ss, unordered_set_size);
    auto iter = data_unordered_set.begin();
    while(iter != data_unordered_set.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template<typename T>
inline void unpack(std::stringstream& ss, std::unordered_set<T>& data_unordered_set)
{
    unsigned int unordered_set_size;
    unpack(ss, unordered_set_size);
    for(unsigned int i = 0; i < unordered_set_size; ++i) {
        T data;
        unpack(ss, data);
        data_unordered_set.insert(data);
    }
}

template<typename T>
inline void pack(std::stringstream& ss, const std::unordered_multiset<T>& data_unordered_multiset)
{
    unsigned int unordered_multiset_size = (unsigned int)data_unordered_multiset.size();
    pack(ss, unordered_multiset_size);
    auto iter = data_unordered_multiset.begin();
    while(iter != data_unordered_multiset.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template<typename T>
inline void unpack(std::stringstream& ss, std::unordered_multiset<T>& data_unordered_multiset)
{
    unsigned int unordered_multiset_size;
    unpack(ss, unordered_multiset_size);
    for(unsigned int i = 0; i < unordered_multiset_size; ++i) {
        T data;
        unpack(ss, data);
        data_unordered_multiset.insert(data);
    }
}

template <typename K, typename V>
inline void pack(std::stringstream& ss, const std::pair<K, V>& data_pair)
{
    pack(ss, data_pair.first);
    pack(ss, data_pair.second);
}

template <typename K, typename V>
inline void unpack(std::stringstream& ss, std::pair<K, V>& data_pair)
{
    unpack(ss, data_pair.first);
    unpack(ss, data_pair.second);
}

template <typename K, typename V>
inline void pack(std::stringstream& ss, const std::map<K, V>& data_map)
{
    unsigned int map_size = (unsigned int)data_map.size();
    pack(ss, map_size);
    auto iter = data_map.begin();
    while(iter != data_map.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template <typename K, typename V>
inline void unpack(std::stringstream& ss, std::map<K, V>& data_map)
{
    unsigned int map_size;
    unpack(ss, map_size);
    for(unsigned int i = 0; i < map_size; ++i) {
        std::pair<K,V> data_pair;
        unpack(ss, data_pair);
        data_map.insert(data_pair);
    }
}

template <typename K, typename V>
inline void pack(std::stringstream& ss, const std::multimap<K, V>& data_multimap)
{
    unsigned int multimap_size = (unsigned int)data_multimap.size();
    pack(ss, multimap_size);
    auto iter = data_multimap.begin();
    while(iter != data_multimap.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template <typename K, typename V>
inline void unpack(std::stringstream& ss, std::multimap<K, V>& data_multimap)
{
    unsigned int multimap_size;
    unpack(ss, multimap_size);
    for(unsigned int i = 0; i < multimap_size; ++i) {
        std::pair<K,V> data_pair;
        unpack(ss, data_pair);
        data_multimap.insert(data_pair);
    }
}

template <typename K, typename V>
inline void pack(std::stringstream& ss, const std::unordered_map<K, V>& data_unordered_map)
{
    unsigned int unordered_map_size = (unsigned int)data_unordered_map.size();
    pack(ss, unordered_map_size);
    auto iter = data_unordered_map.begin();
    while(iter != data_unordered_map.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template <typename K, typename V>
inline void unpack(std::stringstream& ss, std::unordered_map<K, V>& data_unordered_map)
{
    unsigned int unordered_map_size;
    unpack(ss, unordered_map_size);
    for(unsigned int i = 0; i < unordered_map_size; ++i) {
        std::pair<K,V> data_pair;
        unpack(ss, data_pair);
        data_unordered_map.insert(data_pair);
    }
}

template <typename K, typename V>
inline void pack(std::stringstream& ss, const std::unordered_multimap<K, V>& data_unordered_multimap)
{
    unsigned int unordered_multimap_size = (unsigned int)data_unordered_multimap.size();
    pack(ss, unordered_multimap_size);
    auto iter = data_unordered_multimap.begin();
    while(iter != data_unordered_multimap.end()) {
        pack(ss, *iter);
        ++iter;
    }
}

template <typename K, typename V>
inline void unpack(std::stringstream& ss, std::unordered_multimap<K, V>& data_unordered_multimap)
{
    unsigned int unordered_multimap_size;
    unpack(ss, unordered_multimap_size);
    for(unsigned int i = 0; i < unordered_multimap_size; ++i) {
        std::pair<K,V> data_pair;
        unpack(ss, data_pair);
        data_unordered_multimap.insert(data_pair);
    }
}

template <typename T>
class enumWrapper
{
public:
    enumWrapper(){}
    enumWrapper(const T& val): value(val) {}
    ~enumWrapper(){}
    enumWrapper& operator=(const T& val) {
        value = val;
        return *this;
    }

    int value;
};

template <typename T>
inline void pack(std::stringstream& ss, const enumWrapper<T>& data)
{
    int val = data.value;
    pack(ss, val);
}

template <typename T>
inline void unpack(std::stringstream& ss, enumWrapper<T>& data)
{
    int val;
    unpack(ss, val);
    data.value = val;
}

