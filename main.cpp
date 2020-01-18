#include <iostream>
#include <windows.h>
#include <string.h>
#include <cstdlib>

using namespace std;

const int lenght = 25;

struct Player{
    char nume[lenght];
    int scor;
};

Player player[2];

char v[9] = {'#','#','#','#','#','#','#','#','#'},m[3][3] = {'#','#','#','#','#','#','#','#','#'};
int con=1,ok;
bool finished = 0,matrix;

int score(int n){
    int k = 0;
    if (n < 10)
        return 1;
    else if (n >= 10) k += score(n/10);
    return k;
}

void toplayer(int k){
    cout << "\t" << (char)213;
    for (int i = 1 ; i <= (int)strlen(player[k].nume)+6+score(player[k].scor);i++)
        cout << (char)205;
    cout << (char)184;
}

void bottomlayer(int k){
    cout << "\t" << (char)212;
    for (int i = 1 ; i <= (int)strlen(player[k].nume)+6+score(player[k].scor);i++)
        cout << (char)205;
    cout << (char)190;
    }

void showscore(int k)
{
    toplayer(k);
    toplayer(k+1);
    cout << "\n"<<(char)244<<"SCOR"<<(char)245<<'\t'<<(char)179<<player[k].nume << "[X] > "<< player[k].scor <<(char)179<<'\t'<<(char)179<<player[k+1].nume << "[O] > "<< player[k+1].scor <<(char)179<<'\n';
    bottomlayer(k);
    bottomlayer(k+1);
}

void display(){
    matrix ? cout << "\n\t\t" <<(char)201<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)187<<'\n' : cout << "\n\t\t" <<(char)201<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)187<<'\n';
    matrix ? cout <<"\t\t"<<(char)186<<' '<<m[0][0]<<' '<<(char)186<<' '<<m[0][1]<<' '<<(char)186<<' '<<m[0][2]<<' '<<(char)186<<'\n' : cout <<"\t\t"<<(char)186<<' '<<v[0]<<' '<<(char)186<<' '<<v[1]<<' '<<(char)186<<' '<<v[2]<<' '<<(char)186<<'\n';
    matrix ? cout <<"\t\t"<<(char)204<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)185<<'\n' : cout <<"\t\t"<<(char)204<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)185<<'\n';
    matrix ? cout <<"\t\t"<<(char)186<<' '<<m[1][0]<<' '<<(char)186<<' '<<m[1][1]<<' '<<(char)186<<' '<<m[1][2]<<' '<<(char)186<<'\n' : cout <<"\t\t"<<(char)186<<' '<<v[3]<<' '<<(char)186<<' '<<v[4]<<' '<<(char)186<<' '<<v[5]<<' '<<(char)186<<'\n';
    matrix ? cout <<"\t\t"<<(char)204<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)185<<'\n' : cout <<"\t\t"<<(char)204<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)185<<'\n';
    matrix ? cout <<"\t\t"<<(char)186<<' '<<m[2][0]<<' '<<(char)186<<' '<<m[2][1]<<' '<<(char)186<<' '<<m[2][2]<<' '<<(char)186<<'\n' : cout <<"\t\t"<<(char)186<<' '<<v[6]<<' '<<(char)186<<' '<<v[7]<<' '<<(char)186<<' '<<v[8]<<' '<<(char)186<<'\n';
    matrix ? cout <<"\t\t"<<(char)200<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)188<<'\n' : cout <<"\t\t"<<(char)200<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)188<<'\n';
    }

void showboard(int i = 1){
    i ? system("cls") : i = 0;
    showscore(0);
    display();
}

void winmessage(int p){
    p ? cout << "Felicitari " << player[p].nume << "[O] ai castigat jocul!\n" : cout << "Felicitari " << player[p].nume << "[X] ai castigat jocul!\n";
}

void win2(int k,int x,int y, int z, int x1=0, int y1=0, int z1=0){
    system("cls");
    winmessage(k);
    player[k].scor++;
    if (matrix == 0){
        v[x]=(char)254;v[y]=(char)254;v[z]=(char)254;
    }else{
        m[x][x1]=(char)254;m[y][y1]=(char)254;m[z][z1]=(char)254;
    }
    showboard(0);
    system("pause");
}

void retype(int n){
    system("cls");
    cout << "Nu depasiti intervalul [1," << n <<"]!\n";
    cin.clear();
    cin.ignore(80, '\n');
    cin.ignore(256,'\n');
}

int win(int k, int p){
        if((v[0] == v[4] && v[0] == v[8] && v[0] != '#')||(m[0][0] == m[1][1] && m[0][0] == m[2][2] && m[0][0] != '#')){
            matrix ? win2(k,0,1,2,0,1,2) : win2(k,0,4,8);
            return 1;
        }else if((v[2]==v[4] && v[6] == v[2] && v[2] != '#')||(m[0][2] == m[1][1] && m[0][2] == m[2][0] && m[0][2] != '#')){
            matrix ? win2(k,0,1,2,2,1,0) : win2(k,2,4,6);
            return 1;
        }else if((v[0] == v[1] && v[0] == v[2] && v[0] != '#')||(m[0][0] == m[0][1] && m[0][0] == m[0][2] && m[0][0] != '#')){
            matrix ? win2(k,0,0,0,0,1,2) : win2(k,0,1,2);
            return 1;
        }else if((v[3] == v[4] && v[3] == v[5] && v[3] != '#')||(m[1][0] == m[1][1] && m[1][0] == m[1][2] && m[1][0] != '#')){
             matrix ? win2(k,1,1,1,0,1,2) : win2(k,3,4,5);
            return 1;
        }else if((v[6] == v[7] && v[6] == v[8] && v[6] != '#')||(m[2][0] == m[2][1] && m[2][0] == m[2][2] && m[2][0] != '#')){
             matrix ? win2(k,2,2,2,0,1,2) : win2(k,6,7,8);
            return 1;
        }else if((v[0] == v[3] && v[0] == v[6] && v[0] != '#')||(m[0][0] == m[1][0] && m[0][0] == m[2][0] && m[0][0] != '#')){
             matrix ? win2(k,0,1,2,0,0,0) : win2(k,0,3,6);
            return 1;
        }else if((v[1] == v[4] && v[1] == v[7] && v[1] != '#')||(m[0][1] == m[1][1] && m[0][1] == m[2][1] && m[0][1] != '#')){
             matrix ? win2(k,0,1,2,1,1,1) : win2(k,1,4,7);
            return 1;
        }else if((v[2] == v[5] && v[2] == v[8] && v[2] != '#')||(m[0][2] == m[1][2] && m[0][2] == m[2][2] && m[0][2] != '#')){
             matrix ? win2(k,0,1,2,2,2,2) : win2(k,2,5,8);
            return 1;
        }else if(p == 8){
            cout << "Jocul s-a terminat cu o remiza!\n";
            system("pause");
            system("cls");
            return 2;
        }else return 0;
}

void insertplayer(){
    cout << "Introduceti numele Playerilor:\n";
    do{
        cout << "\tPlayer 1[X] > ";cin >> player[0].nume;
        cin.ignore(80, '\n');
        player[0].scor = 0;
    }while (strlen(player[0].nume)>25);
    do{
    cout << "\tPlayer 2[O] > ";cin >>player[1].nume;
    cin.ignore(80, '\n');
    player[1].scor = 0;
    }while (strlen(player[1].nume)>25);
}

void insertelement(int k,int poz, int poz2 = 0){
    if(matrix == 0){
        if(k){
            v[poz]='O';
        }
        else{
            v[poz]='X';
        }
    }else{
        if(k)
            m[poz][poz2] = 'O';
        else
            m[poz][poz2] = 'X';
    }
}

void conditiontocontinue(int k,int &poz,int j){
    if(k){
        cout << '\n' << "  Alegeti pozitia pe care doriti sa va plasati din intervalul[1,"<<j<<"]:\n  " << player[k].nume <<"[O] > ";cin >> poz;
        cin.ignore(80, '\n');
    }else{
        cout << '\n' << "  Alegeti pozitia pe care doriti sa va plasati din intervalul[1,"<<j<<"]:\n  " << player[k].nume <<"[X] > ";cin >> poz;
        cin.ignore(80, '\n');
    }
    while(cin.fail() || (poz < 1 || poz > j) ){
        cin.clear();
        cin.ignore(256,'\n');
        if(k){
            cout << '\n' << "  Alegeti pozitia pe care doriti sa va plasati din intervalul[1,"<<j<<"]:\n  " << player[k].nume <<"[O] > ";cin >> poz;
            cin.ignore(80, '\n');
        }else{
            cout << '\n' << "  Alegeti pozitia pe care doriti sa va plasati din intervalul[1,"<<j<<"]:\n  " << player[k].nume <<"[X] > ";cin >> poz;
            cin.ignore(80, '\n');
        }
    }
}

void disp(int k){
    int l = 0,poz,a[10],b[10],j=0;
    if (matrix==0){
        cout << "Pozitii disponibile:\n";
        for(int i = 0; i <= (int)strlen(v);i++){
            if(v[i]=='#'){
                j++;
                if(i < 3){
                    cout <<j<<")Randul 1 > Celula "<<i+1<<'\t';
                    a[j] = i;
                    if(i+1==3)
                        cout << '\n';
                }else if(i == 3){
                    if (i < 6){
                        cout <<j<<")Randul 2 > Celula 1"<<'\t';
                        a[j] = i;}
                }else if(i < 6){
                    cout <<j<<")Randul 2 > Celula "<<i-2<<'\t';
                    a[j] = i;
                    if(i+1==6)
                        cout << '\n';
                }else if(i == 6){
                    if(i < 9){
                        cout <<j<<")Randul 3 > Celula 1"<<'\t';
                        a[j] = i;}
                }else if(i < 10){
                    cout <<j<<")Randul 3 > Celula "<<i-5<<'\t';
                    a[j] = i; }
            }
        }
        conditiontocontinue(k,poz,j);
        insertelement(k,a[poz]);
        }else{
            cout << "Pozitii disponibile:\n";
            for(int i = 0; i < 3;i++){
                for(int j = 0 ; j < 3 ;j++){
                    if(m[i][j]=='#'){
                        l++;
                        cout <<l<<")Randul "<< i+1 <<" > Celula "<<j+1<<'\t';
                        a[l] = i;
                        b[l] = j;
                    }
                }
                cout << '\n';
            }
        conditiontocontinue(k,poz,l);
        insertelement(k,a[poz],b[poz]);
        }
}

void resetscore(){
    player[1].scor = 0;
    player[0].scor = 0;
}

void changeplayer(){
    if(player[0].scor || player[1].scor || finished){
        system("cls");
        cout << "Doriti sa schimbati un Player?\n\t1)Da\n\t2)Nu\n\t3)Iesire Joc!\n\tAlegere > ";cin>>ok;
        cin.ignore(80, '\n');
        while(cin.fail() || (ok < 1 || ok > 3) ){
            retype(3);
            cout << "Doriti sa schimbati un Player?\n\t1)Da\n\t2)Nu\n\t3)Iesire Joc!\n\tAlegere > ";cin>>ok;
        }
        switch (ok){
            case 1:{
                system("cls");
                cout << "Ce player doriti sa schimbati?\n";
                cout <<"\t1)"<<player[0].nume<<"[X]\n\t2)"<<player[1].nume<<"[O]\n\t3)"<<"Amandoi\n\t4)Nici unul!\n\tAlegere > ";cin >>ok;
                cin.ignore(80, '\n');
                while(cin.fail() || (ok < 1 || ok > 4) ){
                    retype(4);
                    cout << "Ce player doriti sa schimbati?\n";
                    cout <<"\t1)"<<player[0].nume<<"[X]\n\t2)"<<player[1].nume<<"[O]\n\t3)"<<"Amandoi\n\t4)Nici unul!\n\tAlegere > ";cin >>ok;
                    cin.ignore(80, '\n');
                }
                switch (ok){
                    case 1:{
                        system("cls");
                        cout <<"Introduceti Playerul: \n\tPlayer 1[X] > ";cin >> player[0].nume;
                        cin.ignore(80, '\n');
                        resetscore();
                        break;
                    }case 2:{
                        system("cls");
                        cout <<"Introduceti Playerul: \n\tPlayer 1[O] > ";cin >> player[1].nume;
                        cin.ignore(80, '\n');
                        resetscore();
                        break;
                    }case 3:{
                        insertplayer();
                        break;
                    }case 4:{
                        break;
                    }
                }
                break;
            }case 3:{
                system("cls");
                cout << "Sunteti sigur ca doriti sa parasiti jocul?\n\t1)Da\n\t2)Nu\n\tAlegere > ";cin >>ok;
                cin.ignore(80, '\n');
                while(cin.fail() || (ok < 1 || ok > 2) ){
                    retype(2);
                    cout << "Sunteti sigur ca doriti sa parasiti jocul?\n\t1)Da\n\t2)Nu\n\tAlegere > ";cin >>ok;
                }
                switch(ok){
                    case 1:{
                        exit(0);
                        break;
                    }case 2:{
                        changeplayer();
                        break;
                    }
                }
            }
        }
    }
}

void returntostart(){
    system("cls");
        cout << "Doriti sa continuati jocul?\n\t1)Da\n\t2)Nu\n\tAlegere > ";cin >> ok;
        cin.ignore(80, '\n');
        while(cin.fail() || (ok < 1 || ok > 2) ){
                retype(2);
                cout << "Doriti sa continuati jocul?\n\t1)Da\n\t2)Nu\n\tAlegere > ";cin >> ok;
                cin.ignore(80, '\n');
            }
            switch(ok){
                case 1:{
                    if (matrix == 0)
                        strcpy(v,"#########");
                    else{
                        for (int i = 0 ; i <= 2; i++)
                            for (int j = 0 ; j <= 2 ; j++)
                                m[i][j] = '#';
                    }
                    con = 1;
                    finished = 1;
                    system("cls");
                    break;
                }
                case 2:{
                    con = 0;
                    break;
                    }
            }
}

int main(){
    system("title Tic-Tac-Toe by Serban Marin-Eusebiu");
    cout << "Bun Venit la jocul de X si 0, doriti sa intrati sau sa iesiti?\n\t1)Intrare\n\t2)Iesire\n\tAlegere > ";cin >> ok;
    cin.ignore(80, '\n');
    while(cin.fail() || (ok < 1 || ok > 2) ){
                retype(2);
                cout << "Bun Venit la jocul de X si 0, doriti sa intrati sau sa iesiti?\n\t1)Intrare\n\t2)Iesire\n\tAlegere > ";cin >> ok;
    }
    if (ok == 2) exit(0);
    else system("cls");
    insertplayer();
    while(con){
    int p = 0,winner=0,mat;
    system("cls");
    cout << "Ce model de joc doriti sa utilizati?\n\t1)Vector\n\t2)Matrice\n\tAlegere > ";cin >> mat;
    cin.ignore(80, '\n');
    while(cin.fail() || (mat < 1 || mat > 2) ){
        retype(2);
        cout << "Ce model de joc doriti sa utilizati?\n\t1)Vector\n\t2)Matrice\n\tAlegere > ";cin >> mat;
    }
    mat -=1;
    matrix = mat;
    changeplayer();
    showboard();
    while(winner == 0){
        disp(p%2);
        showboard();
        winner = win(p%2,p);
        p++;
    }
    returntostart();
    }
    return 0;
}
