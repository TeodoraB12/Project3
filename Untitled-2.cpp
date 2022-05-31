#include<iostream>
#include<stdio.h>
#include<string>
#include<regex>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

//funkcija za definiranje na pattern za email
bool Email_proverka(string email)
{
    const regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
int main()
{
    //sodrzinata definirana kako konstanta
    const string sodrzina = "INKI838.Teodora.Bojadzieska";
    string emailAddress;
    //validacija ne emailot 
    cout<<"Vnesete ja vasata email adresa: ";
    cin>>emailAddress;
    if(Email_proverka(emailAddress))
    cout<<"Email adresata e validna"<<endl;
    else
    cout<<"Email adresata ne e validna"<<endl;
    //pecatenje na sodrzinata i emailot spoeni
    cout<<sodrzina;
    cout<<" ";
    cout<<emailAddress;
    cout<<endl;

    vector<int>encrypted;
    string filename;
    ofstream file; 
    int indeks = 838;

    //kreiranje na datoteka
    filename = "INKI" + to_string(indeks) + ".Proekt3.txt";
    //polnenje na vektorot so ASCII kodovite od sodrzinata i emailot
      for (unsigned int i=0; i<sodrzina.size(); i++) {
        encrypted.push_back((int) sodrzina.at(i) + 24 + 1 + 02);
    }
      for (unsigned int i=0; i<emailAddress.size(); i++) {
        encrypted.push_back((int) emailAddress.at(i));
    }
    //soritranje na vektorot
    sort(encrypted.begin(), encrypted.end());

     for (unsigned int i=0; i<encrypted.size(); i++) {
        cout<<encrypted[i]<<" ";
    }
        //pecatenje na vektorot vo datoteka
     file.open(string(filename).c_str());

    for (unsigned int i=0; i<encrypted.size(); i++) {
        file<<encrypted[i]<<" ";

        if(i % 10 == 0 && i!=0){
          file<<endl;
        }
    }

        file.close();

return 0;

}