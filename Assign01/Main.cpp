
/*
Consider a student database of SEIT class (at least 15 records). Database contains different fields of
every student like Roll No, Name and SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers in ascending order (UseBubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use Quick sort)
d) Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.
e) Search a particular student according to name using binary search without recursion. (all the student records having the presence of search key should be displayed)
*/



#include<bits/stdc++.h>
using namespace std;
#define max_size 4

struct student
{
    string name;
    int rno;
    float sgpa;
};

class StudentData{
    public:
        student s[max_size] = {
        {"krushna", 32, 7.4},
        {"manish", 15, 4.6},
        {"om", 23, 9.5},
        {"sahil", 54, 9.5},
    };
        void takeInput(){
            cout<<"-------------------Enter details--------------"<<endl;
            for (int i = 0; i < max_size; i++)
            {
                cout<<"Enter name: ";
                cin>>s[i].name;
                cout<<"Enter roll no: ";
                cin>>s[i].rno;
                cout<<"Enter SGPA: ";
                cin>>s[i].sgpa;
                cout<<endl;
            }
            cout<<endl;
        }
        void display(){
            cout<<endl<<"-----------Student Details--------------"<<endl;
            for(int i =0 ;i<max_size; i++){
                cout<<"Name: "<<s[i].name<<endl;
                cout<<"Roll no: "<<s[i].rno<<endl;
                cout<<"SGPA: "<<s[i].sgpa<<endl;
                cout<<endl;
            }
            cout<<endl;
        }
        void linearSearch(){
            // Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.
            float sg;
            cout<<"Enter SGPA of students to find: ";
            cin>>sg;
            for(int i =0 ;i<max_size; i++){
                if(s[i].sgpa == sg){
                    cout<<s[i].name<<endl;
                    cout<<s[i].rno<<endl;
                    cout<<s[i].sgpa<<endl;
                    cout<<endl;
                }
            }cout<<endl;
        }
        void bubbleSort(){
            // arrange students according to roll no in ascening order
            for(int i = 0; i < max_size; i++){
                for(int j = 0; j <= max_size-1-i; j++){
                    if(s[j].rno > s[j+1].rno){
                        swap(s[j], s[j+1]);
                    }
                }
            }
            cout<<"After bubble sort: "<<endl;
            display();
        }

        void insertionSort(){
            // Arrange list of students alphabetically. (Use Insertion sort)
            for(int i =1; i< max_size ; i++){
                string key = s[i].name;
                int key1 = s[i].rno;
                float key2 = s[i].sgpa;
                int j = i -1;
                while(j >= 0 && (s[j].name > key) ){
                    s[j+1] = s[j];
                    j--;
                }
                // we get smaller than our key
                s[j+1].name = key;
                s[j+1].rno = key1;
                s[j+1].sgpa = key2;
            }
            display();
        }

        void binarySearch(){
            string key;
            cout<<"Enter name to search in database: ";
            cin>>key;
            int low =0;
            int high = max_size - 1;
            while(low<=high){
                int mid = (high+low)/2;
                if(key == s[mid].name){
                    cout<<"Found "<<endl;
                    return;
                }
                else if(key < s[mid].name){
                    high = mid -1 ;
                }else if(key > s[mid].name){
                    low = mid + 1;
                }
            }
            if(low > high){
                cout<<"Records not found"<<endl;
            }
        }

        int partition(int low, int high){
            float pivot;
            int i, j;
            pivot = s[low].sgpa;
            i = low;
            j = high;
            while(i<j){
                while(pivot < s[i].sgpa)i++;
                while(pivot >= s[j].sgpa && j>0)j--;
                if(i<j){
                    swap(s[i],s[j]);
                }
            }
            if(i!=j){
                swap(s[j], s[low]);
            }

            return j;
        }

        void quickSort(int low, int high){
            if(low<high){
                int pivot = partition(low, high);
                quickSort(low, pivot-1);
                quickSort(pivot+1, high);
            }
        }
};

int main()
{
    StudentData st;
    // st.takeInput();
    // st.display();

    int choice;
    do{
        cout << "\n1.Enter an element for linear search in Database";
        cout << "\n2.Enter an element for Binary search in Database";
        cout << "\n3.Bubble Sorting Roll no of Database";
        cout << "\n4.Insertion Sorting to arrange names alphabetically of Database";
        cout << "\n5.Quick Sorting of 10 Toppers of Database";
        cout << "\n6.Exit";
        cout << "\n\nEnter your choice: ";
        cin>>choice;
        

        switch (choice)
        {
        case 1:
            st.linearSearch();
            break;
        case 2:
            st.binarySearch();
            break;
        case 3:
            st.bubbleSort();
            break;
        case 4:
            st.insertionSort();
            break;
        case 5:
            st.quickSort(0, max_size-1);
            st.display();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }

    }while(choice<5);

    return 0;
}