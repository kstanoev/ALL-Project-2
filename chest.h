#ifndef CHEST_H
#define CHEST_H
#include <vector>
class Chest {
    public:
    
    int xPos;
    int yPos;
    int Health;
    int maxHealth;
    bool isOpen;
    
    private:
    
    int box(int,int,int,int);
	int puzzle(int,int,int,int);
};
#endif