#include "game.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        Game game;
    } catch (std::string &e) {
        qWarning() << e.c_str() << "\n";
    } catch (std::exception &e){
        qWarning() << e.what() << "\n";
    }
    return a.exec();
}
