// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>


//题目：病人预约医生。对每一个病人i, A[i]和B[i]是病人愿意预约的时间，两个任选一个；
//      S是医生拥有的时间，即1~S都可以预约
//      A和B的每一个元素的范围是：[1, S]
//      给定A、B、S，判断医生的档期是否满足病人的预约要求

// 正确性通过率90%，性能通过率0%

using namespace std;

bool dfs(int i, unordered_set<int>& tset, vector<int>& A, vector<int>& B) {
    if (i == A.size()) return true;

    int leftBranch = A[i];
    int rightBranch = B[i];

    bool flag1 = false, flag2 = false;

    if (tset.find(leftBranch) == tset.end()) {
        tset.insert(leftBranch);
        flag1 = dfs(i + 1, tset, A, B);
        tset.erase(leftBranch);
    }

    if (tset.find(rightBranch) == tset.end()) {
        tset.insert(rightBranch);
        flag2 = dfs(i + 1, tset, A, B);
        tset.erase(rightBranch);
    }

    return flag1 || flag2;
}


bool solution(vector<int> &A, vector<int> &B, int S) {
    // Implement your solution here
    int pCount = A.size();
    if(S<pCount) {
        return false;
    }

    unordered_set<int> tset;
    return dfs(0, tset, A, B);
}





