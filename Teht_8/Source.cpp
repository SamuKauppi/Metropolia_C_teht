#include <iostream>
#include <string>
#include <vector>
#include "classes.h"

using namespace std;

int main()
{
    // Define terrain
    Terrain road = Terrain("road", 1, 1);
    Terrain forest = Terrain("forest", .85, 1.15);
    Terrain mountain = Terrain("mountain", .65, .85);

    // Define tiles
    MapTile roadTile = MapTile(road);
    MapTile forestTile = MapTile(forest);
    MapTile mountainTile = MapTile(mountain);

    // Define game map layout
    vector<vector<MapTile*>> tileLayout;

    // Loop to create rows
    for (int i = 0; i < 3; i++)
    {
        vector<MapTile*> row;

        // Loop to create tiles in each row
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
            {
                row.push_back(new MapTile(road));
            }
            else if (i == 1)
            {
                if (j < 2)
                    row.push_back(new MapTile(mountainTile));
                else if (j == 2)
                    row.push_back(new MapTile(roadTile));
                else
                    row.push_back(new MapTile(forestTile));
            }
            else
            {
                if (j == 0)
                    row.push_back(new MapTile(mountainTile));
                else if (j == 1 || j == 3)
                    row.push_back(new MapTile(forestTile));
                else
                    row.push_back(new MapTile(roadTile));
            }
        }

        // Add the row to the tile layout
        tileLayout.push_back(row);
    }

    // Create player and add them to map
    Character player = Character("Hilfred", 1, 70, 70, 0);
    tileLayout[0][0]->addPlayer(&player);

    // Define enemies
    EnemyType orcType = EnemyType("orc", 30, 10, 5);
    EnemyType ogreType = EnemyType("ogre", 100, 50, 10);

    // Create enemis
    Enemy orc1 = Enemy(orcType);
    Enemy orc2 = Enemy(orcType);
    Enemy ogre = Enemy(ogreType);

    // Add enemies to map
    tileLayout[0][3]->addEnemy(&orc1);
    tileLayout[1][3]->addEnemy(&orc2);
    tileLayout[2][2]->addEnemy(&ogre);

    // Add sword to player
    BattleEquipment sword = BattleEquipment("sword", 20, 10);
    player.addObject(&sword);

    // Create objects
    OtherObject ring = OtherObject("ring", 0, 100);
    OtherObject herb = OtherObject("ring", 100, 0);
    OtherObject armour = OtherObject("ring", 100, 0);

    tileLayout[0][1]->addObject(&ring);
    tileLayout[1][1]->addObject(&herb);
    tileLayout[0][2]->addObject(&armour);
}
