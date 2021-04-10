//Use decimal digits instead of binary to make the code faster. 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    string bigData;
public:
    // Encodes a tree to a single string.
    string codeword(int no)
    {
        string ans="";
        for(int i=0;i<14;i++)
        {
            ans=ans+(char)('0'+(no&1));
            no=no>>1;
        }
        return ans;
    }
    int number(string s,int lb)
    {
        int pow2=1;
        int no=0;
        for(int i=0;i<14;i++)
        {
            no+=pow2*(int)(s[lb+i]-'0');
            pow2*=2;
        }
        return no;
    }    
    void preorder(TreeNode* root)
    {
        //preorder traversal.
        if(root==NULL)return;
        bigData+=codeword(root->val);    
        preorder(root->left);
        preorder(root->right);        
    }
    TreeNode* insert(TreeNode* root,int key)
    {
        if(root==NULL)return new TreeNode(key);
        if(root->val<key)root->right=insert(root->right,key);
        else root->left=insert(root->left,key);
        return root;
    }
    string serialize(TreeNode* root) {
        bigData="";
        preorder(root);
        return bigData;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int no=0;
        TreeNode* root=NULL;
        for(int lb=0;lb<data.length();lb+=14)
        {
            no=number(data,lb);
            root=insert(root,no);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;



/*
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "NULL";
        }
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        
        return to_string(root->val) + " " + left + " " + right;
    }
    
    TreeNode* helper_des(stringstream& ss, string s) {
        ss >> s;
        if(s == "NULL"){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(stoi(s));
        
        root->left = helper_des(ss, s);
        root->right = helper_des(ss, s);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data); // the use of stringstream.
        return helper_des(ss, "");
    }
};
*/