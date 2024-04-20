#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;



// 给定一个字符串，通过添加"."的方式，将它拆分为合法的IP v4地址，输出所有可能结果
// eg: SplitIP("2883174") -> {"2.8.83.174", "2.88.3.174", "2.88.31.74", "28.8.3.174", "28.8.31.74", "28.83.1.74", "28.83.17.4"};
int main(){


    string ip;
    cin >> ip;
    int length = ip.size();
    if (length>12||length<4)
    {
        return -1;
    }
    //每个子字符串的长度为1~3
    for ( int i = 1; i < 4; i++){
        for (int j = 1; j < 4; j++){
            for (int k = 1; k < 4; k++){
                for (int m = 1; m < 4; m++){
                    if (
                        //四个子字符串长度之和为string ip的长度。
                            (length==i+j+k+m)
                            //每个子字符串的“值”不能超过255
                            &&(atoi(ip.substr(0,i).c_str())<=255)
                            &&(atoi(ip.substr(i,j).c_str())<=255)
                            &&(atoi(ip.substr(i+j,k).c_str())<=255)
                            &&(atoi(ip.substr(i+j+k,m).c_str())<=255)
                            ){
                        cout << ip.substr(0, i) << "." << ip.substr(i, j) << "." << ip.substr(i+j, k) << "." << ip.substr(i+j+k, m) << endl;
                    }
                }
            }
        }
    }
    system("pause");
    return 0;
}

