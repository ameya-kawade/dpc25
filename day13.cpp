#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string bruteForceApproach(string s){
	string ans = "";
	int maxLength = 0;

	for(int i = 0; i < s.length(); i++){
		string substring = "";	

		for(int j = i; j < s.length(); j++){

			substring.push_back(s[j]);

			string reversedString = substring;

			reverse(reversedString.begin(), reversedString.end());

			if(substring == reversedString){
				if(substring.length() > maxLength){
					ans = substring;
					maxLength = substring.length();
				}
			}
		}
	}

	return ans;
}

string optimalApproach(string s){
	if(s.length() <= 1){
		return s;
	}
	
	string lps = "";
	
	for(int i = 0; i < s.length(); i++){
		int low = i;
		int high = i;
		

		while(s[low] == s[high]){
			low--;
			high++;
			if(low == -1 || high == s.length()){
				break;
			}
		}	

		
		string palindrome = s.substr(low + 1, high-low-1);
		if(palindrome.length() > lps.length()){
			lps = palindrome;
		}

		low = i - 1;
		high = i;
		while( s[low] == s[high]  ){
			low--;
			high++;
			if(low == -1 || high == s.length()){
				break;
			}
		}
		palindrome = s.substr(low + 1, high-low-1);
		
		if(palindrome.length() > lps.length()){
			lps = palindrome;
		}
		
	}

	return lps;
}

int main(){
	vector<string> v = {
		"babad",
		"cbbd",
		"a",
		 "aaaa",
		"abc",
	};
	
	cout << "Bruteforce approach" << endl;
	for(string s : v){
		cout << s << endl;
		cout << bruteForceApproach(s) << endl;
		cout << "\n\n";
	}

	cout << "Optimal approach" << endl;
	
	for(string s : v){
		cout << s << endl;
		cout << optimalApproach(s) << endl;
		cout << "\n\n";
	}

	return 0;
}
