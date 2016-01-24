/*
LeetCode 150 - Evaluate Reverse Polish Notation
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int x;
        stack<int> S;
        string operators[4] = {"+","-","*","/"};
         
        for (string t: tokens){
            if (check_operator(t))
                do_operation(S,t);
            else
                S.push(stoi(t));
        }
        
        if (!S.size() == 1){ cout << "ERROR" << endl; return 0;}
        return S.top();
    }
    
    bool check_operator(string t){
        string operators[4] = {"+","-","*","/"};
        for (string o: operators){if (t.compare(o) == 0){return true;}}
        return false;
    }
    
    
    void do_operation(stack<int>& S, string operation){
        if (S.size() < 2){
            cout << "ERROR" << endl;
            return;
        }
        
        int n1 = S.top(); S.pop();
        int n2 = S.top(); S.pop();
        if (operation.compare("+") == 0){S.push(n2+n1);}
        if (operation.compare("-") == 0){S.push(n2-n1);}
        if (operation.compare("*") == 0){S.push(n2*n1);}
        if (operation.compare("/") == 0){S.push(n2/n1);}
    }
    
};
