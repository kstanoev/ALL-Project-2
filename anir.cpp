// ALL 2.cpp : Defines the entry point for the console application.

#include <iostream>
#include "libsqlite.hpp"

using namespace std;

//Gold decrease when bronze armour brought
int golddecarmourbronze() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-20 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Armour bronze - 20 points
int armourbronze() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET armor=armor+20 WHERE idUser =?;");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}





//Gold decrease when silver armour brought
int golddecarmoursilver() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-40 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Armour silver - 60 points
int armoursilver() {
	sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET armor=armor+60 WHERE idUser =?;");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}




//Gold decrease when gold armour brought
int golddecarmourgold() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-60 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Armour gold - 100 points
int armourgold() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET armor=armor+100 WHERE idUser =?;");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}





//Gold decrease when large duration brought
int golddecleveljump() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-200 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Level jump - 1 level
int leveljump() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET level=level+1 WHERE idUser=?;");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}





//Gold decrease when small duration brought
int golddecdurationsmall() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-10 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Duration increase - up 3
int durincsmall() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE weapons_user SET duration=duration+3 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,1); //change by global variable here
    cur2->step();
    return 0;
}





//Gold decrease when medium duration brought
int golddecdurationmedium() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-30 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Duration increase - up 6 - medium
int durincmedium() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE weapons_user SET duration=duration+6 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,1); //change by global variable here
    cur2->step();
    return 0;
}





//Gold decrease when large duration brought
int golddecdurationlarge() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE users SET gold=gold-80 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,2); //change by global variable here
    cur2->step();
    return 0;
}
//Duration increase - up 20 - large
int durinclarge() {
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur2 = db.get_statement(); 
    cur2->set_sql("UPDATE weapons_user SET duration=duration+20 WHERE idUser =?");
    cur2->prepare();
    cur2->bind(1,1); //change by global variable here
    cur2->step();
    return 0;
}



int armourcall(){ 
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur = db.get_statement();   
    cur->set_sql("SELECT armor, username FROM users WHERE idUser=?");
    cur->prepare();
    cur->bind(1,2); //change by global variable here
    cur->step();
    int armouruser = cur->get_int(0);
    cout << armouruser << endl;
}




int goldamountcall(){
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur = db.get_statement();   
    cur->set_sql("SELECT gold FROM users WHERE idUser=?;");
    cur->prepare();
    cur->bind(1,2); //change by global variable here
    cur->step();
    int goldamount = cur->get_int(0);
    cout << goldamount << endl;
}


int testfunctioninfunction(){
    goldamountcall();
}

int main(){  
    durinclarge();
    golddecdurationlarge();
    
    
    
    /*
    sqlite::sqlite db( "dungeonCrawler.db" ); 
    auto cur = db.get_statement();   
    cur->set_sql("SELECT gold FROM users WHERE idUser=?;");
    cur->prepare();
    cur->bind(1,2); //change by global variable here
    cur->step();
    int goldamount = cur->get_int(0);
    
    int broughtitem;
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
    cout << "|           7 | Level Jump                      | 1 level    | 100 gold |" << endl;
    cout << "+-------------+---------------------------------+------------+----------+" << endl;
    cout << "Please enter your choice: " << endl;
    cin >> broughtitem;
    
    
   if (broughtitem==1)
           //run armour increase bronze
        if (goldamount>=20) 
        {
            golddecarmourbronze();
            armourbronze();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        } 
        else if (broughtitem==2)
    {
            //run armour increase silver
        if (goldamount>=40 )
        {
            golddecarmoursilver();
            armoursilver();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem==3)
    {
        //run armour increase gold
        if (goldamount>=60) 
        {
            golddecarmourgold();
            armourgold();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem==4)
    {
        //run weapon duration increase small
        if (goldamount>=10) 
        {
            golddecdurationsmall();
            durincsmall();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem==5)
    {
        if (goldamount>=30) 
        {
            golddecdurationmedium();
            durincmedium();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem==6)
    {
        //run weapon duration increase large
        if (goldamount>=80) 
        {
            golddecdurationlarge();
            durinclarge();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else if (broughtitem==7)
    {
            //run level increase
        if (goldamount>=200) 
        {
            leveljump();
            golddecleveljump();
        }    
        else
        {
            cout << "You don't have enough gold" << endl;
        }
    }
    else
    {
        cout << "something is wrong" << endl;
    }
    */
    
    return 0;
}

  