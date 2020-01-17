#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]){
        if(argc = 0){return 0;} 
        string inp = argv[1];
        int l = inp.length();
        //int l =7;
        //int arr[l] = { 0 };
        vector<int> in; 
        for(int i=0;i<l;i++){
                in.push_back(argv[1][i]);
        }
        for(int i=0;i<l;i++){
                in[i]=(int)inp[i]-48;
        }
        reverse(begin(in),end(in));
        int f=0;
        for(int i=0;i<l;i++){
                //cout << "f is currently " << f << " in[i] is " << in[i] << " power is " << i << " resulting in " << pow(2, i) << "\n";
                //f+=pow(in[i], i);
                if(in[i]==1){
                        f+=pow(2,i);
                }
        }
	cout << f << "\n";
}     
