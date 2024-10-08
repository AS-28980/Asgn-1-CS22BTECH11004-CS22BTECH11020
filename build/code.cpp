#include <iostream>
#include <deque>
#include <map>
using namespace std;

 
#define int int 
#define float float 
float total_area(deque <float> h, deque <int> b){
float sum = 0;
 for (int i = 0; i < h.size() && i < b.size(); i = i + 1){
sum = sum + h[i] * b[i];

}
  return sum;

} 

signed main(void){
deque <float> h, b;
 a.push_back(0.5);
 b.push_back(3);
 a.push_back(1.5);
 b.push_back(2);
 a.push_back(2.5);
 b.push_back(1);
 cout << total_area(h, b);

return 0;
}
