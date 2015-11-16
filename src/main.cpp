#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

string input;
const string output = "outs/output.txt";
int n;
const int k = 21;
const int R = 256;

void readFromFile(vector<string>&, fstream&, string); 
void printToFile(char [][k], fstream&, string); 
void getString(char [][k], vector<string>);
void lsdRadixSort(char [][k]);
void countingSort(char [][k], int );

int main(int argc, char **argv)
{
 
    if (argc < 2) {
        cout<<"Error. Less arguments. Please see README for instructions\n";
        exit(-1);
    }
    string prefix = "ins/"; 
    input = prefix + string(argv[1]);

    fstream fo, fi; 

    vector<string> arr;
 
    readFromFile(arr, fi, input);
    n = arr.size(); 
    
    char S[n][k];
    S[0][0] = ' ';
  

    getString(S, arr);
 
/*   cout<<"\nThe array is \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
	    cout<<S[i][j];
	}
	cout<<endl;
    }*/

    lsdRadixSort(S);
 
   cout<<"\nThe array is \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
	    cout<<S[i][j];
	}
	cout<<endl;
    }

 
    //printToFile(S, fo, output);
  //fo.close(); 
    fi.close(); 
  
    return 0;
}

void readFromFile(vector<string>& arr, fstream& fp, string filename)
{ 

    string names = "";
    string values; 
    char ch;

    fp.open(filename.c_str(), ios::in | ios::binary);

 
    if (fp.is_open()) {    
        while (getline(fp, names)){
	    //cout<<names<<endl;
	    int index = names.find(" ");
	    values = names.substr(0, index);
	    //cout<<values<<endl<<endl;
	    arr.push_back(values);
	}

    }
}


void printToFile(char S[][k], fstream& fo, string filename)
{
    fo.open(filename.c_str(), ios::out | ios::binary);
    if (!fo) {
        cout<<"Error opening the file\n";
	exit(-1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
	    cout<<S[i][j];
	    fo <<S[i][j];
	}
	cout<<endl;
	fo<<endl;
    }
 
}

void getString(char S[][k], vector<string> arr) 
{

    for (int i = 0; i < n; i++) {
        //string temp = arr[i].substr(0, k); 
	int l = arr[i].size();
	for (int j = 0; j < l; j++) {
	    if (j < k) {
	        S[i][j] = arr[i].at(j); 
		//cout<<S[i][j]<<" " ;
	      }
	}
	if (l < k) {
	    for (int j = l ; j < k ; j++) {
	        S[i][j] = '\0';
	    }
	}
	//cout<<endl;
	//cout<<temp<<endl;
	//for (int j = 0; j < temp.size(); j++) {
        //strcpy(S[i], temp.c_str());
	    //S[i][j] = temp[j];
	//}
    }


}



void lsdRadixSort(char S[][k])
{
    int count[k];
    
    for (int d = k - 1; d >=0 ; d--) {
    //for (int d = 0; d < k ; d++) {

	countingSort(S, d);
        //break;
    }
    
}

void countingSort(char S[][k], int j)
{
    int count[256] = {0};
    //char temp[n];

    char temp[n][k];
    temp[0][0] = ' ';


    for (int i = 0; i < n; i++) {
	int valueChar = (int) S[i][j];
	//cout<<"Value char of "<<S[i][j]<<" is "<<valueChar<<endl;
	count[valueChar + 1]++;
	
    }

    for (int p = 1; p < 256; p++) {
        count[p] += count[p - 1];
    }
 
    for (int i = 0; i < n; i++) {
        int valueChar = (int)S[i][j];
        //temp[count[valueChar++]++] = S[i][j];
	strcpy(temp[count[valueChar++]++], S[i]);
    }

    for (int i = 0; i < n; i++) {
        //S[i][j] = temp[i]; 
	//cout<<temp[i]<<endl;
	strcpy(S[i], temp[i]);
        //cout<<S[i]<<endl;
    }

   /* for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
        cout<<"i =  "<<i<<" arr = "<<count[i]<<"    ";
         }
    }
    cout<<endl;*/
	
}
