#include <QtWidgets>
#include "mainwindow.h"

dungeon_editor::dungeon_editor()
    : q_plain_text_edit(new QPlainTextEdit)
{
    setCentralWidget(q_plain_text_edit);

    create_editor_actions();
    create_editor_status_bar();
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

void dungeon_editor::closeEvent(QCloseEvent *event) {
    if (maybe_save_dungeon()) {
        write_editor_settings();
        event->accept();
    } else {
        event->ignore();
    }
}

void dungeon_editor::new_dungeon() {
    if (maybe_save_dungeon()) {
        q_plain_text_edit->clear();
        set_current_dungeon(QString());
    }
}

void dungeon_editor::open()
{

}


bool dungeon_editor::save()
{

}

bool dungeon_editor::save_as()
{

}

void dungeon_editor::about()
{

}

void dungeon_editor::dungeon_was_modified()
{

}

void dungeon_editor::commit_data(QSessionManager &)
{

}

void dungeon_editor::create_editor_actions()
{

}

void dungeon_editor::create_editor_status_bar()
{

}

void dungeon_editor::read_editor_settings()
{

}

void dungeon_editor::write_editor_settings()
{

}

bool dungeon_editor::maybe_save_dungeon()
{

}

bool dungeon_editor::save_dungeon(const QString &file_name)
{

}

void dungeon_editor::set_current_dungeon(const QString &dungeon_name)
{

}

QString dungeon_editor::stripped_dungeon_name(const QString &full_dungeon_name)
{

}

