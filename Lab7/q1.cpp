#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <unordered_map>
int main() {
 std::unordered_map<int, int> hash_table;
 std::random_device rd;
 std::mt19937 gen(rd());
 std::uniform_int_distribution<> dis(1, 100000);
 for (int i = 0; i < 10000; ++i) {
 int num = dis(gen);
 hash_table[num] = i;
 }
 for (std::pair<const int, int>& p : hash_table) {
 std::cout << p.first << " ";
 }
 std::cout << std::endl;
 double load_factor = static_cast<double>(hash_table.size()) / hash_table.bucket_count();
 std::cout << "Load factor: " << load_factor << std::endl;
 int search_num = dis(gen);
 std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
 std::unordered_map<int, int>::iterator it = hash_table.find(search_num);
 std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
 std::chrono::duration<double> diff = end - start;
 std::cout << "Time to search for " << search_num << ": " << diff.count() << " seconds" <<
std::endl;
 int remove_num = dis(gen);
 start = std::chrono::high_resolution_clock::now();
 hash_table.erase(remove_num);
 end = std::chrono::high_resolution_clock::now();
 diff = end - start;
 std::cout << "Time to remove " << remove_num << ": " << diff.count() << " seconds" << std::endl;
 std::vector<double> load_factors {0.5, 0.75, 0.9};
 for (double lf : load_factors) {
 std::unordered_map<int, int> ht;
 int num_elements = static_cast<int>(lf * 10000);
 for (int i = 0; i < num_elements; ++i) {
 int num = dis(gen);
 ht[num] = i;
 }
 lf = static_cast<double>(ht.size()) / ht.bucket_count();
 std::cout << "Load factor: " << lf << std::endl;
 int search_num = dis(gen);
 start = std::chrono::high_resolution_clock::now();
 std::unordered_map<int, int>::iterator it = ht.find(search_num);
 end = std::chrono::high_resolution_clock::now();
 diff = end - start;
 std::cout << "Time to search for " << search_num << ": " << diff.count() << " seconds" <<
std::endl;
 int remove_num = dis(gen);
 start = std::chrono::high_resolution_clock::now();
 ht.erase(remove_num);
 end = std::chrono::high_resolution_clock::now();
 diff = end - start;
 std::cout << "Time to remove " << remove_num << ": " << diff.count() << " seconds" << std::endl;
 }
 return 0;
}