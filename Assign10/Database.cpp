#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class Student{
public: string roll, name, address, div;
    Student(string roll, string name, string div, string address){
        this->roll = roll;
        this->name = name;
        this->div = div;
        this->address = address;
    }
};

class Database{
private: 
    fstream fstrm;
    ifstream in;
    string filename;

public: 
    Database(string f){
        this->filename = f;
        createFile();
    }

    void createFile(){
        fstrm.open(filename, ios::app);
        if(!fstrm){
            cout<<"Error while creating file"<<endl;
        }else{
            cout<<"File created successfully"<<endl;
        }
        fstrm.close();
    }

    void addStudent(Student st){
        fstrm.open(filename, ios::app);
        string s = st.name+"\t"+ st.roll+"\t"+ st.div+"\t"+ st.address +"\n";
        fstrm<<s;
        fstrm.close();
    }

    void display(){
        in.open(filename);
        string s;
        while(getline(in, s)){
            cout<<s<<endl;
        }
        in.close();
    }

    void search(){
        in.open(filename);
        cout<<"-----------Searching--------------"<<endl;
        cout<<"Enter roll number of student: ";
        string roll;
        cin>>roll;
        string s;
        bool found =false;
        while(getline(in, s)){
            if(s.find(roll)!= string::npos){// npos means until the end of string
                cout<<s<<endl;
                break;
            }
        }
        in.close();
    }
};

int main()
{
    Database db("data.txt");
    int choice;
    do{
        cout << "\n1.Add student \n2.Display records \n3.Search student \n4.Delete student \n5.Exit: ";
        cin>>choice;

        switch(choice)
        {
        case 1:{
            string roll, name, div,addr;
            cout<<"\nEnter roll: ";
            cin>>roll;
            cout<<"\nEnter name: ";
            cin>>name;
            cout<<"\nEnter division: ";
            cin>>div;
            cout<<"\nEnter address: ";
            cin>>addr;
            Student st(roll, name, div, addr);
            db.addStudent(st);
            break;
        }
        case 2:
            db.display();
            break;
        case 3:
            db.search();
            break;
        default:
            break;
        }
    }while(choice<5);
    return 0;
}