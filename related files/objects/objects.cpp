#include <iostream>
#include <string>
#include <fstream>

class Object
{
private:
    int age;
    std::string filePath;

    void replace(std::string& str, char ch, char replacement)
    {
        for (char& c : str)
        {
            if (c == ch)
                c = replacement;
        }
    }

public:
    Object(std::string filePath)
    {
        this->filePath = filePath;
    }

    void Show()
    {
        std::string line;
        std::ifstream handler(this->filePath);

        if (handler.is_open())
        {
            while (getline(handler, line))
            {
                replace(line, '0', ' ');
                replace(line, '1', '_');
                replace(line, '2', '|');
                replace(line, '3', '/');
                replace(line, '4', '\\');

                std::cout << line << std::endl;
            }

            handler.close();
        }
        else
            std::cout << "Unable to open file : " << this->filePath << std::endl;
    }
};

int main()
{
    Object obj("objects\\human_enemy.txt");
    obj.Show();

    object obj("objects\\zombiee.txt");
    obj.Show();

    Object obj4("objects\\zombie.txt");
    obj4.Show();
}
