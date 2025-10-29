/*
    Name: Khoa Ta
    Assignment: PA3
    hash table template
*/

#pragma once
#include <string>
#include <vector>
#include <utility>

using std::vector;
using std::string;

template<typename K, typename V>
class HashTable {
    private:
        int TABLE_SIZE = 128;
        vector<vector<std::pair<K, V>>> table;

        std::hash<K> hashFunction;
        double load_factor;
        int num_elements;

    public:
        HashTable(int start_size):TABLE_SIZE(start_size), load_factor(0.0), num_elements(0){
            table.resize(TABLE_SIZE);
        }

        HashTable(HashTable& other):TABLE_SIZE(other.TABLE_SIZE), load_factor(other.load_factor), num_elements(other.num_elements){
            table = other.table;
        }

        ~HashTable() {}

        void insert(const K& key, const V& value) {
            size_t index = hashFunction(key) % TABLE_SIZE;

            for (auto& p: table[index]){
                if (p.first == key){
                    p.second = value;
                    return;
                }
            }
            table[index].push_back({key, value});
            num_elements++;
            load_factor = calculate_load();

            if (load_factor > 0.7){
                rehash(TABLE_SIZE * 2);
            }
        }

        V* find(const K& key) {
            size_t index = hashFunction(key) % TABLE_SIZE;
            
            for (auto& p : table[index]){
                if (p.first == key){
                    return &(p.second);
                }
            }
            return nullptr;
        }

        void remove(const K& key) {
            size_t index = hashFunction(key) % TABLE_SIZE;
    
            auto& bucket = table[index];
            for (auto it = bucket.begin(); it != bucket.end(); ++it) {
                if (it->first == key) {
                    bucket.erase(it);
                    num_elements--;
                    return;
                }
            }
        }

        void rehash(int new_size) {
            if (new_size <= TABLE_SIZE) return;

            vector<vector<std::pair<K, V>>> old_table = table;
            int old_size = TABLE_SIZE;

            TABLE_SIZE = new_size;
            table.clear();
            table.resize(TABLE_SIZE);
            num_elements = 0;

            for (int i = 0; i < old_size; i++) {
                for (auto& p : old_table[i]) {
                    insert(p.first, p.second);
                }
            }
        }

        double calculate_load(){
            return (double)num_elements / TABLE_SIZE;
        }
};
