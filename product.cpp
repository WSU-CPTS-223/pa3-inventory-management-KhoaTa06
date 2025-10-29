/*
    Name: Khoa Ta
    Assignment: PA3
    product class implementation
*/

#include "product.hpp"

Product::Product(string uni_id, string prod_name, string brand_name, vector<string> category, string price){
    this->uni_id = uni_id;
    this->prod_name = prod_name;
    this->brand_name = brand_name;
    this->category = category;
    this->price = price;
}

ostream& operator<<(ostream& rhs, const Product& lhs) {
    rhs << "ID: " << lhs.uni_id << endl;
    rhs << "Name: " << lhs.prod_name << endl;
    rhs << "Brand: " << lhs.brand_name << endl;
    rhs << "Categories: ";
    for (const auto& cat : lhs.category) {
        rhs << cat << " | ";
    }
    rhs << endl;
    rhs << "Price: " << lhs.price << endl;
    return rhs;
}