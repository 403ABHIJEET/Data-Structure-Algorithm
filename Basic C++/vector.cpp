#include<iostream>
#include<exception>
using namespace std;

template <typename T>
class vector {
    int capacity = 2;
    T* arr = new int[capacity];
    int idx = 0;
    void resize() {
        T* newArray = new int[capacity];
        for(int i=0; i<capacity; i++)
            newArray[i] = arr[i];
        capacity *= 2;
        arr = new int[capacity];
        for(int i=0; i<capacity; i++)
            arr[i] = newArray[i];
    }
    public:
    void push_back(T val) {
        if(idx==capacity) 
            resize();
        arr[idx] = val;
        idx++;
    }
    void pop_back() {
        if(idx==0) {
            cerr<<"Underflow"<<endl;
            return;
        }
        idx--;
    }
    int size() {
        return idx;
    }
    T &operator[](int i) {
        try {
            if(i<0 or i>=idx)  throw runtime_error(" Index out of bound");
            else return arr[i];
        }
        catch(const exception &e) {
            cerr<<endl<<"Caught exception"<<endl<<e.what()<<endl;
        }
    }
};

int main() {
    vector<int> v;
    for(int i=0; i<8; i++)
        v.push_back(i);
    for(int i=0; i<8; i++)
        cout<<v[i]<<" ";
    cout<<endl<<v[3]<<endl;
    return 0;
}