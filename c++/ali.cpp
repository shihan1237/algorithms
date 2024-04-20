//评测题目一: 比较版本号大小。
// 规则是依次比较前4位数字的大小，不足4位的用0补充, 直到有一位比较出大小为止。
// 如:
// "1.0"=="1.0.0.0"
// "1.0.1">"1.0"
// "1.2.0">"1.1.
// 题目一请补充必要的测试用例

#include <iostream>
#include <unordered_map>
#include <vector>
#include <assert.h>
#include <math.h>


char CompareString(const std::string &str1, const std::string &str2) {
    size_t length1 = str1.length();
    size_t length2 = str2.length();
    size_t i = 0, j = 0;

    while (i < length1 || j < length2) {

        char a = i >= length1? '0' : str1[i];
        char b = j >= length2? '0' : str2[j];

        if(a != b && a != '.' && b != '.') {
            return a < b ? '<' : '>';
        }

        i++;
        j++;

    }
    return '=';
}

void TESTCASE1() {
    std::string str1 = "1.0";
    std::string str2 = "1.0.0.0";
    assert(CompareString(str1, str2) == '=');
}


void TESTCASE2() {
    std::string str1 = "1.0.1";
    std::string str2 = "1.0";
    assert(CompareString(str1, str2) == '>');
}



void TESTCASE3() {
    std::string str1 = "1.2.0";
    std::string str2 = "1.1.0";
    assert(CompareString(str1, str2) == '>');
}





//评测题目二:  计算岛屿的最大面积。
//给定一个二维的矩阵，包含 ‘1’ 和 ‘0’
// ‘1’（陆地）和 ‘0’（水），由这些组成的的岛屿，计算岛屿的最大面积。
//解释：一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
//你可以假设网格的四个边均被水包围。
//输入:
//11000
//11000
//00100
//00011
//输出：4
// 题目二请补充必要的测试用例


std::unordered_map<int, std::unordered_map<int, int>> visitedMap;
int maxLengthForX;
int maxLengthForY;
int maxSquare = 0;


void dfs(size_t i, size_t j, std::vector<std::vector<int>> &input, int curSquare) {
    if(i < 0 || i >= maxLengthForX || j < 0 || j >= maxLengthForY) {
        return;
    }

    if(visitedMap[i][j] == 1 || input[i][j] == 0) {
        return;
    }

    visitedMap[i][j] = 1;
    curSquare++;
    maxSquare = fmax(maxSquare, curSquare);

    dfs(i-1, j, input, curSquare);
    dfs(i+1, j, input, curSquare);
    dfs(i, j-1, input, curSquare);
    dfs(i, j+1, input, curSquare);
}


size_t GetMaxIslandSquare(std::vector<std::vector<int>> input) {
    if(input.size() == 0) {
        return 0;
    }
    maxLengthForX = input.size();
    maxLengthForY = input[0].size();

    for(size_t i = 0; i < maxLengthForX; i++) {
        for(size_t j = 0; j < maxLengthForY; j++) {
            dfs(i, j, input, 0);
        }
    }
    return maxSquare;
}


void TESTCASE4() {
    std::vector<std::vector<int>> input{
            {1, 1, 0 ,0 ,0},
            {1, 1, 0 ,0 ,0},
            {0, 0, 1 ,0 ,0},
            {0, 0, 0 ,1 ,1}};
    auto res = GetMaxIslandSquare(input);
    assert(res == 4);
}


int main() {
    TESTCASE1();
    TESTCASE2();
    TESTCASE3();
    TESTCASE4();

}












