[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.

## Data cleanup
The program will only import/read the properties defined in Product class
1. uni_id
2. product_name
3. brand_name
4. List of category
5. price

# Testing
## Test 1 Insert Operation
Case 1: Normal insertion
Case 2: Edge case, insert into table size-1

## Test 2 Find Operation
Case 1: Normal find existing keys
Case 2: Edge case, find non-existent key

## Test 3 Remove Operation
Case 1: Normal removing existing key
Case 2: Edge case, remove non-existent key

## Test 4 Load Factor
Case 1: Normal load under 0.7
Case 2: Edge case, more than 0.7 load

## Test 5 Chaining Collision
Case 1: Small collision
Case 2: Edge case, all collision