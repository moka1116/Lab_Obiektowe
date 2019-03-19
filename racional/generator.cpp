#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
int counter;
    cin>>counter;
    string nameTab[20]={"Abarath","Alfa Romeo","Dodge","Dacia","BMW","Bugatti","Citroen","Audi","Jeep","Labia","Hyundai","Opel","Lamborghini","Land Rover","KIA","Jaguar","lexus","mini","MG","Nissan"};
    string model[5]{"a","b","c","d","e"};
    cout<<counter<<endl;
    for(int i=0; i<counter; i++){
        cout<<nameTab[rand()%19]<<" "<<model[rand()%4]<<model[rand()%4]<<model[rand()%4]<<model[rand()%4]<<model[rand()%4]<<endl;
        cout<<rand()%10000000<<" "<<rand()%1000<<endl;

    }
}