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

    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getGender() const { return gender; }
    int getHealth() const { return health; }
    int getEnergy() const { return energy; }
    int getLevel() const { return level; }
    int getWarmWeaponSkill() const { return warmWeaponSkill; }
    int getColdWeaponSkill() const { return coldWeaponSkill; }

    // Setters
    void setName(std::string _name) { name = _name; }
    void setAge(int _age) { age = _age; }
    void setGender(std::string _gender) { gender = _gender; }
    void setHealth(int _health) { health = _health; }
    void setEnergy(int _energy) { energy = _energy; }
    void setLevel(int _level) { level = _level; }
    void setWarmWeaponSkill(int _warmWeaponSkill) { warmWeaponSkill = _warmWeaponSkill; }
    void setColdWeaponSkill(int _coldWeaponSkill) { coldWeaponSkill = _coldWeaponSkill; }

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

        for (int i = 0; i < levelsToIncrease; ++i) {
            if (level < 100) // increase level only if it's less than 100
                level += 1;
            experience -= experiencePerLevel;
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
private:
    std::string selectedWeapon; // the weapon that character selected for the player character

public:
    // Constructor
    PlayerCharacter(std::string _name, int _age, std::string _gender,
        std::string _selectedWeapon)
        : Character(_name, _age, _gender),
        selectedWeapon(_selectedWeapon) {}

    // Getters and setters for this class
    std::string getSelectedWeapon() const { return selectedWeapon; }
    void setSelectedWeapon(std::string _selectedWeapon) { selectedWeapon = _selectedWeapon; }

    // Function for upgrading the character's ability
    void upgradeAbility(std::string ability) {
        if (ability == "warmWeaponSkill") {
            warmWeaponSkill += 20;
        }
        else if (ability == "coldWeaponSkill") {
            coldWeaponSkill += 20;
        }
        else {
            std::cout << "Invalid ability!" << std::endl;
        }
    }

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
        const int experiencePerLevel = 10000;
        int levelsToIncrease = experience / experiencePerLevel; // Calculate how many levels wee need to increase

        for (int i = 0; i < levelsToIncrease; ++i) {
            if (level < 100)
                level += 1;
            experience -= experiencePerLevel;
        }

        // Ensure level doesn't exceed 100
        if (level > 100) {
            level = 100;
        }
    }
};

int main() {
    // for generating random numbers for game
    srand(time(nullptr));

    std::string name, gender, selectedWeapon;
    int age;

    // our unique character information
    std::cout << "Enter character's name: ";
    std::cin >> name;

    std::cout << "Enter character's age: ";
    std::cin >> age;

    std::cout << "Enter character's gender: ";
    std::cin >> gender;

    // Available weapons
    std::cout << "Enter character's selected weapon (Sword/Dagger/Shotgun/Flamethrower): ";
    std::cin >> selectedWeapon;

    PlayerCharacter player(name, age, gender, selectedWeapon);

    std::cout << "Player Character Information:" << std::endl;
    player.displayInfo();

    int experience;
    std::cin >> experience;

    // Level up the player character based on experience
    player.levelUpByExperience(experience);

    player.upgradeAbility("warmWeaponSkill");
    player.upgradeAbility("coldWeaponSkill");

    std::cout << "\nPlayer Character Information After Leveling Up and Ability Upgrade:" << std::endl;
    player.displayInfo();

    // Example of reducing the characters energy
    player.decreaseEnergy(20); // Reduces energy by 20
    std::cout << "\nPlayer Character Information After Decreasing Energy:" << std::endl;
    player.displayInfo();

    return 0;
}

