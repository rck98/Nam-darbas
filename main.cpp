#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    string vardas[15], pavarde[15];
    int a=1;
    double galutinis[15];
    double egzaminas;
    double mediana[15];
    double *pazymiai, *temp;
    double k;
    int p;
    int x=0;

    do
    {
        x++;
        double sum=0;
    int n=1;
    pazymiai = new double [n];
    cout<<"iveskite Varda: ";
    cin>>vardas[x];
    cout<<"iveskite Pavarde: ";
    cin>>pavarde[x];
    cout<<"Iveskite namu darbu rezultatus: " ;
    while(k!=0){
        cin>>k;
    if (k!=0 && k>0 && k<11)
    {
        pazymiai[n]=k;
        temp=new double [n+1];
        temp=pazymiai;
        delete[](pazymiai);
        n++;
        pazymiai=new double [n];
        pazymiai=temp;
        delete[](temp);
    }
    }
    k=1;
    for(int i=0 ;i<n ;i++)
    {
        sum+=pazymiai[i];
    }
        cout<<"Iveskite egzamino rezulta: ";
    cin>>egzaminas;
    pazymiai[n]= egzaminas;
    galutinis[x]=(sum/(n-1))*0.4+0.6*egzaminas;
    sort(pazymiai,pazymiai+n+1);
    if(n%2!=0)
    {
        p=(n/2)+1;
     mediana[x]=pazymiai[p];
    }
    else
    {
        p=n/2;
        mediana[x]=(pazymiai[p]+pazymiai[p+1])/2;
    }
    cout<<"Jei norite testi spauskite 1 ";
        cin>>a;
}
        while (a==1);
        cout<<"Spauskite 1 noredami pamatyti vidurki, spauskite 2 noredami pamatyti mediana: ";
        int b;
        cin>>b;
    if(b==1)
    {
    cout<<setw(15)<<left<<"Vardas "<<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis (Vid.) "<<endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(int j=1;j<=x;j++)
    cout<<setw(15)<<left<<vardas[j]<<setw(15)<<left<<pavarde[j]<<setw(20)<<right<<setprecision(3)<<right<<galutinis[j]<<endl;
    }
    else
    {
        cout<<setw(15)<<left<<"Vardas "<<setw(15)<<left<<"Pavarde "<<setw(20)<<right<<"Galutinis (Mediana) "<<endl;
    cout.fill('-');
    cout.width(50);
    cout<<"-"<<endl;
    cout.fill(' ');
    for(int j=1;j<=x;j++)
    cout<<setw(15)<<left<<vardas[j]<<setw(15)<<left<<pavarde[j]<<setw(20)<<right<<setprecision(3)<<right<<mediana[j]<<endl;
    }
}
