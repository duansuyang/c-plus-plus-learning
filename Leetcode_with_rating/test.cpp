#include <iostream>
#include <typeinfo>
using namespace std;

// class Solution {
// public:
//     vector<int> runningSum(vector<int>& nums) {
        



//     }
// }



int main(){
    double a = 3.14;
    int b = static_cast<int>(a);  // 显示将浮点数转换为整数
    cout << b << endl;

    float x = 2.5;
    int y = (int)x;  // 显示将浮点数转换为整数

    long m = 1000;
    int n = static_cast<int>(m);  // 显示将长整数转换为整数
}