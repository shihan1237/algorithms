// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>

//题目：对集合A中的整数，求最大子集，要求这个子集里的数求“按位与”的结果不为0

// 正确性通过率100%，性能通过率100%
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
int solution(vector<int> &A) {
    // Implement your solution here
    vector<int> hashVec(32, 0);
    for(auto &num : A) {
        for(int i = 0; i<32; i++) {
            if((num>>i) & 1 == 1) {
                hashVec[i]++;
            }
        }
    }
    int max = 0;
    for(auto i: hashVec) {
        max = fmax(max, i);
    }
    return max;
}
