#include "game.h"
#include<QFontDatabase>
#include <QApplication>
#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int id = QFontDatabase::addApplicationFont(FONT_PATH);
    if (id != -1)
    {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);
        qDebug() << "Loaded font:" << fontFamilies.at(0);
    }
    int id2 = QFontDatabase::addApplicationFont(":/ressources/VT323-Regular.ttf");
    if (id2 != -1)
    {
        QStringList fontFamilies2 = QFontDatabase::applicationFontFamilies(id2);
        qDebug() << "Loaded font:" << fontFamilies2.at(0);
    }
    try {
        Game game;
        // Autres actions de gestion des erreurs si nécessaires
    } catch (const std::runtime_error& e) {
        // Gérer les autres exceptions de type std::exception
        std::cerr <<"Erreur : " + std::string(e.what());
        return 1;
        // Autres actions de gestion des erreurs si nécessaires
    }
    return a.exec();
}
