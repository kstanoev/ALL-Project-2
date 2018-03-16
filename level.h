#ifndef LEVEL_H
#define LEVEL_H
using namespace std;

#include "player.h"
#include "entity.h"
#include "chest.h"
#include "enemy.h"
#include "puzzle.h"

static bool isRandomInitialised = false;

class Level {

private:
    
    vector< vector<char> > map;
    Player* player;
    /* Map characters:
       (space) - open ground
       # - wall
       P - player
       1 - chest
       2 - enemy
       3 - puzzle
       */
    vector<Chest> chests;
    vector<Enemy> enemies;
    vector<Puzzle> puzzles;

    void movePlayerTo(int, int); //Move the player to any location
    
public:
    
    Level(Player*, int, int); //Constructor
    vector< vector<char> > getMap(); //Return the map
    vector< vector<char> > getMapWithEntities(); //Returns the map with all entities
    void generateMap(); //Creates the map
    vector< vector<int> > getDistanceMap(int, int, int); //Gets the map but shows the distances from a single space
    bool hasLOS(int, int, int, int); //Checks if two positions have line of sight between each other this is essential to making sure the rooms dont overlap otherwise it fucks up and thres loads of retarded maps that trap you in the spawn
    bool playerMove(char); //Moves the player in a specified direction
    bool isEntity(int, int); //Checks if there is an entity at the specified location
    Entity* getEntityAtPosition(int, int); //Gets a pointer to the entity at a given location
    void cleanUp(); //Removes all dead shit and items from the map when picked up etc
    bool isChest(int, int);
    bool openChest(char);
    bool isEnemy(int, int);
    bool startBattle(char);
    bool isPuzzle(int, int);
    bool startPuzzle(char);
    void printMap(vector< vector<int> >);
    int randomNumber(int, int);
    bool isFieldOverlapping(vector<int>, vector<int>);
    float randomProbability();
};
#endif
