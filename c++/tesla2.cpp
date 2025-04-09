// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>


// N个结点，vector<int> &A给出了父亲依赖关系，string &S给出了每个结点的字符
// 把相邻的，字符不同的结点串起来，找到最大的串，返回其长度


// 正确性通过率15%，性能通过率20%
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





