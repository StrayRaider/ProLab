//#include <QtWidgets>
#include<iostream>

class Player{
    private:
        int OyuncuID;
        std::string OyuncuAdi;
        int skor;
    public:
        Player();
        Player(int OyuncuID,std::string OyuncuAdi,int skor){
        };
};

class Computer:Player{
    private:
    public:
};

class User:Player{
    private:
    public:
};
class Tool{
    private:
        int strength;
        int level;
    public:
        Tool();
        Tool(int givenStrength,int givenLevel):strength{givenStrength},level{givenLevel}{};
        void printData();
    };
void Tool::printData(){
    std::cout <<"Strength:" << strength << std::endl;
    std::cout << "Level: " << level << std::endl;
}
class Paper: public Tool{
    private:
        int influence;
    public:
        Paper();
        Paper(int givenLevel,int givenStrength,int givenInfluence){
            influence = givenInfluence;
        };
};

class SpcPaper: public Paper{
    private:
        int thickness;
    public:
        SpcPaper();
        SpcPaper(int givenLevel,int givenStrength);
};

class Rock: public Tool{
    private:
        int soft;
    public:
        Rock();
        Rock(int givenLevel,int givenStrength);
};

class HvRock: public Rock{
    public:
        int hotness;
    public:
        HvRock();
        HvRock(int givenLevel,int givenStrength);
};


class Scissors: public Tool{
    private:
        int sharpness;
    public:
        Scissors();
        Scissors(int givenLevel,int givenStrength);
};

class MasterScissors: public Scissors{
    private:
        int resistance;
    public:
        MasterScissors();
        MasterScissors(int givenLevel,int givenStrength);
};

int main(int argc, char *argv[])
{

    /*int user_input;
    std::cout << "1 - Makas\n2- Taş\n3- Kağıt\n" << std::endl;
    std::cout << "Taş,Kağıt ve Makastan birini seçiniz: " << std::endl;
    std::cin >> user_input;
    if (user_input==1)
    {
        
    }
    else if (user_input==2)
    {
        
    }
    else if (user_input==3)
    {
        
    }
    else{
        std::cout << "\nhata.\n" << std::endl;
    }*/

    Tool mytool = Tool(1,31);
    mytool.printData();

    return 0;
}



    /*srand (time(NULL));
    for(int i=0;i<5;i++){
        int rand_num;
        rand_num = rand() % 3 + 1;
        //rock
        if(rand_num == 1){
           printf("1\n"); 
        }
        //paper
        else if(rand_num == 2){
           printf("2\n"); 
            
        }
        //scissors
        else if(rand_num == 3){
           printf("3\n"); 
            
        }
    }*/

    /*
    QApplication app(argc, argv);
    QWidget window;
    window.resize(320, 240);

    QPushButton *button = new QPushButton("Hello World2",&window);
    button->setGeometry(10, 10, 80, 30);

    window.show();
    window.setWindowTitle(
        QApplication::translate("toplevel", "Top-level widget"));
    return app.exec();
*/