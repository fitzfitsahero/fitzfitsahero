#include <iostream>

// n -> n/2 if even
// n -> 3n +1 if odd

using namespace std;

int main()
{
  int chain = 0;
  int temp = 1;
  int n;

  for(int i = 1000000; i > 0; i--) {
  //for(int i = 1000; i > 0; i++) {
    n = i;
    while(n <= 1000000 && n != 1) {
      temp++;
      if(n % 2 == 0)
        n = n/2;
      else
        n = 3*n +1;   
//      cout << n << endl;
    }
    if(temp > chain){
      chain = temp;
      //cout << chain << endl;
    }
    temp = 1;
  }

  cout << chain << endl;


  return 0;
}
