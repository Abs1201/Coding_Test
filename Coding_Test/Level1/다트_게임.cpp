#include <iostream>

using namespace std;

class String {
private:
	const char* string;

public:
	String() : string(allocateString("")) {}
	String(const char* string) : string(allocateString(string)) {}
	String(char* string) : string(allocateString(string)) {}
	String(const String& copy) : string(allocateString(copy.string)) {}

	const char* getString() {
		return string;
	}
	String setString(char* newString) {
		int newLen = getStringLen(newString);
		char* re = new char[newLen];
		for (int i = 0; i < newLen; i++) {
			*(re + i) = *(newString + i);
		}
		String tmp = re;
		delete[]re;
		return tmp;
	}

	int getStringLen() const {
		int len = 0;
		for (int i = 0; *(string + i) != '\0'; i++) {
			len++;
		}
		return len;
	}
	int getStringLen(char* arr) const {
		int len = 0;
		for (int i = 0; *(arr + i) != '\0'; i++) {
			len++;
		}
		return len;
	}
	int getStringLen(const char* arr) const {
		int len = 0;
		for (int i = 0; *(arr + i) != '\0'; i++) {
			len++;
		}
		return len;
	}
	int getStringLen(String& s) const {
		return s.getStringLen();
	}

	void copyString(char* newString, char* oldString) {
		int len = this->getStringLen(oldString);
		for (int i = 0; i <= len; i++) {
			*(newString + i) = *(oldString + i);
		}
	}
	void copyString(char* newString, const char* oldString) {
		int len = this->getStringLen(oldString);
		for (int i = 0; i <= len; i++) {
			*(newString + i) = *(oldString + i);
		}
	}
	void copyString(char* newString, const char* oldString, int stringLen) {
		for (int i = 0; i < stringLen; i++) {
			*(newString + i) = *(oldString + i);
		}
	}

	char* allocateString(char* oldString) {
		char* tmp = new char[this->getStringLen(oldString) + 1];
		copyString(tmp, oldString);
		*(tmp + this->getStringLen(oldString)) = '\0';
		return tmp;
	}
	char* allocateString(const char* oldString) {
		char* tmp = new char[this->getStringLen(oldString) + 1];
		copyString(tmp, oldString);
		*(tmp + this->getStringLen(oldString)) = '\0';
		return tmp;
	}

	int IndexOf(char c) {
		for (int i = 0; i < this->getStringLen(); i++) {
			if (*(string + i) == c){
				return i;
			}
		}
		
		return -1;
	}
	int IndexOf(char c, int index) { //(index)번째 c 확인
		int count = 0;
		for (int i = 0; i < this->getStringLen(); i++) {
			if (*(string + i) == c) {
				count++;
				if (count == index) return i;
			}
		}
		return -1;
	}

	int IndexOf(String& finder) {
		int stringLen = this->getStringLen();
		int finderLen = finder.getStringLen();

		if (stringLen < finderLen) {
			return -1;
		}
		else {
			bool* tf = new bool[finderLen];
			bool check;
			for (int i = 0; i < stringLen - finderLen + 1; i++) {
				check = 1;
				for (int j = 0; j < finderLen; j++) {

					if (*(finder.string + j) == *(this->string + j + i)) tf[j] = 1;
					else { tf[j] = 0; }
					check = check && tf[j];
				}
				cout << endl;
				if (check == 1) return i;
			}
		}
		return -1;
	}
	int IndexOf(const char* finder) {
		int stringLen = this->getStringLen();
		int finderLen = getStringLen(finder);

		if (stringLen < finderLen) {
			return -1;
		}
		else {
			bool* tf = new bool[finderLen];
			bool check;
			for (int i = 0; i < stringLen - finderLen + 1; i++) {
				check = 1;
				for (int j = 0; j < finderLen; j++) {

					if (*(finder + j) == *(this->string + j + i)) tf[j] = 1;
					else { tf[j] = 0; }
					check = check && tf[j];
				}
				cout << endl;
				if (check == 1) return i;
			}
		}
		return -1;
	}
	
	
	int IndexOf(String& finder, int index) { //(index)번째 finder 확인
		int count = 1;

		int stringLen = this->getStringLen();
		int finderLen = finder.getStringLen();
		if (stringLen < finderLen) {
			return -1;
		}
		else {
			bool* tf = new bool[finderLen];
			bool check = 1;
			for (int i = 0; i < stringLen - finderLen + 1; i++) {
				for (int j = 0; j < finderLen; j++) {
					if (*((finder.getString()) + j) == *((this->getString()) + j + i)) tf[j] = 1;
					else { tf[j] = 0; }
					check = 1;
					check = check && tf[j];
				}
				if (check == 1) {
					if (count == index) return i;
					count++;
				}
			}
		}
	}

	int LastIndexOf(char c) {
		int stringLen = this->getStringLen();
		for (int i = stringLen - 1; stringLen >= 0; i--) {
			if (*(string + i) == c) return i;
		}
		return -1;
	}
	int LastIndexOf(String& finder) { //re.
		int stringLen = this->getStringLen();
		int finderLen = finder.getStringLen();
		if (stringLen < finderLen) {
			return -1;
		}
		else {
			bool* tf = new bool[finderLen];
			bool check = 1;
			for (int i = stringLen - finderLen; i >= 0; i--) {
				for (int j = 0; j < finderLen; j++) {
					if (*((finder.getString()) + j) == *((this->getString()) + j + i)) tf[j] = 1;
					else { tf[j] = 0; }

					check = check && tf[j];
				}
				if (check == 1) return i;
			}
		}
	}

	bool StartWith(char c) {
		int index = this->IndexOf(c);
		if (index == 0) return 1;
		return 0;
	}
	bool StartWith(String& s) {
		int index = this->IndexOf(s);
		if (index == 0) return 1;
		return 0;
	}

	bool EndsWith(char c) {
		int index = this->LastIndexOf(c);
		int stringLen = this->getStringLen();
		if (index == stringLen - 1) return 1;
		return 0;
	}
	bool EndsWith(String& finder) {
		int index = this->LastIndexOf(finder);
		int finderLen = finder.getStringLen();
		int stringLen = this->getStringLen();

		if (index == stringLen - finderLen) return 1;
		return 0;
	}


	bool Contains(char c) {
		for (int i = 0; i < this->getStringLen(); i++) {
			if (*((this->getString()) + i) == c) return 1;
		}
		return 0;
	}
	bool Contains(String& finder) {
		int stringLen = this->getStringLen();
		int finderLen = finder.getStringLen();
		if (stringLen < finderLen) {
			return 0;
		}
		else {
			bool* tf = new bool[finderLen];
			bool check = 1;
			for (int i = 0; i < stringLen - finderLen + 1; i++) {
				check = 1;
				for (int j = 0; j < finderLen; j++) {
					if (*(finder.string + j) == *(this->string + j + i)) {
						tf[j] = 1;
					}
					else { tf[j] = 0; }
					check = check && tf[j];
				}
				if (check == 1) {
					delete[]tf;
					return 1;
				}
				cout << endl;
			}
		}
		return 0;
	}
	bool Contains(const char* finder) {
		int stringLen = this->getStringLen();
		int finderLen = getStringLen(finder);
		if (stringLen < finderLen) {
			return 0;
		}
		else {
			bool* tf = new bool[finderLen];
			bool check = 1;
			for (int i = 0; i < stringLen - finderLen + 1; i++) {
				check = 1;
				for (int j = 0; j < finderLen; j++) {
					if (*(finder + j) == *(this->string + j + i)) {
						tf[j] = 1;
					}
					else { tf[j] = 0; }
					check = check && tf[j];
				}
				if (check == 1) {
					delete[]tf;
					return 1;
				}
				cout << endl;
			}
		}
		return 0;
	}
	String ToLower() {
		int stringLen = this->getStringLen();
		char* newString = new char[stringLen + 1];
		copyString(newString, string, stringLen + 1);

		for (int i = 0; i < stringLen + 1; i++) {
			if (*(newString + i) >= 65 && *(newString + i) <= 90) {
				*(newString + i) += 32;
			}
		}
		*(newString + stringLen) = '\0';
		String tmpString = newString;

		return tmpString;
	}
	String ToUpper() {
		int stringLen = this->getStringLen();
		char* newString = new char[stringLen + 1];
		copyString(newString, string, stringLen + 1);

		for (int i = 0; i < stringLen + 1; i++) {
			if (*(newString + i) >= 97 && *(newString + i) <= 122) {
				*(newString + i) -= 32;
			}
		}
		String tmpString = newString;

		return tmpString;
	}

	String Insert(String adder, int index) {
		int stringLen = this->getStringLen();//5
		int adderLen = adder.getStringLen();
		
		if(index > stringLen){
			return *this;
		}
		else{
			char* tmp = new char[stringLen - index-1];
			
			for ( int i = 0; i < stringLen - index; i++){
				*(tmp + i) = *(string + index + i);
			}
			
			char* newString = new char[stringLen + adderLen + 1];
			copyString(newString, string, index);
			for (int i = index; i < index + adderLen; i++) {
				*(newString + i) = (*(adder.string + i - index));
			}
			for (int i = index + adderLen; i < stringLen + adderLen; i++) {
				*(newString + i) = *(tmp + i - index - adderLen);
			}
			*(newString + stringLen + adderLen + 1) = '\0';
			String tmpString = newString;
			return tmpString;
		}
	}
	
	String Insert(char c, int index) {
		int stringLen = this->getStringLen();
		
		char* newString = new char[stringLen + 2]; // c랑 '\0'
		copyString(newString, string, index);
		*(newString + index) = c;
		for(int i = index + 1; i < stringLen + 2; i++){
			*(newString + i) = *(string + i - 1);
		}
		*(newString + stringLen + 1) = '\0';
		return newString;
	}

	String Remove(int index, int count) {
		int stringLen = this->getStringLen();
		char* newString = new char[stringLen - count + 1];
		copyString(newString, string, index);
		for (int i = index; i < stringLen - count; i++) {
			*(newString + i) = *(string + i + count);
		}
		*(newString + stringLen - count) = '\0';
		String tmpString = newString;
		return tmpString;
	}


	String TrimAll() {
		int count = 0;
		int stringLen = this->getStringLen();
		for (int i = 0; i < stringLen; i++) {
			if (*(string + i) == ' ') count++;
		}
		char* newString = new char[stringLen - count + 1];

		for (int i = 0, j = 0; i < stringLen - count; i++, j++) {
			if (*(string + i) == ' ') {
				j--;
			}
			else {
				*(newString + j) = *(string + i);
			}
		}
		*(newString + stringLen + count) = '\0';
		String tmpString = newString;
		return tmpString;
	}

	String TrimStart(char c = ' ') {
		int stringLen = this->getStringLen();
		int frontCount = 0;
		for (int i = 0; *(string + i) == c; i++) {
			frontCount++;
		}
		char* newString = new char[stringLen - frontCount + 1];
		for (int i = 0; i < stringLen - frontCount; i++) {
			*(newString + i) = *(string + i + frontCount);
		}
		*(newString + stringLen - frontCount) = '\0';

		String tmpString = newString;
		return tmpString;
	}

	String TrimEnd(char c = ' ') {
		int stringLen = this->getStringLen();
		int tailCount = 0;
		for (int i = stringLen - 1; *(string + i) == c; i--) {
			tailCount++;
		}
		char* newString = new char[stringLen - tailCount + 1];
		copyString(newString, string, stringLen - tailCount);
		*(newString + stringLen - tailCount) = '\0';
		String tmpString = newString;
		return tmpString;
	}

	String Trim(char c = ' ') {
		String tmpString = this->TrimStart(c).TrimEnd(c);
		return tmpString;
	}

	// String SubString(int index) {
	// 	int stringLen = this->getStringLen();
	// 	char* newString = new char[stringLen - index];
	// 	for (int i = index; i < stringLen; i++) {
	// 		*(newString + i - index) = *(string + i);
	// 	}
	// 	String tmpString = newString;
	// 	return tmpString;
	// }
	String SubString(int index, bool isTail = 1) {  //앞문자열반환이면 0, 뒤문자열이면 1
		int stringLen = this->getStringLen();
		if(isTail == 1){
			char* newString = new char[stringLen - index+1];
			for (int i = index; i < stringLen; i++) {
				*(newString + i - index) = *(string + i);
			}
			*(newString + stringLen - index) = '\0';
			String tmpString = newString;
			return tmpString;
		}
		else{
			char* newString = new char[index+2];
			for(int i = 0; i < index+1; i++){
				*(newString + i) = *(string + i);
			}
			*(newString + index+1) = '\0';
			String tmpString = newString;
			return tmpString;
		}
		
	}

	String print() const {
		int stringLen = this->getStringLen();
		//cout << "@print: " << stringLen << endl;
		for (int i = 0; i < stringLen; i++) {
			cout << *(string + i);
		}
		cout << ";" << endl;
		return *this;
	}

	String Replace(String& change, String& changer) {
		int stringLen = this->getStringLen();
		int changeLen = change.getStringLen();
		int changerLen = changer.getStringLen();

		bool tf = this->Contains(change);
		if (tf == 0) {
			return *this;
		}
		else {
			int changeIndex = this->IndexOf(change);
			int gap = changerLen - changeLen;
			char* newString = new char[stringLen + gap];

			// for(int i = 0; i < changeIndex; i++){
			// 	*(newString+i) = *(string + i);
			// }
			copyString(newString, string, changeIndex);

			for (int i = changeIndex; i < changeIndex + changerLen; i++) {
				*(newString + i) = *(changer.string + i - changeIndex);
			}

			for (int i = changeIndex + changerLen; i < stringLen + gap; i++) {
				*(newString + i) = *(string + i - gap);
			}
			*(newString + stringLen + gap) = '\0';

			String tmpString = newString;
			return tmpString;
		}
	}
	String Replace(const char* change, const char* changer) {				//overloaded
		int stringLen = this->getStringLen();
		int changeLen = getStringLen(change);
		int changerLen = getStringLen(changer);

		bool tf = this->Contains(change);
		if (tf == 0) {
			return *this;
		}
		else {
			int changeIndex = this->IndexOf(change);
			int gap = changerLen - changeLen;
			char* newString = new char[stringLen + gap];

			// for(int i = 0; i < changeIndex; i++){
			// 	*(newString+i) = *(string + i);
			// }
			copyString(newString, string, changeIndex);

			for (int i = changeIndex; i < changeIndex + changerLen; i++) {
				*(newString + i) = *(changer + i - changeIndex);
			}

			for (int i = changeIndex + changerLen; i < stringLen + gap; i++) {
				*(newString + i) = *(string + i - gap);
			}

			*(newString + stringLen + gap) = '\0';
			
			String tmpString = newString;
			return tmpString;
		}
	}
	String Replace(const char* change, String& changer) {				//overloaded
		int stringLen = this->getStringLen();
		int changeLen = getStringLen(change);
		int changerLen = getStringLen(changer);

		bool tf = this->Contains(change);
		if (tf == 0) {
			return *this;
		}
		else {
			int changeIndex = this->IndexOf(change);
			int gap = changerLen - changeLen;
			char* newString = new char[stringLen + gap];

			// for(int i = 0; i < changeIndex; i++){
			// 	*(newString+i) = *(string + i);
			// }
			copyString(newString, string, changeIndex);

			for (int i = changeIndex; i < changeIndex + changerLen; i++) {
				*(newString + i) = *(changer.string + i - changeIndex);
			}

			for (int i = changeIndex + changerLen; i < stringLen + gap; i++) {
				*(newString + i) = *(string + i - gap);
			}
			
			*(newString + stringLen + gap) = '\0';
			
			String tmpString = newString;
			return tmpString;
		}
	}
	String Replace(String& change, const char* changer) {				//overloaded
		int stringLen = this->getStringLen();
		int changeLen = getStringLen(change);
		int changerLen = getStringLen(changer);

		bool tf = this->Contains(change);
		if (tf == 0) {
			return *this;
		}
		else {
			int changeIndex = this->IndexOf(change);
			int gap = changerLen - changeLen;
			char* newString = new char[stringLen + gap+1];

			// for(int i = 0; i < changeIndex; i++){
			// 	*(newString+i) = *(string + i);
			// }
			copyString(newString, string, changeIndex);

			for (int i = changeIndex; i < changeIndex + changerLen; i++) {
				*(newString + i) = *(changer + i - changeIndex);
			}

			for (int i = changeIndex + changerLen; i < stringLen + gap; i++) {
				*(newString + i) = *(string + i - gap);
			}
			
			*(newString + stringLen + gap) = '\0';

			String tmpString = newString;
			return tmpString;
		}
	}
	String operator+(const String& ref) {
		int stringLen = this->getStringLen() + ref.getStringLen();
		char* tmp = new char[stringLen];
		int i = 0;
		for (; i < this->getStringLen(); i++) {
			*(tmp + i) = *((this->string) + i);
		}
		for (; i < stringLen; i++) {
			*(tmp + i) = *(ref.string + i - this->getStringLen());
		}
		String tmp2 = tmp;
		return tmp2;
	}
	//String.operator+(s)   --->   String+s
	
	String operator=(const String& ref){
		//cout << "wow" << endl;
		int stringLen = this -> getStringLen();
		int refLen = ref.getStringLen();
		
		delete[]this->string;												//question
		this->string = allocateString(ref.string);
		
		return *this;
	}

	~String() {
		delete[](string);
	}
};

int solution(String s);
int getScore(String s);

int main(void){
	//1D2S0T
	char dart[15] = "1D2S0T"; 
	
	String dartScore = dart;
	cout << solution(dart);
	
	
	return 0;
}


int solution(String s){ // 3개의 문자열로 나눠서 각각 점수 구하고 그담에 [옵션]까지 해서 마지막 합산 
	String dart[3];
	int index;
	int stringLen = s.getStringLen();
	int tmp;
	
	for(int k = 0; k < 2; k++){
		for(int i = 2; i < stringLen; i++){
			for(int j = 0; j < 10; j++){
				if(*(s.getString() + i) == (char)(48+j)){
					index = i;
					tmp = j;
					index -= 1;
					break;
				}
			}
			if(*(s.getString() + i) == (char)(48+tmp)){
				dart[k] = s.SubString(index, 0);
				s = s.Remove(0, index+1);
				break;
			}
		}
	}
// 	for(int j = 0 ; j < 2; j++){
// 		for(int i = 0; i < 10; i++){
// 			index = 0;
// 			index = s.IndexOf((char)(48+i)); // 18
// 			if(*(s.getString() + index) == '0'){
// 				if(*(s.getString() + index-1) == '1'){
// 					index -= 1;
// 				}
// 				else if()
					
// 				}
// 			}
// 			//cout << "@" << index << endl;
// 			if(index > 1) break;
// 		}
// 		index -= 1;
// 		dart[j] = s.SubString(index, 0);
// 		cout << "FF ";
// 		s.print();
// 		s = s.Remove(0, index+1);
// 		cout << "SS ";
// 		s.print();
// 	}
	dart[2] = s;
	
	int s1 = getScore(dart[0]);
	int s2 = getScore(dart[1]);
	int s3 = getScore(dart[2]);
	
	if(dart[1].Contains((char)42) ){
		s1 *= 2;
	}
	if(dart[2].Contains((char)42) ){
		s2 *= 2;
	}
	dart[0].print();
	dart[1].print();
	dart[2].print();
	cout << s1 << " " << s2 << " " << s3 << endl;
	
	return s1+s2+s3;
}

int getScore(String s){
	int sum;
	int remover;
	for(int i = 0; i < 10; i++){
		if(*(s.getString() + 0) == (char)(48+i)){
			if(*(s.getString() + 0) == (char)49){
				if(*(s.getString() + 1) == (char)48){
					sum = 10;
					remover = 2;
				}
				else{
					sum = 1;
					remover = 1;
				}
			}
			else{
				sum = i;
				remover = 1;
			}
		}
	}
	s = s.Remove(0, remover);

	if(*(s.getString()+0) == (char)68){				//S
		sum *= sum;
	}
	if(*(s.getString()+0) == (char)84){ 			//D
		int tmp = sum;
		sum *= tmp;
		sum *= tmp;
	}
	s = s.Remove(0, 1);

	if(*(s.getString() + 0) == (char)42){			//*

		// if(seq > 0){
		// 	sum[seq-1] *= 2;
		// }

		sum *= 2;
		s = s.Remove(0,1);
	}
	if(*(s.getString() + 0) == (char)35){			//#
		sum *= -1;
		s = s.Remove(0,1);
	}
	return sum;
}














// int solution(String s){
// 	int sum[3];
// 	int remover;
	
// 	for(int seq = 0; seq < 3; seq++){
		
// 		for(int i = 0; i < 10; i++){
// 			if(*(s.getString() + 0) == (char)(48+i)){
// 				if(*(s.getString() + 0) == (char)49){
// 					if(*(s.getString() + 1) == (char)48){
// 						sum[seq] = 10;
// 						remover = 2;
// 					}
// 					else{
// 						sum[seq] = 1;
// 						remover = 1;
// 					}
// 				}
// 				else{
// 					sum[seq] = i;
// 					remover = 1;
// 				}
// 			}
// 		}
// 		s = s.Remove(0, remover);

// 		if(*(s.getString()+0) == (char)68){				//S
// 			sum[seq] *= sum[seq];
// 		}
// 		if(*(s.getString()+0) == (char)84){ 			//D
// 			int tmp = sum[seq];
// 			sum[seq] *= tmp;
// 			sum[seq] *= tmp;
// 		}
// 		s = s.Remove(0, 1);

// 		if(*(s.getString() + 0) == (char)42){			//*
			
// 			if(seq > 0){
// 				sum[seq-1] *= 2;
// 			}
			
// 			sum[seq] *= 2;
// 			s = s.Remove(0,1);
// 		}
// 		if(*(s.getString() + 0) == (char)35){			//#
// 			sum[seq] *= -1;
// 			s = s.Remove(0,1);
// 		}
		
		
		
// 	}
	
// 	int answer = 0;
// 	for(int i = 0; i < 3; i++){
// 		answer += sum[i];
// 	}
	
// 	return answer;
// }












