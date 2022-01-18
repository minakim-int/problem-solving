/* 
 * from https://www.acmicpc.net/problem/1259
 * find palindrome number
 * ignore first 0
 * run until input only 0
*/

#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> word;
	int num;
	cin>>num;
	while(num){
		while(!word.empty()) word.pop(); //init stack
		bool pal = true;
		int temp = num;
		int count = 0; //counting length of number
		while(temp != temp%10){ //until remain one digit
			temp /= 10;
			count++;
		}
		count++;
			int temp_count = count/2;
			while(temp_count){ //131
				while(temp_count){ //1
					word.push(num%10);
					num /= 10;
					temp_count--;
				}
			}
			if(count%2!=0)
				num /= 10; //if number's length is odd, ignore middle digit
			while(!word.empty()){
				if(word.top()==num%10){
					word.pop();
					num/=10;
				}
				else{
					printf("no\n");
					pal = false;
					break;
				}
			}
			if(pal){
				printf("yes\n");
			}
		cin>>num;
  }
}
