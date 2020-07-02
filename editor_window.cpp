#include <QtCore/QSettings>

#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>

#include <QtGui/QScreen>

#include <QCoreApplication>

#include "editor_window.hpp"

EditorWindow::EditorWindow() {
    setWindowTitle(QCoreApplication::applicationName());

    // create our dungeon view (3DWindow) and embed it in the editor
    auto *dungeon_view = new DungeonView();
    dungeon_view->createScene();
    auto *dungeon_view_container= QWidget::createWindowContainer(dungeon_view );
    dungeon_view_container->setMinimumSize(QSize(200, 100));
    auto screenSize = dungeon_view ->screen()->size();
    dungeon_view_container->setMaximumSize(screenSize);
    setCentralWidget(dungeon_view_container);

    create_editor_actions();
    create_editor_status_bar();
    create_editor_dock_widgets();
}

void EditorWindow::new_dungeon() {
    qInfo() << "Called";
//    if (maybe_save_dungeon()) {
        // TODO
        //view->clear();
//        set_current_dungeon(QString());
//    }
}

void EditorWindow::open() {
    qInfo() << "Called";
//    if (maybe_save_dungeon()) {
//        QString dungeon_name = QFileDialog::getOpenFileName(this);
//        if (!dungeon_name.isEmpty())
//            load_dungeon(dungeon_name);
//    }
}

bool EditorWindow::save() {
    qInfo() << "Called";
//    if (current_dungeon.isEmpty())
//        return save_as();
//    else
//        return save_dungeon(current_dungeon);
    return true;
}

bool EditorWindow::save_as() {
    qInfo() << "Called";
//    QFileDialog dialog(this);
//    dialog.setWindowModality(Qt::WindowModal);
//    dialog.setAcceptMode(QFileDialog::AcceptSave);
//    if (dialog.exec() != QDialog::Accepted)
//        return false;
    return true; // save_dungeon(dialog.selectedFiles().first());
}

void EditorWindow::about() {
    qInfo() << "Called";
//    QMessageBox::about(this, tr("What?"), tr("Get back to work!"));
}

void EditorWindow::dungeon_was_modified() {
    qInfo() << "Called";
    // TODO: setWindowModified(view->isModified());
}

void EditorWindow::commit_data(QSessionManager &) {
    qInfo() << "Called";
}

void EditorWindow::create_editor_actions() {
    qInfo() << "Called";
    // Dungeon menu and toolbar
    auto *dungeon_menu = menuBar()->addMenu("&Dungeon");
    auto *dungeon_tool_bar = addToolBar("Dungeon");

    // New dungeon
    const auto new_dungeon_icon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    auto *new_dungeon = new QAction(new_dungeon_icon, tr("&New"), this);
    new_dungeon->setShortcuts(QKeySequence::New);
    new_dungeon->setStatusTip(tr("Create a new dungeon"));
    connect(new_dungeon, &QAction::triggered, this, &EditorWindow::new_dungeon);
    dungeon_menu->addAction(new_dungeon);
    dungeon_tool_bar->addAction(new_dungeon);

    // Load dungeon
    const QIcon open_dungeon_icon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QAction *open_dungeon = new QAction(open_dungeon_icon, tr("&Open"));
    open_dungeon->setShortcuts(QKeySequence::Open);
    open_dungeon->setStatusTip(tr("Open an existing dungeon"));
    connect(open_dungeon, &QAction::triggered, this, &EditorWindow::open);
    dungeon_menu->addAction(open_dungeon);
    dungeon_tool_bar->addAction(open_dungeon);

    // Save dungeon
    const QIcon save_dungeon_icon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction *save_dungeon = new QAction(save_dungeon_icon, tr("&Save"));
    save_dungeon->setShortcuts(QKeySequence::Save);
    save_dungeon->setStatusTip(tr("Save current dungeon"));
    connect(save_dungeon, &QAction::triggered, this, &EditorWindow::save);
    dungeon_menu->addAction(save_dungeon);
    dungeon_tool_bar->addAction(save_dungeon);
    qInfo() << "Completed";
}

void EditorWindow::create_editor_status_bar() {
    qInfo() << "Called";
    statusBar()->showMessage(tr("Ready"));
}

void EditorWindow::create_editor_dock_widgets() {
    qInfo() << "Called";
    auto *dock = new QDockWidget(tr("Dungeon Properties"), this);
    dock->setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    dungeon_properties = new QListWidget(dock);
    dungeon_properties->addItems(QStringList()
                                 << "Height, 64"
                                 << "Width, 64"
                                 << "Wall Cubes, 13");
    dock->setWidget(dungeon_properties);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void EditorWindow::read_editor_settings() {
    qInfo() << "Called";
    QSettings settings;
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect available_geometry = screen()->availableGeometry();
        resize(available_geometry.width() / 3, available_geometry.height() / 2);
        move((available_geometry.width() - width()) / 2,
             (available_geometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}

void EditorWindow::write_editor_settings() {
    qInfo() << "Called";
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
}

bool EditorWindow::maybe_save_dungeon() {
    qInfo() << "Called";
    // TODO: make sure dungeon is saved or user doesn't care about changings
    //if (!view->isModified())
    //    return true;
    //const QMessageBox::StandardButton ret
    //        = QMessageBox::warning(this, tr("Application"),
    //                   tr("The dungeon has been modified.\n"
    //                      "Do you want to save your changes?"),
    //                   QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    //switch (ret) {
    //case QMessageBox::Save:
    //    return save();
    //case QMessageBox::Cancel:
    //    return false;
    //default:
    //    break;
    //}
    return true;
}

bool EditorWindow::save_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    // TODO Persistence
    //QString error_message;

    //QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    //QSaveFile dungeon_data(dungeon_name);
    //if (dungeon_data.open(QFile::WriteOnly | QFile::Text)) {
    //    QTextStream out(&dungeon_data);
    //    out << view->toPlainText();
    //    if (!dungeon_data.commit()) {
    //        error_message = tr("Cannot write dungeon %1:\n%2.")
    //                       .arg(QDir::toNativeSeparators(dungeon_name), dungeon_data.errorString());
    //    }
    //} else {
    //    error_message = tr("Cannot open dungeon %1 for writing:\n%2.")
    //                   .arg(QDir::toNativeSeparators(dungeon_name), dungeon_data.errorString());
    //}
    //QGuiApplication::restoreOverrideCursor();

    //if (!error_message.isEmpty()) {
    //    QMessageBox::warning(this, tr("Application"), error_message);
    //    return false;
    //}

    //set_current_dungeon(dungeon_name);
    //statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void EditorWindow::set_current_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    current_dungeon = dungeon_name;
    // TODO: view->setModified(false);
    setWindowModified(false);

    // TODO: doesn't work with setWindowTitle() above
    if (current_dungeon.isEmpty())
        setWindowFilePath("dungeon1.txt");
    else
        setWindowFilePath(current_dungeon);
}
