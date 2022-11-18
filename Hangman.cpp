#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{

    char yesOrNo;
    std::string word = "";
    std::string output = "";
    int failedCounter = 0;
    const char *requirements[10] = {"dynamit", "parkuhr", "tasche", "rakete", "notizbuch", "iempfstoff", "provinz", "aschenbecher", "ungeschickt", "diskette"};

    // Query whether you want to enter a word yourself
    std::cout << "Moechten Sie selber ein Wort eingeben? [y][n]" << std::endl;

    std::cin >> yesOrNo;

    if (yesOrNo == 'y')
    {
        std::cout << "Bitte geben Sie ein Wort ein" << std::endl;
        std::cin >> word;
        system("cls");
    }
    else if (yesOrNo == 'n')
    {
        srand(time(0));
        word = requirements[(rand() % 10) + 1];
    }
    else
    {
        std::cout << "Ihre Eingabe war nicht korrekt" << std::endl;
        return -1;
    }

    for (int i = 0; i < word.length(); i++)
    {
        output.append("-");
    }
    std::cout << output << std::endl;

    while ((output.find("-") != std::string::npos) && (failedCounter < 10))
    {
        char input;
        std::cin >> input;

        if (word.find(input) == std::string::npos)
        {
            failedCounter++;
        }
        else
        {

            for (int i = 0; i < word.length(); i++)
            {
                if (word[i] == input)
                {
                    output[i] = input;
                }
            }
        }
        std::cout << output << ", du hast noch " << (10 - failedCounter) << " Fehlversuche" << std::endl;
    }
    if (output.find("-") == std::string::npos)
    {
        std::cout << output << "\n\n=============== WINNER ===============\n"
                  << std::endl;
        system("pause");
    }
    else
    {
        std::cout << output << "\n\n============== GAME OVER =============\n\nDas Wort lautete: " << word << std::endl;
        system("pause");
    }
    return 0;
}