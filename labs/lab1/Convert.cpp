#include <cctype> 
#include <iostream>
#include <string>
using namespace std;

enum format  { BINARY, DECIMAL, HEXADEC };

/*------------ FUNCTIONS IN LIBNC ------------*/

void printusage();

void dec2bin(string &, string &);
void bin2dec(string &, string &);
void bin2hex(string &, string &);
void hex2bin(string &, string &);

void processDECIMAL(string &, string &, format);
void processBINARY(string &, string &, format);
void processHEXADEC(string &, string &, format);

/*----------- YOUR IMPLEMENTATIONS -----------*/
// Function to convert int to string since to_string isn't allowed
string itos(int c){
	//cout << "itos starting\n";
	if(c<10){
	//	cout <<"itos detects int < 10\n";
		return string(1,c+'0');
	}
	//cout << "itos detects int > 10\n";
	return itos(c/10)+itos(c%10);
}
//Wow, this is so inconveinent, if only there was built in function that would convert string to int I could use! /s
int stoic(string c){
	int o=0;
	for(int i=0;c[i]!='\0';i++){
		o=o*10+c[i]-48;
	}
	return o;
}

 void dec2bin(string &decin, string &decout) {	
	// Int of decimal input
	cout << "Starting dec2bin\n";
	int deci = stoic(decin);
	cout << "Stoic returns " << deci <<"\n";	
	// 2,147,483,647 is 10 didgits so array will never be longer than that
	int decd[10];
	int i;
	for(i=0;decd>0;i++){
		cout << "Processing\t" << i << "\n";
		decd[i]=deci%2;
		deci=deci/2;
	}
	cout << "Processing done\n";
	// Debuging output first
	for(i=i-1;i>=0;i--){
		cout << decd[i];
	}	
 }

 void bin2dec(string &binin, string &binout) {
        // Uses inp from previous design 
	string inp = binin;
        int l = inp.length();
        //int l =7;
        //int arr[l] = { 0 };
      /*  vector<int> in; 
        for(int i=0;i<l;i++){
                in.push_back(argv[1][i]);
       	}
       	for(int i=0;i<l;i++){
                in[i]=(int)inp[i]-48;
       	}
       	reverse(begin(in),end(in)); */
	// Interger addition of binary count
	int bo=0;
	//cout << "l is " << l << "\n";
        // Loops through length of input string
	for(int i=0;i<l;i++){
		//cout << "Looking at " << inp[i] << "\n" << "Found " << (int)(inp[i]-48) << "\n";
                //Numbers start at 48, so inp[i]-48 as an int is 1 or 0
		if((int)(inp[i])-48==1){
			//cout << "One detected at " << i << "\n Attempting 2 to the power of " << l-i << "\n";
                	// Effective replacement for pow function
			int a = 1;
			for(int j=0;j<l-i-1;j++){
				a*=2;
			}
			//cout << "A is " << a << "\n";
			// Adds to total
			bo+=a;
			//cout << "current bo " << bo << "\n";
		}
        }
	//cout << "int bo is " << bo << "\n";
	// Itos is a custom function to replace to_string
	binout = itos(bo);
	//cout << "Finished my bin2dec funtion\n";
		
 }
// void bin2hex(string &, string &) { optional }
// void hex2bin(string &, string &) { optional }

/*----------- USER INTERFACE CODE ------------*/

int main(int argc, char *argv[]) {
  string mode;
  string input;
  string output;

  format imode = DECIMAL;
  format omode = BINARY;

  while (1) {
    cout << "enter> ";
    cin >> mode;

	if (cin.eof())
	  break;

	if (mode.compare("dec2bin") == 0) {
      imode = DECIMAL;
      omode = BINARY;
    } else 
	if (mode.compare("dec2hex") == 0) {
      imode = DECIMAL;
      omode = HEXADEC;
    } else 
	if (mode.compare("bin2dec") == 0) {
      imode = BINARY;
      omode = DECIMAL;
    } else 
	if (mode.compare("bin2hex") == 0) {
      imode = BINARY;
      omode = HEXADEC;
    } else 
	if (mode.compare("hex2bin") == 0) {
      imode = HEXADEC;
      omode = BINARY;
    } else 
	if (mode.compare("hex2dec") == 0) {
      imode = HEXADEC;
      omode = DECIMAL;
    } else {
	  cout << mode << " unknown\n";
	  continue;
	}

    cin >> input;

    switch (imode) {
    case DECIMAL:
      processDECIMAL(input, output, omode);
      break;
    case BINARY:
      processBINARY(input, output, omode);
      break;
    case HEXADEC:
      processHEXADEC(input, output, omode);
      break;
    }

	cout << output << "\n";
  }
}
