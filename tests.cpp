/*
    Name: Khoa Ta
    Assignment: PA3
    test functions
*/

#include "tests.hpp"

// Test 1: Insert Operation
void test_insert() {
    cout << "Testing INSERT" << endl;
    
    // Normal case: Insert multiple key-value pairs
    cout << "Normal insert" << endl;
    HashTable<string, int> table(10);
    
    table.insert("apple", 5);
    table.insert("banana", 10);
    table.insert("cherry", 15);
    
    int* val1 = table.find("apple");
    int* val2 = table.find("banana");
    int* val3 = table.find("cherry");
    
    assert(val1 != nullptr && *val1 == 5);
    assert(val2 != nullptr && *val2 == 10);
    assert(val3 != nullptr && *val3 == 15);
    cout << "Test passed" << endl;
    
    // Edge case: Insert into small table (size 1)
    cout << "Insert into size-1 table" << endl;
    HashTable<string, string> small_table(1);
    
    small_table.insert("key1", "value1");
    small_table.insert("key2", "value2");
    small_table.insert("key3", "value3");
    
    string* s1 = small_table.find("key1");
    string* s2 = small_table.find("key2");
    string* s3 = small_table.find("key3");
    
    assert(s1 != nullptr && *s1 == "value1");
    assert(s2 != nullptr && *s2 == "value2");
    assert(s3 != nullptr && *s3 == "value3");
    cout << "Test passed" << endl;
}

// Test 2: Find Operation
void test_find() {
    cout << "\nTesting FIND Operation" << endl;
    
    // Normal case: Find existing keys
    cout << "Find existing keys" << endl;
    HashTable<string, double> table(20);
    
    table.insert("apple", 5);
    table.insert("banana", 10);
    table.insert("cherry", 15);

    double* apple = table.find("apple");
    double* banana = table.find("banana");
    double* cherry = table.find("cherry");

    assert(apple != nullptr && *apple == 5);
    assert(banana != nullptr && *banana == 10);
    assert(cherry != nullptr && *cherry == 15);
    cout << "Test passed" << endl;
    
    // Edge case: Find non-existent key
    cout << "Find non-existent key..." << endl;
    double* notfound = table.find("nonexistent");
    assert(notfound == nullptr);
    cout << "Test passed" << endl;
}

// Test 3: Remove Operation
void test_remove() {
    cout << "Testing REMOVE Operation" << endl;
    
    // Normal case: Remove existing keys
    cout << "Remove existing keys" << endl;
    HashTable<string, int> table(15);
    
    table.insert("one", 1);
    table.insert("two", 2);
    table.insert("three", 3);
    
    // Verify they exist
    assert(table.find("one") != nullptr);
    assert(table.find("two") != nullptr);
    
    // Remove one
    table.remove("two");
    
    // Verify removal
    assert(table.find("one") != nullptr);
    assert(table.find("two") == nullptr);
    assert(table.find("three") != nullptr);
    cout << "Test passed" << endl;
    
    // Edge case: Remove non-existent key
    cout << "Remove non-existent key" << endl;
    table.remove("nonexistent");  // Should not crash
    
    // Verify other keys still exist
    assert(table.find("one") != nullptr);
    assert(table.find("three") != nullptr);
    cout << "Test passed" << endl;
}

// Test 4: Load Factor Calculation
void test_load_factor() {
    cout << "Testing LOAD FACTOR Calculation" << endl;
    
    // Normal case: Calculate load factor with multiple elements
    cout << "Load factor with multiple elements" << endl;
    HashTable<string, int> table(10);
    
    double initial_load = table.calculate_load();
    assert(initial_load == 0.0);
    
    table.insert("a", 1);
    table.insert("b", 2);
    table.insert("c", 3);
    table.insert("d", 4);
    table.insert("e", 5);
    
    double load = table.calculate_load();
    assert(load == 0.5);  // 5 elements / 10 buckets
    cout << "Test passed (load = " << load << ")" << endl;
    
    // Edge case: Full table (100% load factor)
    cout << "Load factor with full table" << endl;
    HashTable<int, string> small_table(5);
    
    small_table.insert(1, "one");
    small_table.insert(2, "two");
    small_table.insert(3, "three");
    small_table.insert(4, "four");
    small_table.insert(5, "five");
    
    double full_load = small_table.calculate_load();
    assert(full_load <= 0.7);  // 5 elements / 5 buckets
    cout << "Test passed (load = " << full_load << ")" << endl;
}

// Test 5: Collision Handling (Chaining)
void test_collisions() {
    cout << "Testing COLLISION Handling" << endl;
    
    // Normal case: Force collisions with small table
    cout << "Multiple keys in same bucket" << endl;
    HashTable<string, int> table(5);  // Small table to force collisions
    
    // Insert many items to guarantee collisions
    table.insert("key1", 100);
    table.insert("key2", 200);
    table.insert("key3", 300);
    table.insert("key4", 400);
    table.insert("key5", 500);
    table.insert("key6", 600);
    table.insert("key7", 700);
    table.insert("key8", 800);
    
    // All should be retrievable despite collisions
    int* v1 = table.find("key1");
    int* v2 = table.find("key2");
    int* v5 = table.find("key5");
    int* v8 = table.find("key8");
    
    assert(v1 != nullptr && *v1 == 100);
    assert(v2 != nullptr && *v2 == 200);
    assert(v5 != nullptr && *v5 == 500);
    assert(v8 != nullptr && *v8 == 800);
    cout << "Test passed" << endl;
    
    // Edge case: All keys hash to same bucket (size 1 table)
    cout << "All keys in single bucket" << endl;
    HashTable<string, string> single_bucket(1);
    
    single_bucket.insert("a", "alpha");
    single_bucket.insert("b", "beta");
    single_bucket.insert("c", "gamma");
    single_bucket.insert("d", "delta");
    
    string* alpha = single_bucket.find("a");
    string* beta = single_bucket.find("b");
    string* gamma = single_bucket.find("c");
    string* delta = single_bucket.find("d");
    
    assert(alpha != nullptr && *alpha == "alpha");
    assert(beta != nullptr && *beta == "beta");
    assert(gamma != nullptr && *gamma == "gamma");
    assert(delta != nullptr && *delta == "delta");
    cout << "Test passed" << endl;
}



// Run all tests
void run_all_tests() {
    cout << "Run all tests" << endl;
    
    test_insert();
    test_find();
    test_remove();
    test_load_factor();
    test_collisions();
    
    cout << "ALL TESTS PASSED!" << endl;
}

int main(void){
    run_all_tests();
    return 0;
}
