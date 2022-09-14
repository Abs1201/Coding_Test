#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long isBigger(const long long& a, const long long& b){ return a > b ? a : b; }

int power(int a, int expo){
	int result = 1;
	for(int i = 0; i < expo; i++){
		result *= a;
	}
	return result;
}

int stringToInt(string s){
	int result = 0;
	for(int i = 0; i < s.size(); i++){
		result += (s[i]-'0')*power(10, s.size()-i-1);
	}
	return result;
}

int solution(string expression) {
    int answer = 0;
	
	vector<string> values_s;
	vector<int> values;
	vector<char> op;
	
	string tmp = "";
	for(int i = 0; i < expression.size(); i++){
		
		if(expression[i] == '*' || expression[i] == '+'|| expression[i] == '-'){
			op.push_back(expression[i]);
			values_s.push_back(tmp);
			tmp = "";
		}
		else{
			tmp += expression[i];
			if(i == expression.size()-1){
				values_s.push_back(tmp);
			}
		}
	}
	//check
	// for(int i = 0; i <values_s.size(); i++){
	// 	cout << "values_s: " << values_s[i] << endl;
	// }
	// for(int i = 0; i < op.size(); i++){
	// 	cout << "op: " << op[i] << endl;
	// }
	int stringToInt_value;
	for(int i = 0; i < values_s.size(); i++){
		stringToInt_value = stringToInt(values_s[i]);
		values.push_back(stringToInt_value);
	}
	
	//check values
	// for(int i = 0; i <values.size(); i++){
	// 	cout << "values: " << values[i] << endl;
	// }
	
	string prior[6] = {
        "*+-", "*-+",
        "+*-", "+-*", 
        "-*+", "-+*",
    };

    for(int i=0;i<6;i++){
        vector<int> values_copy = values;
        vector<char> op_copy = op;
        string pr = prior[i];
        for(int j=0;j<3;j++){
            for(int k=0;k<op_copy.size();k++){
                if(pr[j] == op_copy[k]){
                    if(pr[j] == '*'){
                        values_copy[k] = values_copy[k]*values_copy[k+1];
                        values_copy.erase(values_copy.begin()+k+1);
                    }else if(pr[j] == '+'){
                        values_copy[k] = values_copy[k]+values_copy[k+1];
                        values_copy.erase(values_copy.begin()+k+1);
                    }else if(pr[j] == '-'){
                        values_copy[k] = values_copy[k]-values_copy[k+1];
                        values_copy.erase(values_copy.begin()+k+1);
                    }
                    op_copy.erase(op_copy.begin()+k--);
                }
            }
        }
        answer = max(answer, abs(values_copy[0]));
    }
	
	
    return answer;
}
