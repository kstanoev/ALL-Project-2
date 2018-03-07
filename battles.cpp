#include <iostream>
#include <string>
#include <stdlib.h> 
#include "libsqlite.hpp"
#include "battleScenario.h"
#include <unistd.h> //for usleep stuff
using namespace std;
int waitAbit(int sec){
    usleep(sec * 1000000); //the parameter works in micro-seconds 
}

class Battles{
    public:
    int idUser;
    int idMonster;
    void printWeapons(){
        //function to print all the weapons the user has
        int counter = 2;
        sqlite::sqlite db( "dungeonCrawler.db" ); // open database
        auto cur = db.get_statement(); // create query
        //join query between weapon and weaponds_user
        cur->set_sql("SELECT w.idWeapon, w.type, w.damage, w.attack, wu.duration FROM weapon w, weapons_user wu  WHERE (idUser=? AND w.idWeapon = wu.idWeapon)"); 
        //0-id weapon . 1-type. 2-damage. 3-attack. 4-duration from weapons_user. 
        cur->prepare();
        cur->bind(1,idUser);
        cout<<"Your weapons:"<<endl;
        cout<<"0- Punch"<<"   "<<"10"<<endl;
        while(cur->step()){
            int totalDamage = cur->get_int(2)*cur->get_int(3);
            //example output weapon(duration) attack%
            cout<<cur->get_int(0)<<"- "<<cur->get_text(1)<<"("<<cur->get_int(4)<<") "<<totalDamage<<"&"<<endl;
            counter = counter +1;
        }

    }
    void printMonsterStatus(){
        sqlite::sqlite db( "dungeonCrawler.db" ); // open database
        auto cur_monster = db.get_statement(); // create query
        cur_monster->set_sql("SELECT * FROM monsters WHERE idMonster=?");
        //0-id monster(int) . 1-name(text) . 2-health(int) . 3-attack(int) . 4-counter attack(int)
        cur_monster->prepare();
        cur_monster->bind(1,idMonster);
        cur_monster->step();
        cout<<"Health("<<cur_monster->get_int(2)<<") "<<"Attack("<<cur_monster->get_int(3)<<")+3*level "<<"Counter Attack("<<cur_monster->get_int(4)<<")"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }
    int setUserVariables(){
        
        //function to set user status between turns
        
        return 0;
    }
    int monsterAttack(){
        return 0;
    }
};

int main(){
    int attackW;
    int damageW;
	sqlite::sqlite db("dungeonCrawler.db");//open database
	auto cur = db.get_statement();//create query
    auto cur2 = db.get_statement();
    
    cout<<" Wait until your opponent get ready"<<endl;
    waitAbit(1);
    cout <<"."<<endl;
    waitAbit(1);
    //system("cls"); 
    cout<<"The opponent is cutting his nails"<<endl;
    waitAbit(2);
    cout<<"Let's get started"<<endl;
    cur->set_sql("SELECT COUNT(idMonster) FROM monsters");//to get the number os monsters that exist
    cur->prepare();
    cur->step();
    int numOfMonsters = cur->get_int(0);
    srand(time(0));
    int idMonster = rand() % numOfMonsters + 1; //generate a number between 1-4
    cur2->set_sql("SELECT * FROM monsters WHERE idMonster=?"); 
    // 0-idOnster . 1-name . 2-health . 3-attack . 4-counterattack   
    cur2->prepare();
    cur2->bind(1,idMonster);
    cur2->step();
    cout<<"You will fight against: "<< cur2->get_text(1)<<endl;
    bool stopGame = false;
    if (idMonster==1)
        warrior();
    else if (idMonster==2)
        mage();
    else if (idMonster==3)
        hunter();
    else if (idMonster==4)
        dragQueen();
    else
        cout<<"you are not lucky today"<<endl;
    while(stopGame != true){
        //load mosnter variables about random number
        cur = db.get_statement();//clean the one used before to create query
        Battles var;  // create the object
        var.idUser = 1;            //CHANGEEEE, THIS VALUE IS ONLY FOr TESTING REASONS
        var.idMonster = idMonster;
        var.printMonsterStatus();//print the monster status
        var.printWeapons(); //print all the weapons the user has
        int weaponToUSe;
        cin >> weaponToUSe;
        auto cur_battle = db.get_statement();//create query
        //query to load user and monster variables
        cur_battle->set_sql("SELECT u.maxHealth, u.armor, u.level, m.health, m.attack, m.counterAttack FROM users u, monsters m WHERE u.idUser==? AND m.idMonster=?");
        //0-user health . 1-user armor . 2-user level . 3-monster health . 4-monster attack . 5-monster counterattack  all int
        cur_battle->prepare();
        cur_battle->bind(1,1);         // HERE AS WELLLLL, CHANGEE
        cur_battle->bind(2,idMonster);
        cur_battle->step();
        int user_health = cur_battle->get_int(0);
        int user_armor = cur_battle->get_int(1);
        int user_level = cur_battle->get_int(2);
        int monster_health = cur_battle->get_int(3);
        int monster_attack = cur_battle->get_int(4);
        int monster_counterattack = cur_battle->get_int(5);
        //-----user turn
        if (weaponToUSe > 0){ 
            cur_battle = db.get_statement();//create query
            //query to load the variables of the weapon that the user chose
            cur_battle->set_sql("SELECT w.type, w.damage, w.attack, wu.duration FROM weapon w, weapons_user wu  WHERE (wu.idUser=? AND w.idWeapon =? AND wu.duration > 0 )");
            //0-weapon type(text) . 1-weapon damage(int) . 2- weapon attack(int) . 3-weapon-user duration(int) 
            cur_battle->prepare();
            cur_battle->bind(1,1);      //ANDD HEREEE AS WELLLL THE idUSer
            cur_battle->bind(2,weaponToUSe);
            cur_battle->step();
            attackW = cur_battle->get_int(2);
            damageW = cur_battle->get_int(3);
        }else{
            //when the user choose to punch
            attackW = 10;
            damageW = 1;
        }
        monster_health -= attackW * damageW;//decrease the mosnter health multiplying the attack by damage
        if (monster_counterattack > 0){
            user_armor -= monster_counterattack;
        }
        //--------------
        //------monster turn
        cout<<"Monster's turn"<<endl;
        int totalMonsterDamage = monster_attack * user_level;
        if (user_armor > 0){
            user_armor -= 0.75*totalMonsterDamage;
            user_health -= 0.25*totalMonsterDamage;
        }else{
            user_health -= totalMonsterDamage;
        }
        if(monster_health <= 0){
            cout<<"YOU WON"<<endl;
            stopGame = true;
        }
        if(user_health <= 0){
            cout<<"YOU LOSS"<<endl;
            stopGame = true;
        }
    }

    return 0;
}