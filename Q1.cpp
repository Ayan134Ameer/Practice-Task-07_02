#include <iostream>
#include <cstdlib>
using namespace std;

void Guess(int randomNum,int input){
    if (randomNum==input)
    {
        cout << "Number guessed correctly" << endl;
        return;
    }
    else if(input>randomNum){
        cout << "Guessed number is too high" << endl;
        cin >> input;
        return Guess(randomNum,input);
        
    }
    else{
        cout << "Guessed number is too low" << endl;
        cin >> input;
        return Guess(randomNum,input);
    }
    

}

int main() {
    srand(time(0));
    int randomNum = rand()%101;
    int n;
    cout << "Guess the number" << endl;
    cin >> n;
    Guess(randomNum,n);

   return 0;
}