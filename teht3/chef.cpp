#include "chef.h"

Chef::Chef(string nimi) {
    name = nimi;
    cout<<"Chef "<<name<<" konstruktori"<<endl;
}
Chef::~Chef(){
    cout<<"Chef "<<name<<" destruktori"<<endl;
}
void Chef::makeSalad(){
    cout<<"Chef "<<name<<" makes salad"<<endl;
}
void Chef::makeSoup(){
    cout<<"Chef "<<name<<" makes soup"<<endl;
}

ItalianChef::ItalianChef(string nimi, int a, int b): Chef(nimi) {
    cout<<"Chef "<<name<<" konstruktori"<<endl;
}
ItalianChef::~ItalianChef() {}

string ItalianChef::getName(){
    return name;
}
void ItalianChef::makePasta(int a, int b){
    cout<<"Chef"<<name<<" makes pasta with special recipe"<<endl;
    cout<<"Chef"<<name<<" uses jauhoja = "<<b<<endl;
    cout<<"Chef"<<name<<" uses vettä = "<<a<<endl;
}
