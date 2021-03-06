// ALL 2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "libsqlite.hpp"
#include "global.h"
using namespace std;

//Gold decrease when bronze armour brought
int golddecarmourbronze(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-20 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Armour bronze - 20 points
int armourbronze(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET armor=armor+20 WHERE idUser =?;");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}



//Gold decrease when silver armour brought
int golddecarmoursilver(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-40 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Armour silver - 60 points
int armoursilver(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET armor=armor+60 WHERE idUser =?;");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}




//Gold decrease when gold armour brought
int golddecarmourgold(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-60 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Armour gold - 100 points
int armourgold(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET armor=armor+100 WHERE idUser =?;");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}





//Gold decrease when large duration brought
int golddecleveljump(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-200 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Level jump - 1 level
int leveljump(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET level=level+1 WHERE idUser=?;");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}





//Gold decrease when small duration brought
int golddecdurationsmall(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-10 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Duration increase - up 3
int durincsmall(sqlite::sqlite &db) {//Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE weapons_user SET duration=duration+3 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}





//Gold decrease when medium duration brought
int golddecdurationmedium(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-30 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Duration increase - up 6 - medium
int durincmedium(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE weapons_user SET duration=duration+6 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}



//Gold decrease when large duration brought
int golddecdurationlarge(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-80 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}
//Duration increase - up 20 - large
int durinclarge(sqlite::sqlite &db) { //Uses the already opened database connection
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE weapons_user SET duration=duration+20 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,globalUserID); //global user id is used to find the users id
    cur2->step();
    return 0;
}


//Calls the users amount of armour
int armourcall(sqlite::sqlite &db){ //Uses the already opened database connection
    auto cur = db.get_statement();   
    cur->set_sql("SELECT armor, username FROM users WHERE idUser=?");
    cur->prepare();
    cur->bind(1,globalUserID); //global user id is used to find the users id
    cur->step();
    int armouruser = cur->get_int(0);
    cout << armouruser << endl;
}



//Calls the users amount of gold
int goldamountcall(sqlite::sqlite &db){ //Uses the already opened database connection
    auto cur = db.get_statement();   
    cur->set_sql("SELECT gold FROM users WHERE idUser=?;");
    cur->prepare();
    cur->bind(1,globalUserID); //global user id is used to find the users id
    cur->step();
    int goldamount = cur->get_int(0);
    cout << goldamount << endl;
}


int shopMain(){  
    
    bool running=false;
    
    while(running!=true)
    {
    sqlite::sqlite db( "dungeonCrawler.db" ); //Opens the connection to the database that will be used througout the program
    auto cur = db.get_statement();   
    cur->set_sql("SELECT gold FROM users WHERE idUser=?;");
    cur->prepare();
    cur->bind(1,globalUserID); //global user id is used to find the users id
    cur->step();
    int goldamount = cur->get_int(0);
   
    
    
    char broughtitem;
    //List of items in the shop
    cout << "Your current gold amount is: " << goldamount << endl;
    cout << "+-------------+---------------------------------+------------+----------+" << endl;
    cout << "| Item number |             Item                |    Value   |   Cost   |" << endl;
    cout << "+-------------+---------------------------------+------------+----------+" << endl;
    cout << "|           1 | Bronze armour potion            | 20 points  | 20 gold  |" << endl;
    cout << "|           2 | Silver armour Potion            | 60 points  | 40 gold  |" << endl;
    cout << "|           3 | Gold armour potion              | 100 points | 60 gold  |" << endl;
    cout << "|           4 | Small weapon duration increase  | 3 points   | 10 gold  |" << endl;
    cout << "|           5 | Medium weapon duration increase | 6 points   | 30 gold  |" << endl;
    cout << "|           6 | Large weapon duration increase  | 20 points  | 80 gold  |" << endl;
    cout << "|           7 | Level Jump                      | 1 level    | 200 gold |" << endl;
    cout << "|           8 | Go back to menu                 | None       | None     |" << endl;
    cout << "+-------------+---------------------------------+------------+----------+" << endl;
    cout << "Please enter your choice: " << endl;
    cin >> broughtitem;
    
   //If statement to run the functions of the item the user has chosen to buy
   if (broughtitem=='1')
   {
        //run armour increase bronze
        if (goldamount>=20) 
        {
            golddecarmourbronze(db);
            armourbronze(db);
            cout << "Your armour has been increased by 20 points!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        } 
   }
        else if (broughtitem=='2')
    {
            //run armour increase silver
        if (goldamount>=40 )
        {
            golddecarmoursilver(db);
            armoursilver(db);
            cout << "Your armour has been increased by 60 points!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem=='3')
    {
        //run armour increase gold
        if (goldamount>=60) 
        {
            golddecarmourgold(db);
            armourgold(db);
            cout << "Your armour has been increased by 100 points!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem=='4')
    {
        //run weapon duration increase small
        if (goldamount>=10) 
        {
            golddecdurationsmall(db);
            durincsmall(db);
            cout << "The duration of all your weapons has been increased by 3 points!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem=='5')
    {
        if (goldamount>=30) 
        {
            golddecdurationmedium(db);
            durincmedium(db);
            cout << "The duration of all your weapons has been increased by 6 points!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem=='6')
    {
        //run weapon duration increase large
        if (goldamount>=80) 
        {
            golddecdurationlarge(db);
            durinclarge(db);
            cout << "The duration of all your weapons has been increased by 20 points!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem=='7')
    {
            //run level increase
        if (goldamount>=200) 
        {
            leveljump(db);
            golddecleveljump(db);
            cout << "Your level has been increased by one!!!" << endl;
            running=true;
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
        else if (broughtitem=='8')
    {
            break;
    }
    else
    {
        cout << "something is wrong" << endl;
    }
        
    }
    
    return 0;
}

  
