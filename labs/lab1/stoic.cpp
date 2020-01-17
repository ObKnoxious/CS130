#include <iostream>
int stoic(char c){
	/*int s=0;
	while(*s >= '0' && *s <= '9'){
		s=s * 10 + (*s - '0');
		s++;
	}
	return s;*/
	return (int)c -48;
}
int main(){
	std::cout << stoic('0') << "\t" << stoic('8') << "\n";
}
