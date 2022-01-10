// Burning Tree 
// Hard Accuracy: 43.4% Submissions: 7757 Points: 8
// Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree 
// if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. 
// That is its left child, right child, and parent.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
int minTime(Node* root, int target) 
{
    map<Node*, Node*> m;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *curr = q.front();
        q.pop();
        if(curr->left) {
            m[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right) {
            m[curr->right] = curr;
            q.push(curr->right);
        }
    }
    Node *tar = NULL;
    q.push(root);
    while(!q.empty()) {
        tar = q.front();
        q.pop();
        if(tar->data == target) {
            break;
        }
        if(tar->left) q.push(tar->left);
        if(tar->right) q.push(tar->right);
    }
        
    queue<pair<Node*, int>> time;
    int ans = 0;
    map<Node*, int> vis;
    time.push({tar, 0});
    vis[tar] = 1;
        
    while(!time.empty()) {
        ans = time.front().second;
        Node *curr = time.front().first;
        time.pop();
        if(m.find(curr)!=m.end() && vis.find(m[curr])==vis.end()) {
            time.push({m[curr], ans+1});
            vis[m[curr]] = 1;
        }
        if(curr->left && vis.find(curr->left)==vis.end()) {
            time.push({curr->left, ans+1});
            vis[curr->left] = 1;
        }
        if(curr->right && vis.find(curr->right)==vis.end()) {
            time.push({curr->right, ans+1});
            vis[curr->right] = 1;
        }
    }
    return ans;
}
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends