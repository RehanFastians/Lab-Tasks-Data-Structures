#include<bits/stdc++.h>

using namespace std;
class Exam{
    string* student_name=nullptr;
    string* exam_date=nullptr;
    int* score=nullptr;
    public:
    void setName(string s){
        if(student_name)
            *student_name =s;
        else
            student_name = new string(s);
    }
    void setExamDate(string s){
        if(exam_date)
            *exam_date = s;
        else
            exam_date = new string(s);
    }
    void setScore(int s){
        if(score)
            *score = s;
        else
            score = new int(s);
    }
    void displayDetails() const{
        cout<<"\nStudent Name : "<<*student_name;
        cout<<"\nExam Date : "<<*exam_date;
        cout<<"\nScore : "<<*score;
    }
    ~Exam(){
        delete student_name;
        delete exam_date;
        delete score;
    }
};
int main(){
    Exam s1;
    s1.setName("AbdullahPrhaku");
    s1.setScore(100);
    s1.setExamDate("10/10/2005");
    cout<<"\n Details of student 1";
    s1.displayDetails();
    Exam s2(s1);
    cout<<"\n Details of student 2 (copied from student 1)";
    s2.displayDetails();
    s2.setName("AbdullahShantu");
    s2.setExamDate("AbdullahShantu");
    s2.setScore(101);
    cout<<"\n Details of student 1 (after modifying student2)";
    s1.displayDetails();    
    return 0;
}