#include <QtCore/QFile>
#include <QtCore/QObject>
#include <QtWidgets/QApplication>


#include "editor_window.hpp"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    qSetMessagePattern("%{message} %{backtrace depth=2 separator=\" from \"}");

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Pattycake Mafia");
    QCoreApplication::setApplicationName("Dungeon Editor");

    // set stylesheet
    //QFile file(":/dark.qss");
    //file.open(QFile::ReadOnly | QFile::Text);
    //QTextStream stream(&file);
    //app.setStyleSheet(stream.readAll());

    EditorWindow main_window {};
    main_window.show();
    main_window.resize(800, 600);

    return app.exec();
}
