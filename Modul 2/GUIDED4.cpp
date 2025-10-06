#include <iostream>
using namespace std;

void ubahnilai(int*ptr) {
    *ptr = 20;
}

int main(){
int x = 10 ;
cout << "Nilai sebelum di ubah : " << x <<endl;

ubahnilai(&x);
cout << "Nilai setelah di ubah : " << x << endl;

return 0;
}