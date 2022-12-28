#include<bits/stdc++.h>
#include<fstream>
#include<iostream>
using namespace std;


int main()
{
    string filename = "test.txt";
    fstream file;
    file.open("test.txt", ios::app);
    if(!file){
        cout<<"Error while creating file"<<endl;
    }
    else{
        cout<<"File opened successfully"<<endl;
    }
    // string str = "This is the line i want to write in file";
    // file<<str;

    cout<<"Reading data from file"<<endl;
    string s;
    ifstream infile(filename);
    while(getline(infile, s)){
        cout<<s<<endl;
    }cout<<endl;

    cout<<"-----------searching----------"<<endl;
    string key("krushna");
    ifstream in(filename);
    while(getline(in,s)){
        if(s.find(key)){
            cout<<"Found at: "<<s.find(key);
            break;
        }
    }

    file.close();

    return 0;
}