#include <iostream>
#include <string>
#include "libsqlite.hpp"
#include "shop.h"
#include "weaponset.h"
using namespace std;
int shop(){
    sqlite::sqlite db( "dungeonCrawler.db" ); // open database
    bool checkItem = false;
    cout<<"*-----------------------------------*"<<endl;
    cout<<"|        Welcome to the Cave        |"<<endl;
    cout<<"*-----------------------------------*"<<endl;
    cout<<"*-----------------------------------*"<<endl;
    cout<<"| 1 - Weapons                       |"<<endl;
    cout<<"| 2 - Potions or Level jump         |"<<endl;
    cout<<"*-----------------------------------*"<<endl;
    while (checkItem != true){
        char item;
        cin>>item;
        if(item =='1' || item=='2'){
            checkItem = true;
            if (item=='1'){
                Weapons var; //define the object to print all weapons and assign them to a user
                var.idUser = 7; // dont forget to assign this to the globalvariable   HERE
                var.printWeapons(db);  //antonio part of the code
                bool checkgetWeapon = false;
                while(checkgetWeapon != true){
                    int weaponChoice;
                    cin >> weaponChoice;
                    if (weaponChoice>0 && weaponChoice<5){
                        checkgetWeapon = true;
                        var.assignWeapon(weaponChoice, db);
                    } 
                    else{
                        cout<<"You should type a number between 1 and 4"<<endl;
                    }
                }
            }
            else if (item=='2'){
                shoppotions(); //anir part of the code
            }
        }
    }
}
void menu(){
    bool checkMenu = false;
    while(checkMenu != true){
        cout<<"*-------------------*"<<endl;
        cout<<"| 1- Start the game |"<<endl;
        cout<<"| 2- Shop           |"<<endl;
        cout<<"*-------------------*"<<endl;
        char menuChoice;
        cin>> menuChoice; 
        if (menuChoice=='1' || menuChoice =='2'){
            checkMenu = true;
            if (menuChoice == '2'){
                shop();
            }
        }       
    }
    

    
}
int main(){
    menu();
    return 0;
}