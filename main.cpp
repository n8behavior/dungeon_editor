#include <QtCore/QObject>
#include <QtWidgets/QApplication>


#include "editor_window.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(application);

    qSetMessagePattern("%{message} %{backtrace depth=2 separator=\" from \"}");

    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("Pattycake Mafia");
    QCoreApplication::setApplicationName("Dungeon Editor");

    EditorWindow main_window {};
    main_window.show();
    main_window.resize(800, 600);

    return app.exec();
}
