#include<bits/stdc++.h>

using namespace std;
class Box{
    int* value;
    public:
    Box(int v){value = new int(v);}
    // Deep Copy Constructor
    Box(Box& o){
        value = new int(*(o.value));
    }
    // Shallow Copy Constructor
    // Box(Box& o){
    //     value = o.value;
    // }
    ~Box(){delete value;}
    void operator=(Box& o){
        value = new int(*(o.value));
    }
    void modifyValue(int v){*value = v;}
    void printValue() const{cout<<"Value : "<<*value<<endl;}
};
int main(){
    Box b1(10);
    Box b2(b1);

    cout<<"Value of b1 :\n";
    b1.printValue();

    cout<<"Value of b2 :\n";
    b2.printValue();

    cout<<"Modifying b2 : \n";
    b2.modifyValue(5);
    b2.printValue();
    
    cout<<"Value of b1 after modifying b2 :\n";
    b1.printValue();
    cout<<"This shows that the copy is deap";
    return 0;
}