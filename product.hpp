/*
    Name: Khoa Ta
    Assignment: PA3
    product class header
*/

#pragma once
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::ostream;
using std::cout;
using std::endl;

class Product {
    public:
        string uni_id;
        string prod_name;
        string brand_name;
        vector<string> category;
        string price;

        Product(string uni_id, string prod_name, string brand_name, vector<string> category, string price);

        friend ostream& operator<<(ostream& rhs, const Product& lhs);
};

