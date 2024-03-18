#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Character {
protected:
    std::string name;
    int age;
    std::string gender;
    int health = 100; // Default health 100
    int energy = 100; // Default energy 100
    int level = 1; // Default level 1
    int warmWeaponSkill;
    int coldWeaponSkill;
    int initialExperience = 15; // starting with experience set to 15

public:
    // Constructor
    Character(std::string _name, int _age, std::string _gender)
        : name(_name), age(_age), gender(_gender) {
        // Set warm and cold weapon skills to a random number between 40 and 100
        warmWeaponSkill = rand() % 61 + 40;
        coldWeaponSkill = rand() % 61 + 40;
    }

    // Setters
    void setName(std::string _name) { name = _name; }
    void setAge(int _age) { age = _age; }
    void setGender(std::string _gender) { gender = _gender; }
    void setHealth(int _health) { health = _health; }
    void setEnergy(int _energy) { energy = _energy; }
    void setLevel(int _level) { level = _level; }
    void setWarmWeaponSkill(int _warmWeaponSkill) { warmWeaponSkill = _warmWeaponSkill; }
    void setColdWeaponSkill(int _coldWeaponSkill) { coldWeaponSkill = _coldWeaponSkill; }


    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    int getHealth() const { return health; }
    int getEnergy() const { return energy; }
    int getLevel() const { return level; }
    int getWarmWeaponSkill() const { return warmWeaponSkill; }
    int getColdWeaponSkill() const { return coldWeaponSkill; }


    // Function for decreasing the health while fighting and stuff
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0;
        }
    }


    // Function for decreasing energy of character
    void decreaseEnergy(int amount) {
        energy -= amount;
        if (energy < 0) {
            energy = 0;
        }
    }

    // Function for leveling up character
    void levelUp(int experience) {
        const int experiencePerLevel = 10000;
        int levelsToIncrease = experience / experiencePerLevel; // Calculate that how many levels we need to increase

        float warmIncrease = 0.0, coldIncrease = 0.0; // Define warmIncrease and coldIncrease outside the loop

        for (int i = 0; i < levelsToIncrease; ++i) {
            if (level < 100) { // increase level only if it's less than 100
                level += 1;

                // Increase warm and cold weapon skills by 15% of their current values
                warmWeaponSkill += warmWeaponSkill * 0.15;
                coldWeaponSkill += coldWeaponSkill * 0.15;

                // Make sure warmWeaponSkill and coldWeaponSkill don't exceed 100
                warmWeaponSkill = (warmWeaponSkill > 100) ? 100 : warmWeaponSkill;
                coldWeaponSkill = (coldWeaponSkill > 100) ? 100 : coldWeaponSkill;
            }
        }

        // Ensuring that level doesn't exceed 100
        if (level > 100) {
            level = 100;
        }
    }

    // Function for increasing initial experience
    void increaseInitialExperience(int amount) {
        initialExperience += amount;
    }

    // Function for getting initial experience
    int getInitialExperience() const {
        return initialExperience;
    }

    // Function to display character information
    void displayInfo() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Gender: " << gender << std::endl;
        std::cout << "Health: " << health << std::endl;
        std::cout << "Energy: " << energy << std::endl;
        std::cout << "Level: " << level << std::endl;
        std::cout << "Warm Weapon Skill: " << warmWeaponSkill << std::endl;
        std::cout << "Cold Weapon Skill: " << coldWeaponSkill << std::endl;
    }
};

class PlayerCharacter : public Character {
protected:
    std::string selectedWeapon; // the weapon that character selected for the player character

public:
    // Constructor
    PlayerCharacter(std::string _name, int _age, std::string _gender, std::string _selectedWeapon)
        : Character(_name, _age, _gender), selectedWeapon(_selectedWeapon) {}

    // Getters and setters for this class
    void setSelectedWeapon(std::string _selectedWeapon) { selectedWeapon = _selectedWeapon; }
    std::string getSelectedWeapon() const { return selectedWeapon; }

    // Function to switch the weapons during gameplay
    void switchWeapon(std::string newWeapon) {
        selectedWeapon = newWeapon;
    }

    // Including selected weapon
    void displayInfo() const {
        Character::displayInfo();
        std::cout << "Selected Weapon: " << selectedWeapon << std::endl;
    }

    // Function for leveling up character by experience
    void levelUpByExperience(int experience) {
    }
};

class ZombieCharacter {
protected:
    int health = 100;
    int attackPower;

public:
    // Constructor
    ZombieCharacter() {
        // Setting the attack power to a random number between 10 and 20
        attackPower = rand() % 11 + 10;
    }

    // Function for attack a player
    void attackPlayer(PlayerCharacter& player) {
        // Reduce player's health by the attack power of the zombie 
        player.takeDamage(attackPower);
        std::cout << "Zombie attacked Player for " << attackPower << " damage." << std::endl;
    }
};

class StrongerZombieCharacter : public ZombieCharacter {
public:
    // Constructor
    StrongerZombieCharacter() {
        // setting attack power to a random number between 35 and 45
        attackPower = rand() % 11 + 35;
    }

    // Function for attack a player
    void attackPlayer(PlayerCharacter& player) {
        // Reduce player's health by the attack power of the stronger zombie 
        player.takeDamage(attackPower);
        std::cout << "Stronger Zombie attacked Player for " << attackPower << " damage." << std::endl;
    }
};

class RandomAttack {
public:
    // Function to perform random attack
    static void performRandomAttack(PlayerCharacter& player, ZombieCharacter& zombie, StrongerZombieCharacter& strongerZombie) {
        int randomEnemy = rand() % 2; // Randomly select an enemy to attack

        if (randomEnemy == 0) {
            // Attack the player with a zombie
            zombie.attackPlayer(player);
        } else {
            // Attack the player with a stronger zombie
            strongerZombie.attackPlayer(player);
        }

        // Display player's health after the attack
        std::cout << "Player Health: " << player.getHealth() << std::endl;
    }
};

int main() {
    // for generating random numbers for game
    srand(time(nullptr));

    std::string name, gender, selectedWeapon;
    int age;

    // our unique character information
    std::cout << "Enter character's name: \n";
    std::cin >> name;

    std::cout << "Enter character's age: \n";
    std::cin >> age;

    std::cout << "Enter character's gender: \n";
    std::cin >> gender;

    // Available weapons
    std::cout << "Enter character's selected weapon (Sword/Dagger/Shotgun/Flamethrower): \n";
    std::cin >> selectedWeapon;

    PlayerCharacter player(name, age, gender, selectedWeapon);

    std::cout << "Player Character Information: " << std::endl;
    player.displayInfo();

    int experience;
    std::cin >> experience;

    // Level up the player character based on experience
    player.levelUp(experience);

    std::cout << "\nPlayer Character Information After Leveling Up and Ability Upgrade: " << std::endl;
    player.displayInfo();

    // Example of reducing the characters energy
    player.decreaseEnergy(20); // Reduces energy by 20
    std::cout << "\nPlayer Character Information After Decreasing Energy: " << std::endl;
    player.displayInfo();

    // Creating a zombie
    ZombieCharacter zombie;

    // Creating a stronger zombie
    StrongerZombieCharacter strongerZombie;

    // Perform a random attack
    RandomAttack::performRandomAttack(player, zombie, strongerZombie);

    return 0;
}

