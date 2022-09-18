#include<bits/stdc++.h>
using namespace std;
class Mystring
{
    friend Mystring operator-(const Mystring &obj);                                        // make lowercase
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);       // concatenate
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);           // equals
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs) ;           // not equals
    friend bool operator<(const Mystring &lhs, const Mystring &rhs) ;            // less than
    friend bool operator>(const Mystring &lhs, const Mystring &rhs) ;            // greater than
    friend Mystring &operator+=( Mystring &lhs, const Mystring &rhs);          // s1 += s2;  concat and assign
    friend Mystring operator*(const Mystring &lhs, int n) ;                               // s1 = s2 * 3;  repeat s2 n times
    friend Mystring &operator*=( Mystring &lhs, int n);                                   // s1 *= 3;   s1 = s1 * 3;    
    friend Mystring &operator++(Mystring &obj);                                           // ++s1; pre-increment make uppercase
    friend Mystring operator++(Mystring &obj, int);                                        // s++; post-increment make uppercase
    friend ostream &operator<<(ostream &os, const Mystring &rhs);
    friend istream &operator>>(istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                        // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                      // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;
};


 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       cout << "Copy constructor used" << endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        cout << "Move constructor used" << endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    cout << "Using copy assignment" << endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   cout << "Using move assignment" << endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    cout << str << " : " << get_length() << endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
ostream &operator<<(ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
istream &operator>>(istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// Equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) == 0);
}

// Not equals
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(strcmp(lhs.str, rhs.str) == 0);
}

// Less than
bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) < 0);
}

// Greater than
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (strcmp(lhs.str, rhs.str) > 0);
}

// Make lowercase
Mystring operator-(const Mystring &obj) {
    char *buff = new char[strlen(obj.str) + 1];
    strcpy(buff, obj.str);
    for (size_t i=0; i<strlen(buff); i++) 
        buff[i] = tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// Concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

// concat and assign
Mystring &operator+=( Mystring &lhs, const Mystring &rhs) {
     lhs =  lhs + rhs;
     return lhs;
}

// Repeat
 Mystring operator*(const Mystring &lhs, int n)  {
    Mystring temp;
    for (int i=1; i<= n; i++)
        temp = temp + lhs;
    return temp;
}
        
// Repeat and assign
 Mystring &operator*=( Mystring &lhs, int n) {
        lhs = lhs * n;
        return lhs;
}

// Make uppercase - pre increment
Mystring &operator++(Mystring &obj) {
    for (size_t i=0; i< strlen(obj.str); i++)
        obj.str[i] = toupper(obj.str[i]);
    return obj;
}

// Make uppercase - post-increment
Mystring operator++(Mystring &obj, int) {
    Mystring temp {obj};
    ++obj;      // make sure you call the pre-increment!
    return temp;

}


int main() {
      
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};
    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;          // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    cout << (a!=b) << endl;          // true
     cout << (a<b) << endl;         // true
    cout << (a>b) << endl;          // false
    
    Mystring s1 {"FRANK"};
    s1 = -s1;       
    cout << s1 << endl;             // frank              

    s1 = s1 + "*****";
    cout << s1 << endl;             // frank*****       
    
    s1 += "-----";                      // frank*****-----
    cout << s1 << endl;
    
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;           // 123451234512345
    
    Mystring s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    Mystring repeat_string;
    int repeat_times;
    cout << "Enter a string to repeat: " << endl;
    cin >> repeat_string;
    cout << "How many times would you like it repeated? " << endl;
    cin >> repeat_times;
    repeat_string *= repeat_times;
    cout << "The resulting string is: " << repeat_string << endl;
    
    
    repeat_string = "RepeatMe";
    cout << (repeat_string + repeat_string + repeat_string) << endl;
    
    Mystring s = "Frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s; 
    cout << s << endl;                  // frank
    Mystring result;
    result = ++s;                           
    cout << s << endl;                  // FRANK
    cout << result << endl;           // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    result = s++;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // frank
    return 0;
}




