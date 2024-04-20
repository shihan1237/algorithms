

/*
 * 两个多项式相加，用一个链表表达一个多项式
 * 每个链表的每个结点中有指数和底数，比如 3 * x ^ 2 + x + 1用链表来表达是： node(3, 2) -> node(1, 1) -> node(1,0)
 * 求两个链表相加之和，结果用一个新链表来表示
 */





#include <iostream>

#include <vector>
#include <map>

#include <queue>
using namespace std;



struct Node {
    long coefficient;
    long power;
};

vector<Node> PolyNodeSum(vector<Node> &poly1, vector<Node> &poly2){

    size_t iter1 = 0, iter2 = 0;
    vector<Node> res;
    while(iter1 < poly1.size() && iter2 < poly2.size()){
        Node &node1 = poly1[iter1];
        Node &node2 = poly2[iter2];
        Node tmpNode{};
        if(node1.power > node2.power) {
            tmpNode.power = node1.power;
            tmpNode.coefficient = node1.coefficient;
            iter1++;
        } else if (node1.power < node2.power) {
            tmpNode.power = node2.power;
            tmpNode.coefficient = node2.coefficient;
            iter2++;
        } else {
            tmpNode.power = node1.power;
            tmpNode.coefficient = node1.coefficient + node2.coefficient;
            iter1++;
            iter2++;
        }
        if(tmpNode.coefficient != 0) {
            res.emplace_back(tmpNode);
        }
    }
    if (iter1 >= poly1.size()) {
        while(iter2 < poly2.size()){
            Node node2 = poly2[iter2];
            if(node2.coefficient != 0) {
                res.emplace_back(node2);
            }
            iter2++;
        }
    }

    if (iter2 >= poly2.size()) {
        while(iter1 < poly1.size()){
            Node node1 = poly1[iter1];
            if(node1.coefficient != 0) {
                res.emplace_back(node1);
            }
            iter1++;
        }
    }

    return res;
}

void TESTCASE1(){
    vector<Node> poly1{
            {1, 1}
    };

    vector<Node> poly2{
            {1, 0}
    };
    vector<Node> res = PolyNodeSum(poly1, poly2);
    for(const auto &item: res) {
        std::cout<<item.coefficient;
        std::cout<<item.power;
        std::cout<<"  ";
    }
    std::cout<<std::endl;
}


void TESTCASE2(){
    vector<Node> poly1{
            {2,2},
            {4, 1},
            {3,0}
    };

    vector<Node> poly2{
            {3,2},
            {-4,1},
            {-1,0},
    };
    vector<Node> res = PolyNodeSum(poly1, poly2);
    for(const auto &item: res) {
        std::cout<<item.coefficient<<" ";
        std::cout<<item.power;
    }
    std::cout<<std::endl;

}

void TESTCASE3(){
    vector<Node> poly1{
            {1,2}
    };

    vector<Node> poly2{
            {-1,2}
    };
    vector<Node> res = PolyNodeSum(poly1, poly2);
    for(const auto &item: res) {
        std::cout<<item.coefficient<<" ";
        std::cout<<item.power;
    }
    std::cout<<std::endl;

}


struct Cmp {
    bool operator()(const int &p1, const int &p2){
        return p1 > p2;

    }
};

int main() {
    TESTCASE1();
    TESTCASE2();
    TESTCASE3();

    priority_queue<int, vector<int>, Cmp> pq;

    pq.push(0);
    pq.push(1);
    pq.push(2);

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        //cout<<pq.top().x<<" "<<pq.top().y<<endl;
        pq.pop();
    }



//    map<int, int> amap;
    map<int, int, Cmp> amap;
    amap[0] = 0;
    amap[1] = 1;
    amap[2] = 2;
    amap[3] = 3;




    std::cout<<(--amap.end())->first;



    return 0;
}





















