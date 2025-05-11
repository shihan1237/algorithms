// you can use includes, for example:
// #include <algorithm>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>


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

bool bpm(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& matchTo) {
    for (int v : graph[u]) {
        if (!visited[v]) {
            visited[v] = true;
            // 如果 v 没被匹配，或者可以“挪开”v 的原匹配
            if (matchTo[v] == -1 || bpm(matchTo[v], graph, visited, matchTo)) {
                matchTo[v] = u;  // u 配对给 v
                return true;
            }
        }
    }
    return false;
}



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



#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

bool dpSolution(vector<int> &A, vector<int> &B, int S) {
    int pCount = A.size();
    if (S < pCount) {
        return false;
    }

    // dp[i][j] 表示处理到第 i 个病人时，医生的时间表状态为 j 是否可行
    vector<vector<bool>> dp(pCount + 1, vector<bool>(1 << S, false));
    dp[0][0] = true; // 初始状态没有病人时，时间表为空是可行的

    for (int i = 1; i <= pCount; ++i) {
        for (int j = 0; j < (1 << S); ++j) {
            if (dp[i - 1][j]) {
                // 尝试选择 A[i-1]
                if ((j & (1 << (A[i - 1] - 1))) == 0) {
                    dp[i][j | (1 << (A[i - 1] - 1))] = true;
                }
                // 尝试选择 B[i-1]
                if ((j & (1 << (B[i - 1] - 1))) == 0) {
                    dp[i][j | (1 << (B[i - 1] - 1))] = true;
                }
            }
        }
    }

    // 检查是否存在一个状态使得所有病人都被安排
    for (int j = 0; j < (1 << S); ++j) {
        if (dp[pCount][j]) {
            return true;
        }
    }

    return false;
}

int main() {
    using namespace std;
    vector<int> A = {1, 2, 3};
    vector<int> B = {2, 1, 4};
    int S = 4;

//    bool result = solution(A, B, S);
    bool result = dpSolution(A, B, S);
    cout << "Result: " << (result ? "true" : "false") << endl; // 应输出 true

    return 0;
}
