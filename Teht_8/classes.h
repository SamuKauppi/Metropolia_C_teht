#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/// <summary>
/// Object class
/// </summary>
class GameObject {
private:
    string _name;

public:
    // Constructor
    GameObject(const string& name) : _name(name) {}
};

/// <summary>
/// BattleEquipment class representing equipment for battles.
/// </summary>
class BattleEquipment : public GameObject {
private:
    int _attackPower;
    int _defensePower;

public:
    // Constructor
    BattleEquipment(const string& name, int attackPower, int defensePower)
        : GameObject(name), _attackPower(attackPower), _defensePower(defensePower) {}

};

/// <summary>
/// OtherObject class representing other types of game objects.
/// </summary>
class OtherObject : public GameObject {
private:
    int _healthEffect;
    int _moneyEffect;

public:
    // Constructor
    OtherObject(const string& name, int healthEffect, int moneyEffect)
        : GameObject(name), _healthEffect(healthEffect), _moneyEffect(moneyEffect) {}
};

/// <summary>
/// EnemyType class specifying the type of enemy.
/// </summary>
class EnemyType {
protected:
    string _type;
    int _startHp;
    int _startPower;
    int _startDefence;

public:
    // Constructor
    EnemyType(const string& type, int startHp, int startPower, int startDefence)
        : _type(type), _startHp(startHp), _startPower(startPower), _startDefence(startDefence) {}
};

/// <summary>
/// Enemy class
/// </summary>
class Enemy : public EnemyType {
private:
    int _hp;
    int _power;
    int _defence;

public:
    // Constructor that takes an EnemyType parameter
    Enemy(const EnemyType& enemyType)
        : EnemyType(enemyType), _hp(_startHp), _power(_startPower), _defence(_startDefence) {}
};

/// <summary>
/// Character class representing the player-controlled character.
/// </summary>
class Character : public GameObject {
private:
    int _level;
    int _hitPoints;
    int _maxHitPoints;
    int _money;
    vector<GameObject*> _objects;

public:
    // Constructor
    Character(const string& name, int level, int hitPoints, int maxHitPoints, int money)
        : GameObject(name), _level(level), _hitPoints(hitPoints), _maxHitPoints(maxHitPoints), _money(money) {}

    // Add object to player
    void addObject(GameObject* object) {
        _objects.push_back(object);
    }
};

/// <summary>
/// Terrain class representing the variables of the game terrain.
/// </summary>
class Terrain {
private:
    string _type;
    int _movementDifficulty;
    int _combatDifficulty;

public:
    // Constructor
    Terrain(const string& type, int moveDiff, int combatDiff)
        : _type(type), _movementDifficulty(moveDiff), _combatDifficulty(combatDiff) {}

};

/// <summary>
/// MapTile class containing everything in a map tile and the tile's type.
/// </summary>
class MapTile {
private:
    Terrain _terrain;
    Character* _character;
    vector<Enemy*> _enemies;
    vector<GameObject*> _objects;

public:
    // Constructor
    MapTile(const Terrain& terrain) : _terrain(terrain), _character(nullptr) {}

    // Function to add a player to the tile
    void addPlayer(Character* player) {
        _character = player;
    }

    // Function to remove the player from the tile
    void removePlayer() {
        _character = nullptr;
    }

    // Function to add an enemy to the tile
    void addEnemy(Enemy* enemy) {
        _enemies.push_back(enemy);
    }

    // Function to remove an enemy from the tile
    void removeEnemy(Enemy* enemy) {
        // Assuming you want to remove a specific enemy instance
        auto it = find(_enemies.begin(), _enemies.end(), enemy);
        if (it != _enemies.end()) {
            _enemies.erase(it);
            delete enemy;
        }
    }

    // Function to add an object to the tile
    void addObject(GameObject* object) {
        _objects.push_back(object);
    }

    // Function to remove an object from the tile
    void removeObject(GameObject* object) {
        auto it = find(_objects.begin(), _objects.end(), object);
        if (it != _objects.end()) {
            _objects.erase(it);
            delete object;
        }
    }
};

/// <summary>
/// GameMap class representing the map on which the game is played.
/// </summary>
class GameMap {
private:
    vector<vector<MapTile>> _tiles;

public:
    // Constructor
    GameMap(const vector<vector<MapTile>>& tiles) : _tiles(tiles) {}
};
