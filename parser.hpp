/*
    Name: Khoa Ta
    Assignment: PA3
    parser function header
*/

#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "hash_table.hpp"
#include "product.hpp"

using std::string;
using std::fstream;
using std::vector;
using std::istringstream;

void read_csv(string filename, HashTable<string, Product>* id_table, HashTable<string, vector<string>>* category_table);

vector<string> parse_line(string line, int num_components, char delimiter);

string parse_command(string line);