#include <iostream>
#include <string>
#include <sstream>
#include "hash_table.hpp"
#include "parser.hpp"

using namespace std;

void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory \"<category_string>\" - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

void evalCommand(string line, HashTable<string, Product>* id_table, HashTable<string, vector<string>>* categories_table)
{
    if (line == ":help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        istringstream iss(line);
        string command, inventory_id;
        iss >> command >> inventory_id;
        // Look up the appropriate datastructure to find if the inventory exist
        Product* product = id_table->find(inventory_id);
        cout << *product << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        string category = parse_command(line);

        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        vector<string>* products_id = categories_table->find(category);
        if (products_id == nullptr || products_id->empty())
        {
            cout << "Invalid Category" << endl;
        }else {
            cout << "Products in category " << category << ":" << endl;
            for (const auto& product_id : *products_id)
            {
                Product* product = id_table->find(product_id);
                if(product != nullptr){
                    cout << *product << endl;
                }
            }
        }
    }
}

void bootStrap(HashTable<string, Product>* id_table, HashTable<string, vector<string>>* categories_table)
{
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
    read_csv("amazon_inventory.csv", id_table, categories_table);
}

int main(int argc, char const *argv[])
{
    HashTable<string, Product> id_table(14293);
    HashTable<string, vector<string>> categories_table(127);
    string line;
    bootStrap(&id_table, &categories_table);
    
    while (getline(cin, line) && line != ":quit")
    {
        if (validCommand(line))
        {
            evalCommand(line, &id_table, &categories_table);
        }
        else
        {
            cout << "Command not supported. Enter :help for list of supported commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
