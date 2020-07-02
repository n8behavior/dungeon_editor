#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QSessionManager>

#include "dungeon.hpp"

class EditorWindow: public QMainWindow
{
    Q_OBJECT

public:
    EditorWindow();

    void load_dungeon(const QString &dungeon_name);

private slots:
    void new_dungeon();
    void open();
    bool save();
    bool save_as();
    void about();
    void dungeon_was_modified();
#ifndef QT_NO_SESSIONMANAGER
    void commit_data(QSessionManager &);
#endif

private:
    void create_editor_actions();
    void create_editor_status_bar();
    void create_editor_dock_widgets();
    void read_editor_settings();
    void write_editor_settings();
    bool maybe_save_dungeon();
    bool save_dungeon(const QString &dungeon_name);
    void set_current_dungeon(const QString &dungeon_name);
    Qt3DCore::QEntity *createScene();

    Dungeon dungeon;
    QString current_dungeon;
    QListWidget* dungeon_properties;
};


#endif // EDITORWINDOW_H
