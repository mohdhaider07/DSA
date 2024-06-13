 #include<bits/stdc++.h>

using namespace std;
 
 int evalRPN(vector<string>& tokens) {
        stack<int>stk;
        for(auto s:tokens){
            int empty=stk.empty();
            
            if(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'){
                int n1=0,n2=0;
                if(s[0]=='+'&&!empty){
                    n1=stk.top();
                    stk.pop();
                    n2=stk.top();
                    stk.pop();

                    stk.push(n1+n2);

                }else if(s[0]=='-'&&!empty){
                    n1=stk.top();
                    stk.pop();
                    n2=stk.top();
                    stk.pop();

                    stk.push(n1-n2);

                }else if(s[0]=='*'&&!empty){
                    n1=stk.top();
                    stk.pop();
                    n2=stk.top();
                    stk.pop();

                    stk.push(n1*n2);

                } else if (s[0]=='/'&&!empty){
                    n1=stk.top();
                    stk.pop();
                    n2=stk.top();
                    stk.pop();

                    stk.push(n1/n2);

                }
            }else{
                stk.push(stoi(s));
            }
        }

        return stk.top();

    }

    int main(){

    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

            cout<<"after evaluation : "<<evalRPN(tokens);
        cout<<"\nCode running fine : ";
        return 0;
    }