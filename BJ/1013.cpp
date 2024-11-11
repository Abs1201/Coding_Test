#include <iostream>

using namespace std;
#define ll long long

// 1
// 1001100011100111000001

// 1001 100011

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        cin >> s;
        bool b=1;
        bool check=0;
        for(int i=0; i<s.size();){
            if(s[i]=='1'){
                i++;
                if(i+1>=s.size() || s[i]!='0' || s[i+1]!='0'){
                    b=0;
                    break;
                }
                else i+=2;
                while(i<s.size() && s[i]=='0') i++;
                if(i<s.size() && s[i]=='1'){
                    i++;
                    check=0;
                    while(i<s.size() && s[i]=='1'){
                        check=1;
                        i++;
                    }
                }
                else{
                    b=0;
                    break;
                }
            }
            else{   
                i++;
                if(i<s.size() && s[i]=='1'){
                    i++;
                    check=0;
                }
                else{
                    if(i<s.size() && s[i]=='0' && check){
                        i++;
                        while(i<s.size() && s[i]=='0') i++;
                        if(i<s.size() && s[i]=='1'){
                            i++;
                            check=0;
                            while(i<s.size() && s[i]=='1'){
                                check=1;
                                i++;
                            }
                        }
                        else{
                            b=0;
                            break;
                        }
                    }
                    else{
                        b=0;
                        break;
                    }
                }
            }
        }
        if(b){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }


    
    return 0;
}

