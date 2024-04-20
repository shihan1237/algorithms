#include "string"
#include "deque"
#include "memory.h"
using namespace std;


// 力扣第156题


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Codec {
public:

    deque<string> vals;

    void dfs(TreeNode* node, string &input){
        if(node == NULL) {
            input += "N";
            input += ",";
            return;
        }
        input += to_string(node->val);
        input += ",";

        dfs(node->left, input);
        dfs(node->right, input);


    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string input;
        dfs(root, input);
        return input.substr(0, input.length()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        char tmp[11] = {0};
        int j = 0;

        for(size_t i = 0; i<data.length(); i++){
            if(data[i] == ',') {
                vals.emplace_back(tmp);
                j = 0;
                memset(tmp, 0, 11);
                continue;
            }
            tmp[j++] += data[i];
        }

        return dfs2();


    }

    TreeNode* dfs2(){

        if(vals.empty()) {
            return NULL;
        }

        string val = vals.front();
        vals.pop_front();

        if(val == "N") {
            return NULL;
        }

        TreeNode *tmp =  (TreeNode *)calloc(1, sizeof(TreeNode));
        tmp->val = stoi(val);
        tmp->left = dfs2();
        tmp->right = dfs2();

        return tmp;


    }
};