/*
    Name: Khoa Ta
    Assignment: PA3
    test function header
*/

#pragma once
#include <cassert>
#include <string>
#include <vector>
#include <iostream>
#include "hash_table.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Test 1: Insert operation
void test_insert();

// Test 2: Find operation
void test_find();

// Test 3: Remove operation
void test_remove();

// Test 4: Load factor calculation
void test_load_factor();

// Test 5: Collision handling
void test_collisions();

// Test 6: Update existing key
void test_update();

// Test 7: Empty table operations
void test_empty_table();

// Test 8: Large dataset
void test_large_dataset();

// Run all tests
void run_all_tests();
