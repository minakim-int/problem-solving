/*
 * from https://www.acmicpc.net/problem/1316
 * find the word which has separated alphabet
 * for example, 'happy' returns 0, 'puppy' returns 1
 * input: N = number of words to be checked / N words
 * output: accumulation of number of words which returns 1
 */
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	bool alphabet[26] = {false,};
	bool is =false;
	int count = 0; //for output
	cin>>n;
	vector<string>list(n);
	for(int i=0; i<n; i++){
		is = false;
		cin>>list[i];
		alphabet[list[i][0]-97]=true; //check first character of input word
		for(int j=1; j<list[i].length()+1; j++){
			if(list[i][j]!=list[i][j-1]){ //different from character just before
				if(alphabet[list[i][j]-97]){
					is=false; //found overlapped seperate alphabet
					break;
				}
				else{ //same from character just before
					alphabet[list[i][j]-97] = true;
					is=true;
				}
			}
		}
		if(is) count++;
		memset(alphabet, false, 26); //reset checked alphabet array for new word
	}
	printf("%d", count);
}
