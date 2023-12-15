#include <QApplication>
#include "QLineEdit_Histo.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLineEdit_Histo window;
    window.setWindowTitle("Messagerie");
    window.show();

    return app.exec();
}
