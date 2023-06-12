#include "game.h"
#include<QFontDatabase>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int id = QFontDatabase::addApplicationFont(FONT_PATH);
    qWarning()<<"je rentre dans la main";
    if (id != -1)
    {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(id);
        qDebug() << "Loaded font:" << fontFamilies.at(0);
    }
    try {
        Game game;
    } catch (std::string &e) {
    } catch (std::exception &e){
    }
    return a.exec();
}
