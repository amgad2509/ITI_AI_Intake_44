#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* arr;

public:
    // Constructor
    String(char* str = "")
    {
        arr = new char[strlen(str) + 1];
        strcpy(arr, str);
    }

    // Destructor
    ~String()
    {
        delete[] arr;
    }

    // Copy constructor
    String(const String& s)
    {
        arr = new char[strlen(s.arr) + 1];
        strcpy(arr, s.arr);
    }

    // Assignment operator
    String& operator=(String& s)
    {
        if (this != &s) {
            delete[] arr;
            arr = new char[strlen(s.arr) + 1];
            strcpy(arr, s.arr);
        }
        return *this;
    }

    // Getter
    char* get_str()
    {
        return arr;
    }

    // Concatenation operator
    String operator+(String& s)
    {
        String result;
        result.arr = new char[strlen(arr) + strlen(s.arr) + 1];
        strcpy(result.arr, arr);
        strcat(result.arr, s.arr);
        return result;
    }

    // Comparison operators
    int operator==(String& s)
    {
        return strcmp(arr, s.arr) == 0;
    }

    int operator!=(String& s)
    {
        return !(*this == s);
    }

     // Function to get the length of the string
    int length()
    {
        return strlen(arr);
    }
    // Function to convert the string to uppercase
    void toUpperCase()
    {
        for (int i = 0; i < strlen(arr); ++i) {
            arr[i] = toupper(arr[i]);
        }
    }
    // Function to check if the string is empty
    int isEmpty()
    {
        return (length() == 0);
    }

};

int main() {
    const int maxInputSize = 100;
    char input1[maxInputSize];

    cout << "Enter the first string: ";
    cin.getline(input1, maxInputSize);

    String s1(input1);

    char input2[maxInputSize];

    cout << "Enter the second string: ";
    cin.getline(input2, maxInputSize);

    String s2(input2);

    // Concatenation
    String s3 = s1 + s2;
    cout << "Concatenated String: " << s3.get_str() << endl;

    // Comparison
    if (s1 == s2) {
        cout << "s1 is equal to s2" << endl;
    } else {
        cout << "s1 is not equal to s2" << endl;
    }

    ///// Test for some functions:
    cout << "The Upper case for S1 : " << endl;
    s1.toUpperCase();
    cout << s1.get_str() << endl;

    cout << "The Length for S1 : " << endl;
    cout << s1.length() << endl;
    return 0;
}
