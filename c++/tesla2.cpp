// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

// N个结点，vector<int> &A给出了父亲依赖关系，string &S给出了每个结点的字符
// 把相邻的，字符不同的结点串起来，找到最大的串，返回其长度



// 正确性通过率15%，性能通过率20%
// 用并查集分了不同的可通行区域以后，还应该剪枝，遍历每一个结点，如果它的边多于两个，则应该
// 划分可通行区域以后，是不是遍历连通区域内每一个结点，用bfs求它到其它结点的路径，取最大值即可？就和“网络传播时间”那道题一样
// 性能还是不好，还是用树+dfs的思路来做比较好，

//第二题，对于每一个连通集，求“树的直径”，任选一个节点 u，做一次 BFS，找到最远的节点 v。
// 以 v 为起点，再做一次 BFS，找到离 v 最远的节点 w，v到w的距离即为所求。

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;
struct Node{
    char val_;
    int index_;
    vector<Node*> nexts;
    Node(char val, int index):val_(val), index_(index){}
};
struct MergeFind {
    unordered_map<Node*, Node*> parent;
    unordered_map<Node*, int> count;

    Node* find(Node* x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            count[x] = 1;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(Node* x, Node* y) {
        Node* pX = find(x);
        Node* pY = find(y);
        if (pX == pY) {
            return;
        }
        if (count[pX] < count[pY]) {
            parent[pX] = pY;
            count[pY] += count[pX];
        } else {
            parent[pY] = pX;
            count[pX] += count[pY];
        }
    }

    int getMaxComponentSize() {
        int maxSize = 0;
        for (const auto& entry : count) {
            if (entry.second > maxSize) {
                maxSize = entry.second;
            }
        }
        return maxSize;
    }
};



int solution(string &S, vector<int> &A) {
    MergeFind mergeFind;
    int size = A.size();
    vector<Node*> vecAll(size, nullptr);
    for(int i = 0; i<size; ++i) {
        Node *node = new Node(S[i], i);
        vecAll[i] = node;

    }
    for(int i = 0; i<size; ++i) {
        int index = A[i];
        Node *cur = vecAll[i];
        if(index != -1) {
            vecAll[index]->nexts.emplace_back(cur);
            cur->nexts.emplace_back(vecAll[index]);
        }
    }

    for(Node *node: vecAll) {
        for(Node *next: node->nexts) {
            if(next->val_ == node->val_) continue;
            if(mergeFind.find(node) == mergeFind.find(next)) continue;
            mergeFind.merge(node, next);
        }
    }

    for (int i = 0; i < size; ++i) {
        delete vecAll[i];
    }

    return mergeFind.getMaxComponentSize();



}





