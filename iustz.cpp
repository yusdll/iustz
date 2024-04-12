#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>

enum AttackTechniques {
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
    int PlayerattackPower,coin=0;
    std::string SelectedItem;
    bool IsConsumableItemRequested = false, IsThrowableItemRequested = false, IsPermanentItemRequested = false, ISAttackPowerRequested = false;
    bool sniperEntered = false, TankEntered = false, DefenceIsAactive = false;
public:
    // Constructor
    PlayerCharacter(std::string _name, int _age, std::string _gender)
        : Character(_name, _age, _gender) {
        PlayerattackPower = rand() % 11 + 55;
    }

    // Getters and setters for this class
    void setSelectedWeapon(std::string _selectedWeapon) { selectedWeapon = _selectedWeapon; }
    void setPlayerattackPower(int _PlayerattackPower) { PlayerattackPower = _PlayerattackPower; }
    void setSelectedItem(std::string _SelectedItem) { SelectedItem = _SelectedItem; }
    void setcoin(int _coin){coin = _coin; }
    void setIsConsumableItemRequested(bool _IsConsumableItemRequested){ IsConsumableItemRequested = _IsConsumableItemRequested; }
    void setIsThrowableItemRequested(bool _IsThrowableItemRequested){ IsThrowableItemRequested = _IsThrowableItemRequested; }
    void setIsPermanentItemRequested(bool _IsPermanentItemRequested){ IsPermanentItemRequested  = _IsPermanentItemRequested; }
    void setsniperEntered(bool _sniperEntered){ sniperEntered = _sniperEntered; }
    void setTankEntered(bool _TankEntered){ TankEntered = _TankEntered; }
    void setDefenceIsAactive(bool _DefenceIsAactive){ DefenceIsAactive = _DefenceIsAactive; }
    void setISAttackPowerRequested(bool _ISAttackPowerRequested){ ISAttackPowerRequested = _ISAttackPowerRequested; }
    std::string getSelectedWeapon() const { return selectedWeapon; }
    int getPlayerattackPower() const { return PlayerattackPower; }
    std::string getSelectedItem() { return SelectedItem; }
    int getcoin(){return coin; }
    bool getIsConsumableItemRequested(){return IsConsumableItemRequested;}
    bool getIsThrowableItemRequested(){return IsThrowableItemRequested;}
    bool getIsPermanentItemRequested(){return IsPermanentItemRequested;}
    bool getsniperEntered(){return sniperEntered;}
    bool getTankEntered(){return TankEntered;}
    bool getDefenceIsAactive(){return DefenceIsAactive;}
    bool getISAttackPowerRequested(){return ISAttackPowerRequested;}

    // Function to switch the weapons during gameplay
    int PermanentItem(std::string newWeapon) {
        int Damage;
        if (newWeapon == "Shotgun") {
            return Damage = 35;
        }
        else if (newWeapon == "Machine Gun") {
            return Damage = 50;
        }
        else if (newWeapon == "Is50") {
            return Damage = 30;
        }
        else if (newWeapon == "M16") {
            return Damage = 30;
        }
    }

    void ConsumableItem(std::string foodName) {
        if (foodName == "Pizza") {
            std::cout <<"     /\\     "<<std::endl;
            std::cout <<"    /00\\     "<<std::endl;
            std::cout <<"   /0000\\     "<<std::endl;
            std::cout <<"  /pizza \\     "<<std::endl;
            std::cout <<" /________\\     "<<std::endl;
            setHealth(getHealth() + 30);
            if(getHealth()>100){
                setHealth(100);
            }
        }
        else if (foodName == "Dizi") {
            std::cout <<"      /\\     "<<std::endl;
            std::cout <<"     /__\\     "<<std::endl;
            std::cout <<"    |____|     "<<std::endl;
            std::cout <<"   / Dizzi\\     "<<std::endl;
            std::cout <<"   \\______/     "<<std::endl;
            setHealth(getHealth() + 35);
            if(getHealth()>100){
                setHealth(100);
            }
        }
        else if (foodName == "Sambouse") {
            std::cout <<"     /\\    "<<std::endl;
            std::cout <<"    /  \\    "<<std::endl;
            std::cout <<"   /    \\    "<<std::endl;
            std::cout <<"  /      \\    "<<std::endl;
            std::cout <<" /sambouse\\    "<<std::endl;
            std::cout <<"/__________\\    "<<std::endl;
            setHealth(getHealth() + 30);
            if(getHealth()>100){
                setHealth(100);
            }
        }
        else if (foodName == "Redbull") {
            std::cout<<"    _________"<<std::endl;
            std::cout <<" //________/ " << std::endl;
            std::cout <<" ||/_/_/_/_| " << std::endl;
            std::cout <<" ||        |  " << std::endl;
            std::cout <<" || Redbull|" << std::endl;
            std::cout <<" ||________|" << std::endl;
            std::cout <<" ||________|" << std::endl;
            setEnergy(getEnergy() + 30);
            if(getEnergy()>100){
                setEnergy(100);
            }
        }
        else if (foodName == "Mangosmoothie") {
            std::cout <<"      |       " << std::endl;
            std::cout <<"  __________ " << std::endl;
            std::cout <<" \\ Mango   / " << std::endl;
            std::cout <<"  \\       /  " << std::endl;
            std::cout <<"   \\     /   " << std::endl;
            std::cout <<"    \\___/   " << std::endl;
            setEnergy(getEnergy() + 15);
            if(getEnergy()>100){
                setEnergy(100);
            }
        }
        else if (foodName == "Late") {
            std::cout <<"  ________ " << std::endl;
            std::cout <<"  |______| " << std::endl;
            std::cout <<"  |_Late_| " << std::endl;
            std::cout <<"  |______| " << std::endl;
            setEnergy(getEnergy() + 25);
            if(getEnergy()>100){
                setEnergy(100);
            }
        }
    }


    int ThrowableItem(std::string itemName) {
        int Damage;
        if (itemName == "Bomb") {
            return Damage = 35;
        }
        else if (itemName == "Grenade") {
            return Damage = 20;
        }
        else if (itemName == "Chemicalgas") {
            return Damage = 40;
        }
        else if (itemName == "Fireball") {
            return Damage = 25;
        }
    }

    // Including selected weapon
    void displayInfo() const {
        Character::displayInfo();
        std::cout << "Selected Weapon: " << selectedWeapon << std::endl;}

    // Function for decreasing the health while fighting and stuff
    void takeDamage(int damage){
        if(!getDefenceIsAactive()){
            health -= damage;
            if (getHealth() > 0 && getHealth() < 100){
                std::cout << "Player Health: " << getHealth() << std::endl;
            }
            else if (getHealth() >= 100){
                setHealth(100);
                std::cout << "Player Health: " << getHealth() << std::endl;
            }
            else if (getHealth() <= 0) {
                health = 0;
                std::cout << "You lose! You should play this level again." << std::endl;
                std::cout << "Player Health: " << getHealth() << std::endl;
                setLevel(getLevel() - 1);
                if(getLevel()<=1){
                    setLevel(1);
                }
                std::cout << "Player Level: " << level << std::endl;
            }
        }
        else if (getDefenceIsAactive()){
            std::cout << "The protective shield is activated and the enemy's attack is defended." << std::endl;
            setHealth(100);
        }
    }

};

class Shop{
    public :
    void Buy(PlayerCharacter& player){
        int price, SelectionNumber;
        std::cout<<"Store Menu :"<<std::endl;
        std::cout<<"1. Item :"<<std::endl;
        std::cout<<"itemName = Bomb / Damage:35 / price:50 coin"<<std::endl;
        std::cout<<"itemName = Grenade / Damage:20 / price:40 coin"<<std::endl;
        std::cout<<"itemName = Chemicalgas / Damage:40 / price:60 coin"<<std::endl;
        std::cout<<"itemName = Fireball / Damage:25 / price:45 coin"<<std::endl;
        std::cout<<"2. Food & Drink(food to increase health and drink to increase energy)"<<std::endl;
        std::cout<<"foodName = Pizza / Energy:30 / price:30 coin"<<std::endl;
        std::cout<<"foodName = Dizi / Energy:35 / price:35 coin"<<std::endl;
        std::cout<<"foodName = Sambouse / Energy:30 / price:30 coin"<<std::endl;
        std::cout<<"drinkName = Redbull / Energy:30 / price:30 coin"<<std::endl;
        std::cout<<"drinkName = Mangosmoothie / Energy:15 / price:20 coin"<<std::endl;
        std::cout<<"drinkName = Late / Energy:25 / price:25 coin"<<std::endl;
        std::cout<<"3. Sniper / Damage:50 / price:150 coin"<<std::endl;
        std::cout<<"4. Tank / Damage:100 / price:200 coin"<<std::endl;
        std::cout<<"5. Protective Shield / price:150 coin"<<std::endl;
        std::cout<<"6. Leaving The Store"<<std::endl;
        std::cout<<"Enter your choice to buy : ";
        std::cin>>SelectionNumber;
        std::cout<<std::endl;
        switch (SelectionNumber) {
    case 1: {
            // Get character's selected Item
            std::string  SelectedItem;
            std::cout << "Enter character's selected Item (Bomb/Grenade/Chemicalgas/Fireball): \n";
            std::cin >> SelectedItem;
            if (SelectedItem == "Bomb") {
                if(player.getcoin()>=50){
                    std::cout << "_____" << std::endl;
                    std::cout << "\\    \\____________" << std::endl;
                    std::cout << " \\     MK81        \\" << std::endl;
                    std::cout << " /    ____________ /" << std::endl;
                    std::cout << "/____/" << std::endl;
                    player.setcoin(player.getcoin()-50);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.setSelectedItem(SelectedItem);
                    std::cout << "Selected Item: " << player.getSelectedItem() << std::endl;
                    player.setIsThrowableItemRequested(true);
                } else if(player.getcoin()<50){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedItem == "Grenade") {
                if(player.getcoin()>=40){
                    std::cout << "_____" << std::endl;
                    std::cout << "\\    \\____________" << std::endl;
                    std::cout << " \\     Grenade     \\" << std::endl;
                    std::cout << " /    ____________ /" << std::endl;
                    std::cout << "/____/" << std::endl;
                    player.setcoin(player.getcoin()-40);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.setSelectedItem(SelectedItem);
                    std::cout << "Selected Item: " << player.getSelectedItem() << std::endl;
                    player.setIsThrowableItemRequested(true);
                } else if(player.getcoin()<40){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedItem == "Chemicalgas") {
                if(player.getcoin()>=60){
                    std::cout << "_____" << std::endl;
                    std::cout << "\\    \\_____________" << std::endl;
                    std::cout << " \\    ChemicalGas  \\" << std::endl;
                    std::cout << " /    ____________ /" << std::endl;
                    std::cout << "/____/" << std::endl;
                    player.setcoin(player.getcoin()-60);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.setSelectedItem(SelectedItem);
                    std::cout << "Selected Item: " << player.getSelectedItem() << std::endl;
                    player.setIsThrowableItemRequested(true);
                } else if(player.getcoin()<60){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedItem == "Fireball") {
                if(player.getcoin()>=45){
                std::cout << "_____" << std::endl;
                std::cout << "\\    \\_____________" << std::endl;
                std::cout << " \\    Fireball      \\" << std::endl;
                std::cout << " /    ____________ /" << std::endl;
                std::cout << "/____/" << std::endl;
                    player.setcoin(player.getcoin()-45);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.setSelectedItem(SelectedItem);
                    std::cout << "Selected Item: " << player.getSelectedItem() << std::endl;
                    player.setIsThrowableItemRequested(true);
                } else if(player.getcoin()<45){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            }
            break;
        }
        case 2: {
            std::string SelectedFood;
            std::cout << "Enter character's selected Food or Drink (Pizzaa/Dizi/Sambouse/Redbull/Mangosmoothie/Late): \n";
            std::cin>>SelectedFood;
            if (SelectedFood == "Pizza") {
                if(player.getcoin()>=30){
                    player.setcoin(player.getcoin()-30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.ConsumableItem(SelectedFood);
                    std::cout << "Player Health: " << player.getHealth() << std::endl;
                    std::cout << "Player Energy: " << player.getEnergy() << std::endl;
                } else if(player.getcoin()<30){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedFood == "Dizi") {
                if(player.getcoin()>=35){
                    player.setcoin(player.getcoin()-35);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.ConsumableItem(SelectedFood);
                    std::cout << "Player Health: " << player.getHealth() << std::endl;
                    std::cout << "Player Energy: " << player.getEnergy() << std::endl;
                } else if(player.getcoin()<35){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedFood == "Sambouse") {
                if(player.getcoin()>=30){
                    player.setcoin(player.getcoin()-30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.ConsumableItem(SelectedFood);
                    std::cout << "Player Health: " << player.getHealth() << std::endl;
                    std::cout << "Player Energy: " << player.getEnergy() << std::endl;
                } else if(player.getcoin()<30){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedFood == "Redbull") {
                if(player.getcoin()>=30){
                    player.setcoin(player.getcoin()-30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.ConsumableItem(SelectedFood);
                    std::cout << "Player Health: " << player.getHealth() << std::endl;
                    std::cout << "Player Energy: " << player.getEnergy() << std::endl;
                } else if(player.getcoin()<30){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedFood == "Mangosmoothie") {
                if(player.getcoin()>=20){
                    player.setcoin(player.getcoin()-20);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.ConsumableItem(SelectedFood);
                    std::cout << "Player Health: " << player.getHealth() << std::endl;
                    std::cout << "Player Energy: " << player.getEnergy() << std::endl;
                } else if(player.getcoin()<20){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            } else if (SelectedFood == "Late") {
                if(player.getcoin()>=25){
                    player.setcoin(player.getcoin()-25);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                    player.ConsumableItem(SelectedFood);
                    std::cout << "Player Health: " << player.getHealth() << std::endl;
                    std::cout << "Player Energy: " << player.getEnergy() << std::endl;
                } else if(player.getcoin()<25){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            }
            break;
        }
        case 3: {
            if(player.getcoin()>=150){
                player.setcoin(player.getcoin()-150);
                std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                player.setsniperEntered(true);
            } else if(player.getcoin()<150){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            break;
        }
        case 4: {
            if(player.getcoin()>=200){
                player.setcoin(player.getcoin()-200);
                std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                std::cout << "             _________" << std::endl;
                std::cout << "            |   ______" << std::endl;
                std::cout << "            |  |" << std::endl;
                std::cout << "  _________/    \\_________" << std::endl;
                std::cout << " /                        \\" << std::endl;
                std::cout << "/               M1A2 SEPV3 \\" << std::endl;
                std::cout << "\\__________________________/" << std::endl;
                std::cout << " \\________________________/" << std::endl;
                std::cout << " (/_/_/_/_/_/_/_/_/_/_/_/_)" << std::endl;
                player.setTankEntered(true);
            } else if(player.getcoin()<200){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            break;
        }
        case 5: {
            if(player.getcoin()>=150){
                player.setcoin(player.getcoin()-150);
                std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                player.setDefenceIsAactive(true);
            } else if(player.getcoin()<150){
                std::cout<<"You do not have enough coins to buy this option!"<<std::endl;}
            break;
        }
        case 6: {
            std::cout << "Leaving The Store..." << std::endl;
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
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

    void takedamage(PlayerCharacter& player, Shop& shop) {
        if(player.getHealth()>0){
            if(player.getTankEntered()){
                health -= 100;
                std::cout << "Tank entered the game and reduced Enemy Health by 100!"<< std::endl;
                if (health <= 0) {
                    health = 0;
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl;
                    std::cout << "you won! The zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+30);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 30. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setTankEntered(false);
            }
            if(player.getsniperEntered()){
                health -= 50;
                std::cout << "Sniper entered the game and reduced Enemy Health by 50!"<< std::endl;
                if(health>0){
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl; 
                }
                else if (health <= 0 ) {
                    health = 0;
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl;
                    std::cout << "you won! The zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+30);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 30. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setsniperEntered(false);
                }
            if(player.getIsPermanentItemRequested()){ 
                health -= player.PermanentItem(player.getSelectedWeapon());
                if (player.getSelectedWeapon() == "Shotgun") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   Shotgun_____ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                } else if (player.getSelectedWeapon() == "Machine Gun") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   MachinGun_____ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                    std::cout<<"           |\\"<<std::endl;
                } else if (player.getSelectedWeapon() == "Is50") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   IS50_________ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                } else if (player.getSelectedWeapon() == "M16") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   M16 _________ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                }
                std::cout << "You attacked the zombie enemy for " << player.PermanentItem(player.getSelectedWeapon()) << " damage with SelectedWeapon !"<< std::endl;
                if(health>0){
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl; 
                }
                else if (health <= 0 ) {
                    health = 0;
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl;
                    std::cout << "you won! The zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+30);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 30. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setIsPermanentItemRequested(false);
                }
            if(player.getIsThrowableItemRequested()){ 
                health -= player.ThrowableItem(player.getSelectedItem()); 
                std::cout << "You attacked the zombie enemy for " << player.ThrowableItem(player.getSelectedItem()) << " damage with SelectedItem !"<< std::endl;
                if(health>0){
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl; 
                }
                else if (health <= 0 ) {
                    health = 0;
                    std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl;
                    std::cout << "you won! The zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+30);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 30. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+30);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setIsThrowableItemRequested(false);
                }
                if(player.getISAttackPowerRequested()){
            health -= player.getPlayerattackPower();
            std::cout << "You attacked the zombie enemy for " << player.getPlayerattackPower() << " damage !";
            if(health>0){
                std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl; 
            }
            else if (health <= 0 ) {
                health = 0;
                std::cout<< "The health of the zombie enemy is : " << health << " "<< std::endl;
                std::cout << "you won! The zombie enemy character was killed. " << std::endl;
                player.setLevel(player.getLevel()+1);
                std::cout<<"player level : "<<player.getLevel()<<std::endl;
                player.setHealth(player.getHealth()+30);
                if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                std::cout<<"Increase player health by 30. "<<"Player Health: " << player.getHealth() << std::endl;
                player.setcoin(player.getcoin()+30);
                std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                }
        }
    }

    // Function for attack a player
    void attackPlayer(PlayerCharacter& player, Shop& shop) {
        // Reduce player's health by the attack power of the zombie
        std::cout << std::endl << "Information about the Zombie Enemy : " << std::endl;
        std::cout << "Name: Zombie Enemy" << std::endl;
        std::cout << "Health: " << health << std::endl;
        while(health > 0 && player.getHealth()>0){
        std::cout<<"It is the player's turn to attack the enemy. Attack menu :"<<std::endl;
        std::cout<<"1. Attack power"<<std::endl;
        std::cout<<"2. Permanent weapon"<<std::endl;
        std::cout<<"3. Buy items from the shop"<<std::endl;
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                player.setISAttackPowerRequested(true);
                takedamage(player, shop);
                break;
            }
            case 2: {
                std::cout << "Enter character's selected weapon (M16 ,power:30/Is50 ,power:30/Shotgun ,power:35/Machine Gun ,power:50): ";
                std::string selectedWeapon;
                std::cin >> selectedWeapon;
                player.setSelectedWeapon(selectedWeapon);
                player.setIsPermanentItemRequested(true);
                takedamage(player, shop);
                break;
            }
            case 3: {
                shop.Buy(player);
                takedamage(player, shop);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
        if(getHealth()>0){
        std::cout<<"It is the enemy's turn to attack"<<std::endl;
        player.takeDamage(attackPower);
        std::cout << "Zombie attacked Player for " << attackPower << " damage." << std::endl;}
        }
        if(player.getHealth() == 0){
            player.setHealth(100);
        }
        health=100;
    }
};

class StrongerZombieCharacter : public ZombieCharacter {
public:
    // Constructor
    StrongerZombieCharacter() {
        // setting attack power to a random number between 35 and 45
        attackPower = rand() % 11 + 35;
    }

    void takedamage(PlayerCharacter& player, Shop& shop) {
        if(player.getHealth()>0){
            if(player.getTankEntered()){
                health -= 100;
                std::cout << "Tank entered the game and reduced Enemy Health by 100!"<< std::endl;
                if (health <= 0) {
                    health = 0;
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The stronger zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+40);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 40. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+50);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setTankEntered(false);
            }
            if(player.getsniperEntered()){
                health -= 50;
                std::cout << "Sniper entered the game and reduced Enemy Health by 50!"<< std::endl;
                if(health>0){
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0) {
                    health = 0;
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The stronger zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+40);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 40. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+50);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setsniperEntered(false);
            }
            if(player.getIsPermanentItemRequested()){
                health -= player.PermanentItem(player.getSelectedWeapon());
                if (player.getSelectedWeapon() == "Shotgun") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   Shotgun_____ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                } else if (player.getSelectedWeapon() == "Machine Gun") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   MachinGun_____ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                    std::cout<<"           |\\"<<std::endl;
                } else if (player.getSelectedWeapon() == "Is50") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   IS50_________ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                } else if (player.getSelectedWeapon() == "M16") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   M16 _________ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                }
                std::cout << "You attacked the stronger zombie enemy for " << player.PermanentItem(player.getSelectedWeapon())<< " damage with SelectedWeapon !" << std::endl;
                if(health>0){
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0) {
                    health = 0;
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The stronger zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+40);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 40. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+50);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setIsPermanentItemRequested(false);
                } 
            if(player.getIsThrowableItemRequested()){
                health -= player.ThrowableItem(player.getSelectedItem()); 
                std::cout << "You attacked the stronger zombie enemy for "<< player.ThrowableItem(player.getSelectedItem()) << " damage with SelectedItem !" << std::endl;
                if(health>0){
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0) {
                    health = 0;
                    std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The stronger zombie enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+40);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 40. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+50);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setIsThrowableItemRequested(false);
            }
            if(player.getISAttackPowerRequested()){
            health -= player.getPlayerattackPower();
            std::cout << "You attacked the stronger zombie enemy for " << player.getPlayerattackPower() << " damage !";
            if(health>0){
                std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
            }
            else if (health <= 0) {
                health = 0;
                std::cout<<" The health of the stronger zombie enemy is : " << health << " " << std::endl;
                std::cout << "you won! The stronger zombie enemy character was killed. " << std::endl;
                player.setLevel(player.getLevel()+1);
                std::cout<<"player level : "<<player.getLevel()<<std::endl;
                player.setHealth(player.getHealth()+40);
                if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 40. "<<"Player Health: " << player.getHealth() << std::endl;
                player.setcoin(player.getcoin()+50);
                std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
            }
        }
    }


    // Function for attack a player
    void attackPlayer(PlayerCharacter& player, Shop& shop) {
        // Reduce player's health by the attack power of the stronger zombie 
        std::cout << std::endl << "Information about the Stronger Zombie Enemy : " << std::endl;
        std::cout << "Name: Stronger Zombie Enemy" << std::endl;
        std::cout << "Health: " << health << std::endl;
        while(health > 0 && player.getHealth()>0){
        std::cout<<"It is the player's turn to attack the enemy. Attack menu :"<<std::endl;
        std::cout<<"1. Attack power"<<std::endl;
        std::cout<<"2. Permanent weapon"<<std::endl;
        std::cout<<"3. Buy items from the shop"<<std::endl;
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                player.setISAttackPowerRequested(true);
                takedamage(player, shop);
                break;
            }
            case 2: {
                std::cout << "Enter character's selected weapon (M16 ,power:30/Is50 ,power:30/Shotgun ,power:35/Machine Gun ,power:50): ";
                std::string selectedWeapon;
                std::cin >> selectedWeapon;
                player.setSelectedWeapon(selectedWeapon);
                player.setIsPermanentItemRequested(true);
                takedamage(player, shop);
                break;
            }
            case 3: {
                shop.Buy(player);
                takedamage(player, shop);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
        if(getHealth()>0){
        std::cout<<"It is the enemy's turn to attack"<<std::endl;
        player.takeDamage(attackPower);
        std::cout << "Stronger Zombie attacked Player for " << attackPower << " damage." << std::endl;}
        }
        if(player.getHealth() == 0){
            player.setHealth(100);
        }
        health=100;
    }
};


class HumanEnemy : public Character {
protected:
    int attackPower;
public:
    HumanEnemy() : Character("HumanEnemy", rand() % 10 + 20, rand() % 2 == 0 ? "Male" : "Female") {
        warmWeaponSkill = rand() % 41 + 30;
        coldWeaponSkill = rand() % 41 + 30;
        attackPower = rand() % 11 + 45;
    }

    void TakeDamage(PlayerCharacter& player,Shop& shop) {
        if(player.getHealth()>0){
            if(player.getTankEntered()){
                health -= 100;
                std::cout << "Tank entered the game and reduced Enemy Health by 100!"<< std::endl;
                if (health <= 0) {
                    health = 0;
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The human enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+50);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 50. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+70);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setTankEntered(false);
            }
            if(player.getsniperEntered()){
                health -= 50;
                std::cout << "Sniper entered the game and reduced Enemy Health by 50!"<< std::endl;
                if(health>0){
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0 && player.getHealth()>0) {
                    health = 0;
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The human enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+50);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 50. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+70);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setsniperEntered(false);
            }
            if(player.getIsPermanentItemRequested()){
                health -= player.PermanentItem(player.getSelectedWeapon());
                if (player.getSelectedWeapon() == "Shotgun") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   Shotgun_____ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                } else if (player.getSelectedWeapon() == "Machine Gun") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   MachinGun_____ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                    std::cout<<"           |\\"<<std::endl;
                } else if (player.getSelectedWeapon() == "Is50") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   IS50_________ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                } else if (player.getSelectedWeapon() == "M16") {
                    std::cout << "        _________________" << std::endl;
                    std::cout << "_____ /   M16 _________ /" << std::endl;
                    std::cout << "\\______/ \\/" << std::endl;
                }
                std::cout << "You attacked the Human Enemy for " << player.PermanentItem(player.getSelectedWeapon())<< " damage with SelectedWeapon ! "<< std::endl;
                if(health>0){
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0 && player.getHealth()>0) {
                    health = 0;
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The human enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+50);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 50. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+70);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setIsPermanentItemRequested(false);
                } 
            if(player.getIsThrowableItemRequested()){
                health -= player.ThrowableItem(player.getSelectedItem()); 
                std::cout << "You attacked the Human Enemy for "<< player.ThrowableItem(player.getSelectedItem()) << " damage with SelectedItem ! "<< " " << std::endl;
                if(health>0){
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0 && player.getHealth()>0) {
                    health = 0;
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The human enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+50);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 50. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+70);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;}
                    player.setIsThrowableItemRequested(false);
                }
        }
        if (Techniques == Attack || Techniques == ComeBack)
        {
            if(player.getISAttackPowerRequested()){
            health -= player.getPlayerattackPower();
            if (health < 100 && player.getHealth()>0) {
                std::cout << "You attacked the human enemy for " << player.getPlayerattackPower() << " damage !";
                if(health>0){
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                }
                else if (health <= 0 && player.getHealth()>0) {
                    health = 0;
                    std::cout<<" The health of the human enemy is : " << health << " " << std::endl;
                    std::cout << "you won! The human enemy character was killed. " << std::endl;
                    player.setLevel(player.getLevel()+1);
                    std::cout<<"player level : "<<player.getLevel()<<std::endl;
                    player.setHealth(player.getHealth()+50);
                    if(player.getHealth()>100){
                        player.setHealth(100);
                    }
                    std::cout<<"Increase player health by 50. "<<"Player Health: " << player.getHealth() << std::endl;
                    player.setcoin(player.getcoin()+70);
                    std::cout<<"Number of coin : "<<player.getcoin()<<std::endl;
                }
            }
            }
        }
        else if (Techniques == ReturnAttack) {
            if(player.getISAttackPowerRequested()){
            player.setHealth(player.getHealth() - player.getPlayerattackPower());
            std::cout << "oops! Human Enemy return the attack to the player with a strength of " << player.getPlayerattackPower() << ". " << std::endl;}
        }
        else if (Techniques == Defense) {
            if(player.getISAttackPowerRequested()){
            health = health;
            std::cout << "oops! The human enemy defended the player's attack. " << std::endl;}
        }
    }
    void attack(PlayerCharacter& player, StrongerZombieCharacter& StrongerZombie, ZombieCharacter& zombie, Shop& shop){
        std::cout<<"It is the player's turn to attack the enemy. Attack menu :"<<std::endl;
                std::cout<<"1. Attack power"<<std::endl;
                std::cout<<"2. Permanent weapon"<<std::endl;
                std::cout<<"3. Buy items from the shop"<<std::endl;
                int choice;
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                switch (choice) {
                    case 1: {
                        player.setISAttackPowerRequested(true);
                        TakeDamage(player, shop);
                        break;
                    }
                    case 2: {
                        std::cout << "Enter character's selected weapon (M16 ,power:30/Is50 ,power:30/Shotgun ,power:35/Machine Gun ,power:50): ";
                        std::string selectedWeapon;
                        std::cin >> selectedWeapon;
                        player.setSelectedWeapon(selectedWeapon);
                        player.setIsPermanentItemRequested(true);
                        TakeDamage(player, shop);
                        break;
                    }
                    case 3: {
                        shop.Buy(player);
                        TakeDamage(player, shop);
                        break;
                    }
                    default:
                        std::cout << "Invalid choice. Please try again." << std::endl;
                        break;
                }
                if(getHealth()>0){
                std::cout<<"It is the enemy's turn to attack"<<std::endl;
                player.takeDamage(attackPower);
                std::cout << "Human Enemy attacked Player for " << attackPower << " damage." << std::endl;}
    }
    void attackPlayerCharacter(PlayerCharacter& player, StrongerZombieCharacter& StrongerZombie, ZombieCharacter& zombie, Shop& shop) {
        int determinative;

        // Display information about the human enemy
        std::cout << std::endl << "Information about the human enemy : " << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Gender: " << gender << std::endl;
        std::cout << "Health: " << health << std::endl;

        // Wait for 1/6 minute before determining the attack technique
        auto startTime = std::chrono::high_resolution_clock::now();
        std::this_thread::sleep_for(std::chrono::minutes(1 / 6));
        auto endTime = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::minutes>(endTime - startTime);
        if (duration.count() >= 1 / 6) {
            determinative = 1;
        }

        // Determine the attack technique based on the player's level
        if (determinative == 1)
        {
            if (player.getLevel() >= 8 && player.getLevel() <= 9) {
                // Use the Attack technique
                while(health>0 && player.getHealth()>0){
                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);}
                if(player.getHealth() == 0){
                    player.setHealth(100);
                }
                health=100;

            }
            else if (player.getLevel() >= 10) {
                // Use the Defense technique
                Techniques = Defense;
                attack(player, StrongerZombie, zombie, shop);

                // Use the Attack technique
                while(health>0 && player.getHealth()>0){
                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);}
                if(player.getHealth() == 0){
                    player.setHealth(100);
                }
                health=100;
            }
            else if (player.getLevel() >= 12) {
                Techniques = Defense;
                attack(player, StrongerZombie, zombie, shop);

                // Use the ReturnAttack technique
                Techniques = ReturnAttack;
                attack(player, StrongerZombie, zombie, shop);

                // Use the Attack technique
                while(health>0 && player.getHealth()>0){
                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);}
                if(player.getHealth() == 0){
                    player.setHealth(100);
                }
                health=100;
            }
            else if (player.getLevel() >= 14) {
                // Use the Attack technique
                Techniques = Attack;
                attack(player, StrongerZombie, zombie, shop);

                // Use the Run technique
                Techniques = Run;
                std::cout << "The human enemy fled to recuperate! But the zombies are coming. " << std::endl;

                // Randomly select a zombie to attack the player
                int RandomSelection = rand() % 2;
                if (RandomSelection == 0) {
                    StrongerZombie.attackPlayer(player, shop);
                }
                else if (RandomSelection == 1) { zombie.attackPlayer(player, shop); }

                // If the zombies are defeated, the human enemy returns with full health
                if (StrongerZombie.getHealth() == 0 || zombie.getHealth() == 0)
                {
                    player.setLevel(player.getLevel()-1);
                    Techniques = ComeBack;
                    health = 100;
                    std::cout << "Human enemy returned with 100 health. " << std::endl;
                    attack(player, StrongerZombie, zombie, shop);
                    while(health>0 && player.getHealth()>0){
                        Techniques = Attack;
                        attack(player, StrongerZombie, zombie, shop);}
                    if(player.getHealth() == 0){
                        player.setHealth(100);
                    }
                    health=100;
                }
            }
            else if (player.getLevel() >= 16) {
                // Randomly select the attack technique
                int Randomselection = rand() % 2 + 1;
                if (Randomselection == 1)
                {

                    // Use the Attack, Defense, ReturnAttack, and Attack techniques

                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Defense;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = ReturnAttack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = ReturnAttack;
                    attack(player, StrongerZombie, zombie, shop);
                    while(health>0 && player.getHealth()>0){
                        Techniques = Attack;
                        attack(player, StrongerZombie, zombie, shop);}
                    if(player.getHealth() == 0){
                        player.setHealth(100);
                    }
                    health=100;
                }
                else if (Randomselection == 2) {

                    // Use the Attack, Defense, ReturnAttack, Attack, and Defense techniques

                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Defense;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = ReturnAttack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Defense;
                    attack(player, StrongerZombie, zombie, shop);
                    while(health>0 && player.getHealth()>0){
                        Techniques = Attack;
                        attack(player, StrongerZombie, zombie, shop);}
                    if(player.getHealth() == 0){
                        player.setHealth(100);
                    }
                    health=100;
                }
                else if (player.getLevel() >= 18) {

                    // Use the Attack, ReturnAttack, Defense, ReturnAttack, and Attack techniques

                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = ReturnAttack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Defense;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = ReturnAttack;
                    attack(player, StrongerZombie, zombie, shop);
                    Techniques = Attack;
                    attack(player, StrongerZombie, zombie, shop);

                    // Use the Run technique
                    Techniques = Run;
                    std::cout << "The human enemy fled to recuperate! But the zombies are coming. " << std::endl;
                    StrongerZombie.attackPlayer(player, shop);
                    zombie.attackPlayer(player, shop);

                    // If the zombies are defeated, the human enemy returns with full health
                    if (StrongerZombie.getHealth() == 0 && zombie.getHealth() == 0) {
                        player.setLevel(player.getLevel()-2);
                        Techniques = ComeBack;
                        health = 100;
                        std::cout << "Human enemy returned with 100 health. " << std::endl;
                        attack(player, StrongerZombie, zombie, shop);
                        Techniques = Defense;
                        attack(player, StrongerZombie, zombie, shop);
                        Techniques = Attack;
                        attack(player, StrongerZombie, zombie, shop);
                        Techniques = ReturnAttack;
                        attack(player, StrongerZombie, zombie, shop);
                        while(health>0 && player.getHealth()>0){
                            Techniques = Attack;
                            attack(player, StrongerZombie, zombie, shop);}
                        if(player.getHealth() == 0){
                            player.setHealth(100);
                        }
                        health=100; 
                    }
                }
            }
        }
    }
};



class RandomAttack {
public:
    // Function to perform random attack
    static void performRandomAttack(PlayerCharacter& player, ZombieCharacter& zombie, StrongerZombieCharacter& strongerZombie, HumanEnemy& enemy, Shop& shop) {
        int randomEnemy = rand() % 3; // Randomly select an enemy to attack

        if (randomEnemy == 0 && player.getLevel() < 12) {
            // Attack the player with a zombie
            zombie.attackPlayer(player, shop);
        }
        else if (randomEnemy == 1 && player.getLevel() < 12) {
            // Attack the player with a stronger zombie
            strongerZombie.attackPlayer(player, shop);
        }
        else if (randomEnemy == 2 && player.getLevel() >= 8 && player.getLevel() < 12) {
            // Attack the player with a Human Enemy
            enemy.attackPlayerCharacter(player, strongerZombie, zombie, shop);
        }
        else if (player.getLevel() >= 12) {
            // Attack the player with a Human Enemy
            enemy.attackPlayerCharacter(player, strongerZombie, zombie, shop);
        }


    }

};

void displayMainMenu() {
    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "1. Create Character" << std::endl;
    std::cout << "2. Start Game" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

void displayMainMenu2() {
    std::cout<<"1. next level"<<std::endl;
    std::cout << "2. Change player information" << std::endl;
    std::cout << "3. Exit" << std::endl;
}

// Function to handle player's choice
void handleChoice(PlayerCharacter& player, ZombieCharacter& zombie, StrongerZombieCharacter& strongerZombie, HumanEnemy& enemy, Shop& shop) {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        std::string name, gender, selectedWeapon, selectedItem;
        int age;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter character's name: ";
        std::getline(std::cin, name);

        std::cout << "Enter character's age: ";
        std::cin >> age;

        std::cout << "Enter character's gender (Male/Female): ";
        std::cin >> gender;

        player = PlayerCharacter(name, age, gender);
        std::cout << "Character created successfully!" << std::endl;
        break;
    }
    case 2: {
        
        std::cout << "Starting the game..." << std::endl;
        RandomAttack::performRandomAttack(player, zombie, strongerZombie, enemy, shop);
        break;
    }
    case 3: {
       
        std::cout << "Exiting the game..." << std::endl;
        exit(0);
        break;
    }
      
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }
}       

void handleChoice2(PlayerCharacter& player, ZombieCharacter& zombie, StrongerZombieCharacter& strongerZombie, HumanEnemy& enemy, Shop& shop) {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1: {
        RandomAttack::performRandomAttack(player, zombie, strongerZombie, enemy, shop);
        break;
    }
    case 2: {
        std::string name, gender, selectedWeapon, selectedItem;
        int age;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter character's name: ";
        std::getline(std::cin, name);

        std::cout << "Enter character's age: ";
        std::cin >> age;

        std::cout << "Enter character's gender (Male/Female): ";
        std::cin >> gender;

        player = PlayerCharacter(name, age, gender);
        std::cout << "Character created successfully!" << std::endl;
        break;
    }
    case 3: {
       
        std::cout << "Exiting the game..." << std::endl;
        exit(0);
        break;
    }
      
    default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
    }
}       

int main() {
    srand(time(nullptr));

    PlayerCharacter player("Default", 20, "Male");
    ZombieCharacter zombie;
    StrongerZombieCharacter strongerZombie;
    HumanEnemy enemy;
    Shop shop;
    displayMainMenu();
    handleChoice(player, zombie, strongerZombie, enemy, shop);
    while (true) {
        displayMainMenu2();
        handleChoice2(player, zombie, strongerZombie, enemy, shop);
        handleChoice(player, zombie, strongerZombie, enemy, shop);
    }

    return 0;
}
