/*
    Name: Khoa Ta
    Assignment: PA3
    parser functions
*/

#include "parser.hpp"

void read_csv(string filename, HashTable<string, Product>* id_table, HashTable<string, vector<string>>* categories_table){
    fstream file;
    file.open(filename, std::ios::in);
    string line;
    getline(file, line);
    while (getline(file,line)){
        vector<string> components = parse_line(line, 8, ',');

        vector<string> categories = parse_line(components[4], -1, '|');

        Product product = Product(components[0],
            components[1],
            components[2],
            categories,
            components[7]);

        id_table->insert(components[0], product);

        for (string category : categories) {
            vector<string>* product_list = categories_table->find(category);

            if (product_list != nullptr){
                product_list->push_back(product.uni_id);
            }else{
                vector<string> new_list;
                new_list.push_back(product.uni_id);
                categories_table->insert(category, new_list);
            }
        }
    }
    file.close();
}

vector<string> parse_line(string line, int num_components, char delimiter){
    vector<string> components;
    string currComponent;
    bool inQuotes = false;

    for (long unsigned int i=0; i < line.length(); i++){
        char c = line[i];

        if (c == '"'){
            if(inQuotes && i + 1 < line.length() && line[i+1] == '"'){
                currComponent += '"';
                i++;
            }else {
                inQuotes = !inQuotes;
            }
        }else if (c == delimiter && !inQuotes){
            if (num_components == 0){
                return components;
            }else if (num_components == -1){
                num_components++;
            }

            if (currComponent.empty()){
                components.push_back("N/A");
                currComponent.clear();
                continue;
            }

            if (currComponent[0] == ' ') currComponent = currComponent.substr(1);
            if (currComponent[ currComponent.length() -1 ] == ' ') 
                currComponent = currComponent.substr(0, currComponent.length() -1);

            components.push_back(currComponent);

            currComponent.clear();
            num_components--;
            
        }else{
            currComponent += c;
        }
    }
    components.push_back(currComponent);

    return components;
}

string parse_command(string line){
    size_t quote_start = line.find('"');
        size_t quote_end = line.rfind('"');
        string parameter;

        if (quote_start != string::npos && quote_end != string::npos && quote_start < quote_end){
            parameter = line.substr(quote_start + 1, quote_end - quote_start - 1);
        }else{
            istringstream iss(line);
            string command;
            iss >> command;
            std::getline(iss, parameter);

            size_t start = parameter.find_first_not_of(" \t");
            if (start != string::npos) {
                parameter = parameter.substr(start);
            }
        }

    return parameter;
}