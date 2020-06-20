#include <QtWidgets>
#include "mainwindow.h"

dungeon_editor::dungeon_editor()
    : q_plain_text_edit(new QPlainTextEdit)
{
    qSetMessagePattern("%{backtrace depth=2 separator=\" from \"}");

    //setWindowTitle(tr("Dungeon Editor [*]"));
    setCentralWidget(q_plain_text_edit);

    create_editor_actions();
    create_editor_status_bar();
    create_editor_dock_widgets();
    read_editor_settings();
    setUnifiedTitleAndToolBarOnMac(true);
    connect(q_plain_text_edit->document(), &QTextDocument::contentsChanged, this ,&dungeon_editor::dungeon_was_modified);

#ifndef QT_NO_SESSIONMANAGER
    QGuiApplication::setFallbackSessionManagementEnabled(false);
    connect(qApp, &QGuiApplication::commitDataRequest,
            this, &dungeon_editor::commit_data);
#endif

    // TODO: should call new map or load previous
    set_current_dungeon(QString());
}

void dungeon_editor::load_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    QFile file(dungeon_name);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(dungeon_name), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    q_plain_text_edit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QGuiApplication::restoreOverrideCursor();
#endif

    set_current_dungeon(dungeon_name);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

void dungeon_editor::closeEvent(QCloseEvent *event) {
    qInfo() << "Called";
    if (maybe_save_dungeon()) {
        write_editor_settings();
        event->accept();
    } else {
        event->ignore();
    }
}

void dungeon_editor::new_dungeon() {
    qInfo() << "Called";
    if (maybe_save_dungeon()) {
        q_plain_text_edit->clear();
        set_current_dungeon(QString());
    }
}

void dungeon_editor::open() {
    qInfo() << "Called";
    if (maybe_save_dungeon()) {
        QString dungeon_name = QFileDialog::getOpenFileName(this);
        if (!dungeon_name.isEmpty())
            load_dungeon(dungeon_name);
    }
}


bool dungeon_editor::save() {
    qInfo() << "Called";
    if (current_dungeon.isEmpty())
        return save_as();
    else
        return save_dungeon(current_dungeon);
}

bool dungeon_editor::save_as() {
    qInfo() << "Called";
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return save_dungeon(dialog.selectedFiles().first());
}

void dungeon_editor::about() {
    qInfo() << "Called";
    QMessageBox::about(this, tr("What?"), tr("Get back to work!"));
}

void dungeon_editor::dungeon_was_modified() {
    qInfo() << "Called";
    setWindowModified(q_plain_text_edit->document()->isModified());
}

void dungeon_editor::commit_data(QSessionManager &) {
    qInfo() << "Called";
}

void dungeon_editor::create_editor_actions() {
    qInfo() << "Called";

    // Dungeon menu and toolbar
    QMenu *dungeon_menu = menuBar()->addMenu(tr("&Dungeon"));
    QToolBar *dungeon_tool_bar = addToolBar(tr("Dungeon"));

    // New dungeon
    const QIcon new_dungeon_icon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *new_dungeon = new QAction(new_dungeon_icon, tr("&New"), this);
    new_dungeon->setShortcuts(QKeySequence::New);
    new_dungeon->setStatusTip(tr("Create a new dungeon"));
    connect(new_dungeon, &QAction::triggered, this, &dungeon_editor::new_dungeon);
    dungeon_menu->addAction(new_dungeon);
    dungeon_tool_bar->addAction(new_dungeon);

    // Load dungeon
    const QIcon open_dungeon_icon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QAction *open_dungeon = new QAction(open_dungeon_icon, tr("&Open"));
    open_dungeon->setShortcuts(QKeySequence::Open);
    open_dungeon->setStatusTip(tr("Open an existing dungeon"));
    connect(open_dungeon, &QAction::triggered, this, &dungeon_editor::open);
    dungeon_menu->addAction(open_dungeon);
    dungeon_tool_bar->addAction(open_dungeon);

    // Save dungeon
    const QIcon save_dungeon_icon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction *save_dungeon = new QAction(save_dungeon_icon, tr("&Save"));
    save_dungeon->setShortcuts(QKeySequence::Save);
    save_dungeon->setStatusTip(tr("Save current dungeon"));
    connect(save_dungeon, &QAction::triggered, this, &dungeon_editor::save);
    dungeon_menu->addAction(save_dungeon);
    dungeon_tool_bar->addAction(save_dungeon);
}

void dungeon_editor::create_editor_status_bar() {
    qInfo() << "Called";
    statusBar()->showMessage(tr("Ready"));
}

void dungeon_editor::create_editor_dock_widgets() {
    qInfo() << "Called";
    QDockWidget *dock = new QDockWidget(tr("Dungeon Properties"), this);
    dock->setAllowedAreas(Qt::DockWidgetArea::AllDockWidgetAreas);
    dungeon_properties = new QListWidget(dock);
    dungeon_properties->addItems(QStringList()
                                 << "Height, 64"
                                 << "Width, 64"
                                 << "Wall Cubes, 13");
    dock->setWidget(dungeon_properties);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void dungeon_editor::read_editor_settings() {
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

void dungeon_editor::write_editor_settings() {
    qInfo() << "Called";
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
}

bool dungeon_editor::maybe_save_dungeon() {
    qInfo() << "Called";
    if (!q_plain_text_edit->document()->isModified())
        return true;
    const QMessageBox::StandardButton ret
            = QMessageBox::warning(this, tr("Application"),
                       tr("The dungeon has been modified.\n"
                          "Do you want to save your changes?"),
                       QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}

bool dungeon_editor::save_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    QString error_message;

    QGuiApplication::setOverrideCursor(Qt::WaitCursor);
    QSaveFile dungeon_data(dungeon_name);
    if (dungeon_data.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream out(&dungeon_data);
        out << q_plain_text_edit->toPlainText();
        if (!dungeon_data.commit()) {
            error_message = tr("Cannot write dungeon %1:\n%2.")
                           .arg(QDir::toNativeSeparators(dungeon_name), dungeon_data.errorString());
        }
    } else {
        error_message = tr("Cannot open dungeon %1 for writing:\n%2.")
                       .arg(QDir::toNativeSeparators(dungeon_name), dungeon_data.errorString());
    }
    QGuiApplication::restoreOverrideCursor();

    if (!error_message.isEmpty()) {
        QMessageBox::warning(this, tr("Application"), error_message);
        return false;
    }

    set_current_dungeon(dungeon_name);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void dungeon_editor::set_current_dungeon(const QString &dungeon_name) {
    qInfo() << "Called";
    current_dungeon = dungeon_name;
    q_plain_text_edit->document()->setModified(false);
    setWindowModified(false);

    if (current_dungeon.isEmpty())
        setWindowFilePath("dungeon1.txt");
    else
        setWindowFilePath(current_dungeon);
}
