#include<bits/stdc++.h>

using namespace std;
class Product{
    string name;
    double price;
    int stock;
    public:
    Product(){}
    Product(string name, double price, int stock) : name(name), price(price), stock(stock){}
    void displayDetails() const{
        cout<<"\n Product Details:-";
        cout<<"\n Name : "<<name;
        cout<<"\n Price : "<<price;
        cout<<"\n Stock : "<<stock;
    }
};
class Bundle{
    Product *products=nullptr;
    int productCount = 0;
    double discount_percentage=0;
    public:
    Bundle(Product *list, int count, double discount){
        products = new Product[count];
        for(int i=0;i<count;i++)    products[i] = list[i];
        productCount = count;
        discount_percentage = discount;
    }
    // Deep copy
    Bundle(Bundle&  o){
        products = new Product[o.productCount];
        for(int i=0;i<o.productCount;i++)    products[i] = o.products[i];
        productCount = o.productCount;
        discount_percentage = o.discount_percentage;
    }
    // Shallow Copy
    // Bundle(Bundle&  o){
    //     products=o.products;
    //     productCount = o.productCount;
    //     discount_percentage = o.discount_percentage;
    // }
    void applyDiscount(double d){discount_percentage=d;}
    void addProduct(Product p){
        Product* temp = new Product[productCount+1];
        for(int i=0;i<productCount;i++) temp[i]=products[i];
        temp[productCount++]=p;
        delete[] products;
        products=temp;
    }
    void display(){
        cout<<"\n Discount : "<<discount_percentage<<"%";
        cout<<"\nDetails of Products in this bundle :-";
        for(int i=0;i<productCount;i++){
            cout<<"\n"<<i+1<<". ";
            products[i].displayDetails();
        }
    }
    ~Bundle(){
        delete[] products;
    }
};
int main(){
    Product* p= new Product[3];
    for(int i=1;i<=3;i++){
        p[i-1] = Product("Product " + to_string(i), i*100, i*5);
    }
    cout<<endl<<"Product List : ";
    for(int i=0;i<3;i++)    p[i].displayDetails();

    Bundle b(p, 3, 0);
    cout<<endl<<"Initital Bundle b";
    b.display();

    Bundle b2(b);
    cout<<endl<<"Initital Bundle b2";
    b2.display();

    b2.addProduct(Product("Product 4", 400, 20));
    cout<<endl<<"Bundle b2 after adding product in b2";
    b2.display();
    cout<<endl<<"Bundle b after adding product in b2";
    b.display();
    return 0;
}