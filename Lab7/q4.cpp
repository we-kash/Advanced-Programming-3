#include <iostream>
#include <vector>
#include <chrono>
#include <random>
const int TABLE_SIZE = 10000;
class HashTable {
public:
 HashTable() {
 table_.resize(TABLE_SIZE, -1);
 }
 void insert(int key) {
 int index = hash(key);
 int i = 1;
 while (table_[index] != -1) {
 index = (index + i * i) % TABLE_SIZE;
 i++;
 }
 table_[index] = key;
 }
 bool search(int key) {
 int index = hash(key);
 int i = 1;
 while (table_[index] != -1) {
 if (table_[index] == key) {
 return true;
 }
 index = (index + i * i) % TABLE_SIZE;
 i++;
 }
 return false;
 }
 double load_factor() {
 int count = 0;
 for (auto& key : table_) {
 if (key != -1) {
 count++;
 }
 }
 return static_cast<double>(count) / TABLE_SIZE;
 }
public:
 int hash(int key) {
 return key % TABLE_SIZE;
 }
 std::vector<int> table_;
};
int main() {
 HashTable ht;
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<> dis(1, 100000);
 for (int i = 0; i < 2000; ++i) {
 int num = dis(gen);
 ht.insert(num);
 }
 for (auto& key : ht.table_) {
 if (key != -1) {
 std::cout << key << " ";
 }
 }
 std::cout << std::endl;
 double lf = ht.load_factor();
 std::cout << "Load factor: " << lf << std::endl;
 int search_num = dis(gen);
 auto start = std::chrono::high_resolution_clock::now();
 bool found = ht.search(search_num);
 auto end = std::chrono::high_resolution_clock::now();
 std::chrono::duration<double> diff = end - start;
 std::cout << "Time to search for " << search_num << ": " << diff.count() << " seconds"
<< std::endl;
 int insert_num = dis(gen);
 start = std::chrono::high_resolution_clock::now();
 ht.insert(insert_num);
 end = std::chrono::high_resolution_clock::now();
 diff = end - start;
 std::cout << "Time to insert " << insert_num << ": " << diff.count() << " seconds" <<
std::endl;
 std::vector<double> load_factors {0.5, 0.75, 0.9};
 for (auto lf : load_factors) {
 HashTable ht;
 int num_elements = static_cast<int>(lf * TABLE_SIZE);
 for (int i = 0; i < num_elements; ++i) {
 int num = dis(gen);
 ht.insert(num);
 }
 lf = ht.load_factor();
 std::cout << "Load factor: " << lf << std::endl;
 int search_num = dis(gen);
 start = std::chrono::high_resolution_clock::now();
 found = ht.search(search_num);
 end = std::chrono::high_resolution_clock::now();
 diff = end - start;
 std::cout << "Time to search for " << search_num << ": " << diff.count() << " seconds"
<< std::endl;
 int insert_num = dis(gen);
 start = std::chrono::high_resolution_clock::now();
 ht.insert(insert_num);
 end = std::chrono::high_resolution_clock::now();
 diff = end - start;
 std::cout << "Time to insert " << insert_num << ": " << diff.count() << " seconds" <<
std::endl;
 }
 return 0;
}