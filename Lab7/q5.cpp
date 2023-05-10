#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <chrono>
using namespace std;
int random(int min, int max) {
 return min + (rand() % (max - min + 1));
}
template <typename T>
double search_time(T& table, int key) {
 auto start = chrono::high_resolution_clock::now();
 table.find(key);
 auto end = chrono::high_resolution_clock::now();
 return chrono::duration_cast<chrono::microseconds>(end - start).count();
}
template <typename T>
double remove_time(T& table, int key) {
 auto start = chrono::high_resolution_clock::now();
 table.erase(key);
 auto end = chrono::high_resolution_clock::now();
 return chrono::duration_cast<chrono::microseconds>(end - start).count();
}
int main() {
 const int n = 10000;
 int a[n];
 for (int i = 0; i < n; i++) {
 a[i] = random(1, 1000000);
 }
 unordered_map<int, int> linear_probing;
 unordered_map<int, int> quadratic_probing;
 unordered_map<int, int> double_hashing;
 unordered_map<int, int> chaining;
 for (int i = 0; i < n; i++) {
 linear_probing[a[i]] = a[i];
 quadratic_probing[a[i]] = a[i];
 double_hashing[a[i]] = a[i];
 chaining[a[i]] = a[i];
 }
 int key = random(1, 1000000);
 double lp_time = search_time(linear_probing, key);
 double qp_time = search_time(quadratic_probing, key);
 double dh_time = search_time(double_hashing, key);
 double ch_time = search_time(chaining, key);
 key = random(1, 1000000);
 lp_time = remove_time(linear_probing, key);
 qp_time = remove_time(quadratic_probing, key);
 dh_time = remove_time(double_hashing, key);
 ch_time = remove_time(chaining, key);
 cout << "Linear probing search time: " << lp_time << " microseconds" << endl;
 cout << "Quadratic probing search time: " << qp_time << " microseconds" << endl;
 cout << "Double hashing search time: " << dh_time << " microseconds" << endl;
 cout << "Chaining search time: " << ch_time << " microseconds" << endl;
 cout << "Linear probing remove time: " << lp_time << " microseconds" << endl;
 cout << "Quadratic probing remove time: " << qp_time << " microseconds" << endl;
 cout << "Double hashing remove time: " << dh_time << " microseconds" << endl;
 cout << "Chaining search remove time: " << ch_time << " microseconds" << endl;
}