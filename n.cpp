#include<bits/stdc++.h>
using namespace std;
#define ll long long
int braces(string a) {
    int n = a.length();
    stack<string> s;
    for(int i=0; i<n; ++i){
        if(a[i] == '('){
            s.push("(");
        }
        else if(a[i] == ')'){
            string exp = s.top();
            if(exp=="("){
                return 1;
            }
            int t = exp.length();
            if(exp[t-2] == '(' && exp[t-1]!='#'){
            	return 1;
            }

            s.pop();
            s.push("(#");
            exp = s.top();

            cout<<exp<<endl;

            if(exp!="(#"){
            	return 1;
            }
            s.pop();
            
        }
        else{
        	if(!s.empty()){
            string exp = s.top();
            exp += a[i];

            s.pop();
            s.push(exp);
        }
        else{
        	string t="";
        	t+=a[i];
        	s.push(t);
        }

        }
    }
    return 0;
}

int main(){
	string s;
	cin>>s;
	cout<<braces(s);

}
