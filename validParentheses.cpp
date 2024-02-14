#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s);

int main(){
    string input;
    cin >>input;
    cout << isValid(input);
}

bool isValid(string s) {
    stack<char> stk;
    string input = s;
    for(int i=0; i<input.length(); i++){
        if(input[i]==']'||input[i]=='}'||input[i]==')'){
            if(stk.empty())
                return false;
        }
        if(input[i]== '('){
            stk.push('(');
        }else if(input[i]==')'){
            if(stk.top()!='(')
                return false;
            else if(stk.top() == '(')
                stk.pop();
        }else if(input[i]=='['){
            stk.push('[');
        }else if(input[i]==']'){
            if(stk.top()!='[' )
                return false;
            else if(stk.top() == '[')
                stk.pop();
        }else if(input[i]=='{'){
            stk.push('{');
        }else if(input[i]=='}'){
            if(stk.top()!='{')
                return false;
            else if(stk.top() == '{')
                stk.pop();
        }
    }
    if(stk.empty())
        return true;
    return false;
}