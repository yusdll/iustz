#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

enum AttackTechniques{
    Attack = 0,
    ReturnAttack = 1,
    Defense = 2,
    Run = 3,
    ComeBack = 4
}Techniques;

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

    // Function for decreasing energy of character
    void decreaseEnergy(int amount) {
        energy -= amount;
        if (energy < 0) {
            energy = 0;
        }
    }

    // Function for leveling up character
    void increaseLevel() {
        if (level < 20) {
            level++;
        }
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
    int PlayerattackPower;
public:
    // Constructor
    PlayerCharacter(std::string _name, int _age, std::string _gender, std::string _selectedWeapon)
        : Character(_name, _age, _gender), selectedWeapon(_selectedWeapon) { PlayerattackPower=rand() % 11 + 55; }

    // Getters and setters for this class
    void setSelectedWeapon(std::string _selectedWeapon) { selectedWeapon = _selectedWeapon; }
    void setPlayerattackPower(int _PlayerattackPower) { PlayerattackPower = _PlayerattackPower;}
    std::string getSelectedWeapon() const { return selectedWeapon; }
    int getPlayerattackPower() const {return PlayerattackPower;}

    // Function to switch the weapons during gameplay
    void PermanentItem(std::string newWeapon) {
        selectedWeapon = newWeapon;
        if (newWeapon == "Shotgun") {
            enemy.takeDamage(35);
        } 
        if (newWeapon == "Machine Gun") {
            enemy.takeDamage(50);
        } 
        if (newWeapon == "Is50") {
            enemy.takeDamage(30);
        }
        else if (newWeapon == "M16") {
            enemy.takeDamage(30);
        } 
        
    }

    
    void ConsumableItem(std::string foodName) {
        if (foodName == "Cheeseburger") {
            setHealth(getHealth() + 30);
        }
        if (foodName == "Dizi") {
           setHealth(getHealth() + 35);
        }
        if (foodName == "Pasta") {
            setHealth(getHealth() + 30);
        }
        if (foodName == "Redbull") {
           setEnergy(getEnergy() + 30);
        }
        if (foodName == "Mangosmoothie") {
            setEnergy(getEnergy() + 15);
        }
        else if (foodName == "Late") {
           setEnergy(getEnergy() + 25);
        }
    }

    void ThrowableItem(std::string itemName) {  
        if (itemName == "Bomb") {
            enemy.takeDamage(35);
        }
        if (itemName == "Grenade") {
            enemy.takeDamage(20);
        }
        if (itemName == "Chemicalgas") {
            enemy.takeDamage(40);
        }
        else if (itemName == "Fireball") {
            enemy.takeDamage(25);
        } 
    }

    // Including selected weapon
    void displayInfo() const {
        Character::displayInfo();
        std::cout << "Selected Weapon: " << selectedWeapon << std::endl;
    }

    // Function for decreasing the health while fighting and stuff
    void takeDamage(int damage) {
        health -= damage;
        if (health<100)
        {
            if (health <= 0) {
                std::cout<<"You lose! You have to play again from the beginning. "<<std::endl;
                level=1;}
        }
    }

    // Function for leveling up character
    void increaseLevel() {
        if (level < 20) {
            level++;
        }
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
    
    int getHealth() const { return health; }

    void takedamage(PlayerCharacter& player){
        health -= player.getPlayerattackPower();
                if (health<100){
                    std::cout<<"You attacked the zombie enemy for "<<player.getPlayerattackPower()<<" damage ! The health of the zombie enemy is : "<<health<<" "<<std::endl;
                    if (health <= 0) { health = 0;
                        std::cout<<"you won! The zombie enemy character was killed. "<<std::endl; }
                }
    }

    // Function for attack a player
    void attackPlayer(PlayerCharacter& player) {
        // Reduce player's health by the attack power of the zombie
        std::cout<<std::endl<<"Information about the Zombie Enemy : "<<std::endl;
        std::cout << "Name: Zombie Enemy"<< std::endl;
        std::cout << "Health: " << health << std::endl; 
        player.takeDamage(attackPower);
        std::cout << "Zombie attacked Player for " << attackPower << " damage." << std::endl;
        takedamage(player);

        if (health <= 0) {
            std::cout << "you won! The zombie enemy character was killed." << std::endl;
            player.increaseLevel(); // leveling up the character
        }
    }
};

class StrongerZombieCharacter : public ZombieCharacter {
public:
    // Constructor
    StrongerZombieCharacter() {
        // setting attack power to a random number between 35 and 45
        attackPower = rand() % 11 + 35;
    }

    void takedamage(PlayerCharacter& player){
        health -= player.getPlayerattackPower();
                if (health<100){
                    std::cout<<"You attacked the stronger zombie enemy for "<<player.getPlayerattackPower()<<" damage ! The health of the stronger zombie enemy is : "<<health<<" "<<std::endl;
                    if (health <= 0) { health = 0;
                        std::cout<<"you won! The stronger zombie enemy character was killed. "<<std::endl; }
                }
    }

    // Function for attack a player
    void attackPlayer(PlayerCharacter& player) {
        // Reduce player's health by the attack power of the stronger zombie 
        std::cout<<std::endl<<"Information about the Stronger Zombie Enemy : "<<std::endl;
        std::cout << "Name: Stronger Zombie Enemy"<< std::endl;
        std::cout << "Health: " << health << std::endl; 
        player.takeDamage(attackPower);
        std::cout << "Stronger Zombie attacked Player for " << attackPower << " damage." << std::endl;
        takedamage(player);

        if (health <= 0) {
            std::cout << "you won! The stronger zombie enemy character was killed." << std::endl;
            player.increaseLevel();
        }
    }
};


class HumanEnemy : public Character { 
    protected:
        int attackPower; 
    public: 
        HumanEnemy(): Character("HumanEnemy",rand() % 10 + 20, rand() % 2 == 0 ? "Male" : "Female" ){
            warmWeaponSkill = rand() % 41 + 30;
            coldWeaponSkill = rand() % 41 + 30;
            attackPower=rand() % 11 + 45; 
        }

        void TakeDamage(PlayerCharacter& player){
            if (Techniques == Attack || Techniques == ComeBack)
            {
                health -= player.getPlayerattackPower();
                if (health<100){
                    std::cout<<"You attacked the human enemy for "<<player.getPlayerattackPower()<<" damage ! The health of the human enemy is : "<<health<<" "<<std::endl;
                    if (health <= 0) { health = 0;
                        std::cout<<"you won! The human enemy character was killed. "<<std::endl; }
                }
            }else if (Techniques == ReturnAttack) {
                player.setHealth(player.getHealth() - player.getPlayerattackPower());
                std::cout<<"oops! Human Enemy return the attack to the player with a strength of "<<player.getPlayerattackPower()<<". "<<std::endl;
            }else if (Techniques == Defense ) {
                health = health;
                std::cout<<"oops! The human enemy defended the player's attack. "<<std::endl;
            }   
        }
        void attackPlayerCharacter(PlayerCharacter& player , StrongerZombieCharacter& StrongerZombie, ZombieCharacter& zombie) {
            int determinative;
            std::cout<<std::endl<<"Information about the human enemy : "<<std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Age: " << age << std::endl;
            std::cout << "Gender: " << gender << std::endl;
            std::cout << "Health: " << health << std::endl;
            auto startTime = std::chrono::high_resolution_clock::now();
            std::this_thread::sleep_for(std::chrono::minutes(1/6));
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime);
            if (duration.count() >= 1/6) {
                determinative = 1;
            }
            if (determinative == 1)
            {
                if (player.getLevel()>=8 && player.getLevel()<=9) { 
                    Techniques=Attack;  
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                }else if (player.getLevel()>=10){
                    Techniques=Defense;
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                    Techniques=Attack;
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                }else if (player.getLevel()>=12) {
                    Techniques=Defense;
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                    Techniques=ReturnAttack;
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                    Techniques=Attack;
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                }else if (player.getLevel()>=14) {
                    Techniques=Attack;
                    TakeDamage(player);
                    player.takeDamage(attackPower);
                    std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                    TakeDamage(player);
                    Techniques=Run;
                    std::cout<<"The human enemy fled to recuperate! But the zombies are coming. "<<std::endl;
                    int RandomSelection= rand() % 2;
                    if ( RandomSelection == 0 ) { StrongerZombie.attackPlayer(player);  
                    }else if ( RandomSelection == 1 ) { zombie.attackPlayer(player); }
                    if (StrongerZombie.getHealth() == 0 || zombie.getHealth() == 0)
                    {
                        Techniques=ComeBack;
                        health = 100 ;
                        std::cout<<"Human enemy returned with 100 health. "<<std::endl;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        Techniques=Attack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                    }
                }else if (player.getLevel()>=16) {
                    int Randomselection= rand() % 2 + 1;
                    if ( Randomselection == 1 )
                    {
                        Techniques=Attack;
                        TakeDamage(player);
                        Techniques=Defense;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        Techniques=ReturnAttack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=ReturnAttack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        TakeDamage(player);
                    }else if ( Randomselection == 2 ) {
                        Techniques=Attack;
                        TakeDamage(player);
                        Techniques=Defense;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=ReturnAttack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Defense;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                    }else if (player.getLevel()>=18) {
                        Techniques=Attack;
                        TakeDamage(player);
                        Techniques=ReturnAttack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Defense;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=ReturnAttack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        TakeDamage(player);
                        Techniques=Run;
                        std::cout<<"The human enemy fled to recuperate! But the zombies are coming. "<<std::endl;
                        StrongerZombie.attackPlayer(player); 
                        zombie.attackPlayer(player);
                        if (StrongerZombie.getHealth() == 0 && zombie.getHealth() == 0){
                        Techniques=ComeBack;
                        health = 100 ;
                        std::cout<<"Human enemy returned with 100 health. "<<std::endl;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        Techniques=Defense;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        TakeDamage(player);
                        Techniques=ReturnAttack;
                        player.takeDamage(attackPower);
                        std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;
                        TakeDamage(player);
                        Techniques=Attack;
                        TakeDamage(player);
                        TakeDamage(player);}
                    }      
                }     
            }
        }

        if (health <= 0) {
            std::cout << "you won! The human enemy character was killed." << std::endl;
            player.increaseLevel();
        }
};

class RandomAttack {
public:
    // Function to perform random attack
    static void performRandomAttack(PlayerCharacter& player, ZombieCharacter& zombie, StrongerZombieCharacter& strongerZombie,HumanEnemy& enemy) {
        int randomEnemy = rand() % 3; // Randomly select an enemy to attack

        if (randomEnemy == 0 && player.getLevel()<12 ) {
            // Attack the player with a zombie
            zombie.attackPlayer(player);
        }else if( randomEnemy == 1 && player.getLevel()<12 ) {
            // Attack the player with a stronger zombie
            strongerZombie.attackPlayer(player);
        }else if( randomEnemy == 2 &&  player.getLevel()>=8 && player.getLevel()<12) {
            // Attack the player with a Human Enemy
            enemy.attackPlayerCharacter(player,strongerZombie,zombie);
        }else if ( player.getLevel()>=12 )
        {
            // Attack the player with a Human Enemy
            enemy.attackPlayerCharacter(player,strongerZombie,zombie);
        }
        

        // Display player's health after the attack
        std::cout << "Player Health: " << player.getHealth() << std::endl;
    }
};

class CharacterCreation {
public:
    // Function to create a new character
    static void createCharacter(std::string& name, int& age, std::string& gender, std::string& selectedWeapon) {
        // Get character's name
        std::cout << "Enter character's name: \n";
        std::cin >> name;

        // Get character's age
        std::cout << "Enter character's age: \n";
        std::cin >> age;

        // Get character's gender
        std::cout << "Enter character's gender: \n";
        std::cin >> gender;

        // Get character's selected weapon
        std::cout << "Enter character's selected weapon (Sword/Dagger/Shotgun/Flamethrower): \n";
        std::cin >> selectedWeapon;
    }
};

int main() {
    // for generating random numbers for game
    srand(time(nullptr));

    std::string name, gender, selectedWeapon;
    int age;

    // Create a character
    CharacterCreation::createCharacter(name, age, gender, selectedWeapon);

    // our unique character information
    std::cout << "Created Character Information: " << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Selected Weapon: " << selectedWeapon << std::endl;


    // Create a player character based on the entered information
    PlayerCharacter player(name, age, gender, selectedWeapon);

    
    std::cout << "\nPlayer Character Information After Leveling Up and Ability Upgrade: " << std::endl;
    player.displayInfo();

    std::chrono::minutes time_interval(1);
    while (true) {
        player.decreaseEnergy(15);
        std::this_thread::sleep_for(time_interval);
    }

    std::cout << "\nPlayer Character Information After Decreasing Energy: " << std::endl;
    player.displayInfo();

    // Creating a zombie
    ZombieCharacter zombie;

    // Creating a stronger zombie
    StrongerZombieCharacter strongerZombie;

    // Creating a human enemy
    HumanEnemy enemy;

    // Perform a random attack
    RandomAttack::performRandomAttack(player, zombie, strongerZombie,enemy);

    return 0;
}
