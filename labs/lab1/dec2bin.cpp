#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
	if(argc = 0){return 0;}
	/*string deci = argv[1];
	stringstream s(deci);
	int decr;
	s >> decr;
	string o;
	bool sent = true;
	int t1;
	while(sent){
		t1 = decr % 2;
		if(t1 == 0){
			o.insert(0,1,"0");
		}else{
			o.insert*/
	vector<int> bind;
	int n,i;
	n = stoi(argv[1]);
	//n = 12;
	for(i=0;n>0;i++){
		bind.push_back(n%2);
		n=n/2;
	}
	string o = "  ";
	for(i=0;i<bind.size();i++){
		o.append(to_string(bind.at(i)));
	}
	cout << "\n" << o << "\n";
}
