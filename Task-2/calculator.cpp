#include<iostream>
using namespace std;
int main(){
    int Num1,Num2,Choice;
    cout<<"Enter two Numbers:"; cin>>Num1;
    cin>>Num2;
    cout<<"Choose operation to perform:"<<endl;
    cout<<"1.Addition"<<endl<<"2.Subtraction"<<endl<<"3.Division"<<endl<<"4.Multiplication";
    cin>>Choice;
    switch(Choice){
        case 1:
        cout<<"Sum of two numbers is:"<<Num1+Num2<<endl;
        break;
        case 2:
        cout<<"Difference of two numbers is:"<<Num1-Num2<<endl;
        break;
        case 3:
        cout<<"Division is:"<<Num1/float(Num2)<<endl;
        break;
        case 4:
        cout<<"Multiplication of two numbers is:"<<Num1*Num2<<endl;
        break;
        default:
        cout<<"Make a correct choice!!";
    }
    return 0;

}
