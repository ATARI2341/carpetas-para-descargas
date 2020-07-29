#include<iostream>
#include<direct.h>
#include<windows.h>
using namespace std;
int main()
{
    int i=0;
    string a="aaron";
    for(i=0;i<5;i++)
        {
        a[i]=a[i+1];
        }
    i=0;
    while(a[i]!='\0')
        {
            cout<<a[i];
            i++;
        }


if(system("if exist sa return 1")!=NULL){
        cout<<"carpeta creada correctamente"<<endl;
    }
    return 0;

}
