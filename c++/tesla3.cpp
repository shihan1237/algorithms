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


//第三题，遍历每一个病人，判断其是否能被分配时间槽；若所有人都能正常分配，返回true。怎么判断是否能被分配时间槽？递归函数：
//dfs:
//1、每次遍历要维护一个visited list，判断一次递归有没有访问过；如果访问过就不在dfs中访问第二次；
//2、维护一个match的map，记录每一个时间槽v对应的病人u；
//3、bpm处理一个病人u，遍历其所有候选的槽v。完成visited判定和v是否已被占用的判定，
// 若visited[v]为空则直接占用，获取被占用的病人id u2, 将其挪走。


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





