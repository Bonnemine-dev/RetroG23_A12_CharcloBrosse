#include "game.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        Game game;
    } catch (std::string &e) {
    } catch (std::exception &e){
    }
    return a.exec();
}
