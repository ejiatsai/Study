#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode*> children;
    TreeNode(T val) : data(val) {}
    virtual ~TreeNode() {
        for (auto child : children) delete child;
    }
    TreeNode* addChild(T childVal) {
        TreeNode* child = new TreeNode(childVal);
        children.push_back(child);
        return child;
    }

    class iterator {
        vector<TreeNode*> nodes;
    public:
        iterator() {}
        iterator(TreeNode* root) {
            if (root) nodes.push_back(root);
        }
        T& operator*() { return nodes.back()->data; }
        iterator& operator++() {
            TreeNode* current = nodes.back();
            nodes.pop_back();
            for (auto it = current->children.rbegin();
                 it != current->children.rend(); ++it)
                nodes.push_back(*it);
            return *this;
        }
        bool operator!=(const iterator& other) const {
            bool e1 = nodes.empty(), e2 = other.nodes.empty();
            if (e1 && e2) return false;
            if (e1 != e2) return true;
            return nodes.back() != other.nodes.back();
        }
    };
    iterator begin() { return iterator(this); }
    iterator end()   { return iterator(); }
};

// Help function to check function format
bool isFunctionFormat(const string& s) {
    int lp = s.find('(');
    int rp = s.rfind(')');
    if (lp == string::npos || rp == string::npos || rp <= lp) return false;
    if (lp == 0) return false;
    for (int i = 0; i < lp; ++i) {
        char c = s[i];
        if (i == 0 && !isalpha(c) && c != '_') return false;
        if (i > 0 && !isalnum(c) && c != '_') return false;
    }
    return true;
}

// Help function to match brackets
int findMatchingParen(const string& s, int start) {
    if (s[start] != '(') static_cast<int>(string::npos);
    int depth = 1;
    for (int i = start + 1; i < s.size(); ++i) {
        if (s[i] == '(') depth++;
        else if (s[i] == ')') {
            depth--;
            if (depth == 0) return i;
        }
    }
    return static_cast<int>(string::npos);
}

// Sample parser to implement: "FuncName(Gunc(a,b),c)" -> ["FuncName", "Gunc(a,b)", "c"]
vector<string> parse_func(const string& str) {
    if (!isFunctionFormat(str))
        throw runtime_error("Illegal format");

    // Determine range of parameters list
    int lp = str.find('(');
    int rp = str.rfind(')');
    string name = str.substr(0, lp);
    string params = str.substr(lp + 1, rp - lp - 1);
    vector<string> tokens;
    tokens.push_back(name);

    int i = 0, start = 0;
    while (i < params.size()) {
        // process brackets in function-like element, i.e., "Function_name(para1,..)"
        if (params[i] == '(') {
            int match = findMatchingParen(params, i);
            if (match == string::npos)
                throw runtime_error("Asymmetrical brackets");
            i = match + 1;
        // process for comma-separated element 
        } else if (params[i] == ',' && i >= start) {
            tokens.push_back(params.substr(start, i - start));
            start = i + 1;
            ++i;
        } else {
            ++i;
        }
    }
    if (start < params.size())
        tokens.push_back(params.substr(start));

    for (auto& t : tokens) {
        int first = t.find_first_not_of(" \t");
        int last  = t.find_last_not_of(" \t");
        t = (first == string::npos) ? "" : t.substr(first, last - first + 1);
    }
    return tokens;
}

// HW: Complete this class to implement the AST building
class ParseTree : public TreeNode<string>{
public:
    ParseTree(const string& expr) : TreeNode<string>("") /* Note: call parent's Constructor */ {
        if (!isFunctionFormat(expr)) {
            // HW: Process for non-functional style elements (expr) 
            this->data = expr;
        } else {
            vector<string> token = parse_func(expr);
            this->data = token[0];
            for(int i = 1;i < token.size();++i){
                this->children.push_back(new ParseTree(token[i]));
            }
            // HW: Process for functional style elements (expr)
            // Hint: parse the expr
            // Hint: get function name
            // Hint: use for-loop to construct the other element in array to tree node
            //       and push they to children array
        }
    }
};

int main() {
    string input = "F(G(a, f(b, c)), c)";
    ParseTree tree(input);

    // Travel the tree
    cout << "Traveling:" << endl;
    for (auto& val : tree) {
        cout << val << " ";
    }
    cout << endl;
    // Output：F G a f b c c
    return 0;
}