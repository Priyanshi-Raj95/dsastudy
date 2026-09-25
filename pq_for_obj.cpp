#include<iostream>
#include<queue>
#include<string>
using namespace std;

// PQ for Objects
class Student{ // "<" overload
public:
    string name;
    int marks;
    Student(string name, int marks){
        this->name= name;
        this->marks= marks;
    }
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
    }
};
// PQ for Pairs
// ----------- This struct is used where we want to get output on basis of second priority---------
// struct ComparePair{
//     bool operator() (pair<string, int> &p1, pair<string, int> &p2){
//         return p1.second < p2.second;
//     }
// };
int main(){
    priority_queue<Student>pq;
    pq.push(Student("Priyanshi", 98));
    pq.push(Student("Satya", 95));
    pq.push(Student("Anvi", 96));
    while(!pq.empty()){
        cout<<"Top = "<<pq.top().name<<", "<<pq.top().marks<<endl;
        pq.pop();
    }
    // priority_queue<pair<string, int>, vector<pair<string, int>>,ComparePair> pq1;
    // this line is used if we want to use second property
    priority_queue<pair<string, int>> pq1; //default - maxHeap; based on first property
    pq1.push(make_pair("Priyanshi", 98));
    pq1.push(make_pair("Satya", 95));
    pq1.push(make_pair("Anvi", 96));
    cout<<"---------------------------------------"<<endl;
    while(!pq1.empty()){
        cout<<"Top = "<<pq1.top().first<<", "<<pq1.top().second<<endl;
        pq1.pop();
    }
    return 0;
}  