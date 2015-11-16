#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
    cout<<"n is "<<n<<endl;
    
    char S[n][k];
    memset(S, ' ', sizeof(S));
  

    getString(S, arr);
 
/*    cout<<"\nThe array is \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
	    cout<<S[i][j]<<" ";
	}
	cout<<endl;
    }
*/
    lsdRadixSort(S);

    /*cout<<"\nThe array is \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
	    cout<<S[i][j]<<" ";
	}
	cout<<endl;
    }*/

    printToFile(S, fo, output);
    fi.close(); 
    fo.close(); 

    return 0;
}

void readFromFile(vector<string>& arr, fstream& fp, string filename)
{
    string names = "";
    string values; 
    char ch;

    fp.open(filename, ios::in | ios::binary);

    /*if(fp.is_open()){
        while (fp >> names) {
            arr.push_back(names);
            fp.get();
        }
    }*/
 
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


void printToFile(char S[][k], fstream& fp, string filename)
{
    fp.open(filename, ios::out | ios::binary);
    if (fp.is_open()) {
        for (int i = 0; i < n; i++) {
	    for (int j = 0; j < k; j++) 
	        fp<<S[i][j];
             fp<<endl;
        }
    }
}

void getString(char S[][k], vector<string> arr) 
{

    for (int i = 0; i < n; i++) {
        string temp = arr[i].substr(0, k); 
        strcpy(S[i], temp.c_str());
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
    memset(temp, ' ', sizeof(temp));


    for (int i = 0; i < n; i++) {
	int valueChar = (int) S[i][j];
	//cout<<"Value char of "<<S[i][j]<<" is "<<valueChar<<endl;
	count[valueChar + 1]++;
	
    }

    for (int k = 1; k < 256; k++) {
        count[k] += count[k - 1];
    }
 
    for (int i = 0; i < n; i++) {
        int valueChar = (int)S[i][j];
        //temp[count[valueChar++]++] = S[i][j];
	strcpy(temp[count[valueChar++]++], S[i]);
    }

    for (int i = 0; i < n; i++) {
        //S[i][j] = temp[i];
	strcpy(S[i], temp[i]);
    }

   /* for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
        cout<<"i =  "<<i<<" arr = "<<count[i]<<"    ";
         }
    }
    cout<<endl;*/
	
}
