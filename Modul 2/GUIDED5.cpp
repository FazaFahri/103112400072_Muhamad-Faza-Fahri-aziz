#include <iostream>
using namespace std;

void ubahnilai(int&ref) { 
    ref = 20;
}

int main (){
int x =10;
cout << "Nilai sebelum di ubah " << x <<endl;

ubahnilai(x);
cout << "Nilai di ubah : " << x<< endl;

return 0 ;
}