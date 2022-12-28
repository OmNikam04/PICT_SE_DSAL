#include<iostream>
#include "Stack.cpp"
#include <algorithm>
#include <math.h>

using namespace std;

class expression{
private: string infix, postFix, prefix;

public:
    string reverse(string s){
        string rev = "";
        for(int i = s.length()-1; i>=0; i--){
            rev += s[i];
        }
        return rev;
    }   
    int precedance(char c){
        if(c == '+' || c == '-')return 1;
        if(c == '*' || c == '/')return 2;
        if(c == '^')return 3;
        return -1;
    }
    string infixToPostfix(Stack<char> st, string str){
        string res = "";
        for(int i =0; i< str.length(); i++){
            if(isalnum(str[i])){
                res += str[i];
            }
            else if(str[i] == '('){
                st.push('(');
            }
            else if(str[i] == ')'){
                while(!st.isEmpty() && (st.getTop()!='(')){
                    res += st.getTop();
                    st.pop();
                }
                st.pop();
            }
            else{
                // str[i] is operator
                while(!st.isEmpty() && precedance(st.getTop()) >= precedance(str[i])){
                    res += st.getTop();
                    st.pop();
                }
                st.push(str[i]);
            }
        }
        while (!st.isEmpty())
        {
            res += st.getTop();
            st.pop();
        }
        
        return res;
    }
    string infixToPrefix(Stack<char> st, string str){
        string ans = reverse(str);
        for(int i = 0; i<ans.length() ; i++){
            if(ans[i] == '('){
                ans[i]=')';
            }
            else if(ans[i]==')'){
                ans[i]='(';
            }
        }
        this->prefix = infixToPostfix(st, ans);
        
        return reverse(this->prefix);
    }

    int postfixEvaluation(Stack<int>st, string str){
        for(int i = 0 ;i <str.length(); i++){
            if(isalnum(str[i])){
                st.push(str[i]-'0');
            }
            else{
                // operator encountered
                int n1 = st.getTop();
                st.pop();
                int n2 = st.getTop();
                st.pop();

                switch(str[i]){
                    case '+':
                        st.push(n2+n1);
                        break;
                    case '-':
                        st.push(n2-n1);
                        break;
                    case '*':
                        st.push(n2*n1);
                        break;
                    case '/':
                        st.push(n2/n1);
                        break;
                    case '^':
                        st.push(pow(n2,n1));
                        break;
                    default:
                        break;
                }
            }
        }
        return st.getTop();
    }

    int prefixEvaluation(Stack<int>st, string str){

        for(int i =str.length()-1; i>=0; i--){
            if(isalnum(str[i])){
                st.push(str[i]-'0');
            }else{
                //operator is encountered
                int n1 = st.getTop();
                st.pop();
                int n2 = st.getTop();
                st.pop();

                switch (str[i])
                {
                case '+':
                    st.push(n2+n1);
                    break;
                case '-':
                    st.push(n2-n1);
                    break;
                case '*':
                    st.push(n2*n1);
                    break;
                case '/':
                    st.push(n2/n1);
                    break;
                case '^':
                    st.push(pow(n2,n1));
                    break;
                default:
                    break;
                }
            }
        }
        return st.getTop();
    }
};

int main()
{
    Stack<int> int_stack;
    Stack<char> char_stack;

    expression exp;
    string infix="a+b/c*(d+e)-f";
    string inf = "(A+B^C)*D+E^5";
    // cout<<"Enter infix expression: ";
    // cin>>infix;
    cout<<"Postfix: " << exp.infixToPostfix(char_stack, infix)<<endl;
    cout<<"Prefix: " << exp.infixToPrefix(char_stack, inf)<<endl;
    
    string eval = "3574-2^*+";
    cout<<"Postfix Evaluation: "<<exp.postfixEvaluation(int_stack, eval)<<endl;

    string preEval = "+9*26";
    cout<<"Prefix Evaluation: "<<exp.prefixEvaluation(int_stack, preEval)<<endl;
    
    return 0;
}