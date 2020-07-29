#include <iostream>
#include<direct.h>
#include<string>
#include<fstream>
#include<windows.h>
using namespace std;
void CopiarArchivo(string nombre);
string* CrearDIR();
void crearDirectorios(string nombre);
void crearArchivo();
string* lista(string []);
string *archivo();
int main(){
    //string *arreglo;
    //crearDirectorios();
    // esta funcion crea archivos tipo rar crearArchivo();if(system("dir *.rar")!=NULL){
    //arreglo = archivo();
      //  cout<<arreglo[0];
        //cout<<system("dir")<<endl;

       string *r;
       string l[2000];
       r=CrearDIR();
       for(int i=0;i<2000;i++){
        l[i]= *(r+i);
       }
        r=lista(l);
        for(int i=0;i<2000;i++){
        l[i]= *(r+i);
       }
    for(int i=0;i<2000;i++){
        if(l[i]!="*"&&l[i]!="2")
            {
            crearDirectorios(l[i]);
            CopiarArchivo(l[i]);
            }
    }
    return 0;
}

string* CrearDIR(){
    string renglon;
    int cont=0,temp=0;
   static string r1[2000];
    ifstream archivo;
    int i=0;
    system("dir> dir.txt");
    archivo.open("dir.txt", ios::in);
    while(!archivo.eof()){
            getline(archivo,renglon);
        //archivo>>renglon;

        //en este metodo estamos tomando todas las extenciones de los archivos
        if(renglon[27]!='<'&&renglon[0]!=' '&&renglon[0]!=NULL){
             //cout<<renglon<<endl;

                while(renglon[i]!='\0'){
                if(renglon[i]=='.')
                    {
                    temp=i;
                    cout<<"sa"<<endl;
                    }
                    i++;
             }
             if(temp!=0){
             for(i=temp;i<renglon.size();i++){
             r1[cont]+=renglon[i];
             }
             cout<<r1[cont]<<endl;
             cont++;
             temp=0;}
             i=0;
        }

    }
    cout<<cont<<endl;
    for(int k=cont+1;k<2000;k++){
     r1[k]="*";
    }
    //string* r2=&r1[0];
    system("pause");
    return r1;

}

string* lista(string lista[])
{
    int cont[2000],i=0;

    for(i=0;i<2000;i++){
        cont[i]=0;
    }
    i=0;
    string temp="*";
    for(i=0;i<2000;i++){
        for(int j=0;j<2000;j++){
        if(lista[i]==lista[j]&&lista[i]!="*"&&i!=j)
            {
             lista[j]="2";
            }

        }
    }
    i=0;
    while(lista[i]!="*"){


            cout<<lista[i]<<endl;
        i++;
    }
    system("pause");

    string* l= lista;
    return l;
}

/*en esta funcion se esta verificando un archivo dir
el cual tiene los datos del escritorio*/
string *archivo(){
string p;
ifstream archivo;
archivo.open("aaron.txt", ios::in);
archivo>>p;
int i=0;
int cont=0;
int f=0;
int r = 0;
while(!archivo.eof()){
    archivo>>p;
    i = p.size();
    //en esta parte del codigo verificamos si tiene algun tipo de extencion
        if(p[i-3]=='.')
{
      cout<<p<<endl;
      //si tiene alguna extencion, se agregara un numero al conteo para el siguiente paso
      cont++;
}
}
archivo.close();
archivo.open("aaron.txt", ios::in);
archivo>>p;
//generamos un arreglo con todos los nombres de archivos con extencion
string c[cont];
int aux[cont];
int s=0;
cout<<endl;
while(!archivo.eof()){
    archivo>>p;
    i = p.size();
        if(p[i-3]=='.'){
            //hacemos una lista para tener mejor manejo
         c[f]="";
            for(r=p.size()-3;r<p.size();r++){
        c[f]+=p[r];
        }
         aux[f]=0;
        f++;
        }
}
archivo.close();
for(f=0;f<cont;f++){
    for(i=0;i<cont;i++){
                if(c[f]==c[i]){
                    aux[f]+=1;
                    s++;
                }
                }

}
for(f=0;f<s;f++){
    cout<<aux[f];
    cout<<c[f]<<endl;

    }
string *punt;
punt=&c[cont];
return punt;
}




void crearDirectorios(string nombre){
    string ruta=nombre;
    string test;
    for(int i=0;i<ruta.size();i++){
        ruta[i]=ruta[i+1];
    }
    test="if exist D "+ruta+" return 1";
    //creacion de carpeta
        if(system(test.c_str())==NULL){

    if(mkdir(ruta.c_str())==0)
        cout<<"carpeta creada correctamente"<<endl;
        }

}
void crearArchivo(){
    string tipo="rar";
string ruta1 ="archivo."+tipo;
FILE * archivo;
if(archivo=fopen(ruta1.c_str(),"a"))
    cout<<"archivo creado correctamente";
}

void CopiarArchivo(string nombre){
    string ruta=nombre;
    for(int i=0;i<ruta.size();i++){
        ruta[i]=ruta[i+1];
    }
    string archivo="xcopy *"+nombre+" "+ruta+"\ ";
    try{
 system(archivo.c_str());
 }
 catch(exception e)
 {
     cout<<"error "<<endl;
 }
}
