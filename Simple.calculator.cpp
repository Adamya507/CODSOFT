#include<bits/stdc++.h>
using namespace std;
    //SIMPLE CALCULATOR

float sum(float a, float b){
    return a+b;
}    

float subtract(float a, float b){
    return a-b;
}    

float multiple(float a, float b){
    return a*b;
}    

float division(float a, float b){
    return a/b;
}    

int main(){
    float a, b;
    char ch;
    cin>>a>>ch>>b;
    int i=0;
    if(ch == '+') cout<<sum(a,b);
    else if(ch == '-') cout<<subtract(a,b);
    else if(ch == '*') cout<<multiple(a,b);
    else if(ch == '/') cout<<division(a,b);
    else cout<<"invalid operator";   
}