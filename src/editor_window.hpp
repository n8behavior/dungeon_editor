#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtGui/QSessionManager>

#include "dungeon.hpp"

class EditorWindow: public QMainWindow
{
    Q_OBJECT

public:
    EditorWindow();
    ~EditorWindow();

    void load_dungeon(const QString &dungeon_name);

private slots:
    void new_dungeon();
    void open();
    bool save();
    bool save_as();
    void about();
    void dungeon_was_modified();
    void show_debug_overlay();
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
    DungeonView *dungeon_view;
    QString current_dungeon;
    QListWidget* dungeon_properties;
};


#endif // EDITORWINDOW_H
