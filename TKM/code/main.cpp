//#include <QtWidgets>
#include<iostream>

class Tool{
    public:
        int strength;
        int level;
    };

class Paper: public Tool{
    public:
        int influence;
};

class SpcPaper: public Paper{
    public:
        int thickness;
};

class Rock: public Tool{
    public:
        int soft;
};

class HvRock: public Rock{
    public:
        int hotness;
};


class Scissors: public Tool{
    public:
        int sharpness;
};

class MasterScissors: public Scissors{
    public:
        int resistance;
};

int main(int argc, char *argv[])
{

    Tool obj_1;
    obj_1.strength = 0;
    obj_1.level = 0;

    printf("%d\n",obj_1.strength);

int main(int argc, char *argv[])
{
    srand (time(NULL));



    for(int i=0;i<5;i++){
        int rand_num;
        rand_num = rand() % 3 + 1;
        if(rand_num == 1){
            
        }
        else if(rand_num == 2){
            
        }
        else if(rand_num == 3){
            
        }
    }
    Tool obj_1;
    obj_1.strength = 0;
    obj_1.level = 0;

    printf("%d\n",obj_1.strength);







int main(int argc, char *argv[])
{

    Tool obj_1;
    obj_1.strength = 0;
    obj_1.level = 0;

    printf("%d\n",obj_1.strength);

    Paper pap_1;
    pap_1.influence = 0;
    printf("%d\n",pap_1.influence);

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
    return 0;
}
