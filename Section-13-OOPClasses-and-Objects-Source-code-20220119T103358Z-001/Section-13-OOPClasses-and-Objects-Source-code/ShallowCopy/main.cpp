// Section 13
// Copy Constructor - Shallow Copy
// Note: this program will crash
#include <iostream>
using namespace std;

class Shallow {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    // Destructor
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source) 
     {
         int *new_int=new int();
         *new_int=*source.data;
        this->data=new_int;
        delete new_int;
        cout<<"source.data :"<<source.data<<endl;
        cout << "Copy constructor  - shallow copy" << endl;
}

Shallow::~Shallow() {
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    
    Shallow obj1 {100};
    display_shallow(obj1);
    
    Shallow obj2 {obj1};
    obj2.set_data_value(1000);
    cout<<endl;
    cout<<"Before Changing Data"<<endl;
    cout<<"Object 1 data-->"<<obj1.get_data_value()<<endl;
    cout<<"Object 2 data-->"<<obj2.get_data_value()<<endl;
    cout<<"After Changing Data"<<endl;
    obj1.set_data_value(25);
    cout<<"Object 1 data-->"<<obj1.get_data_value()<<endl;
    cout<<"Object 2 data-->"<<obj2.get_data_value()<<endl;
    cout<<endl;
    
    
    return 0;
}

