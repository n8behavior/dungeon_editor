#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSessionManager>

class dungeon_editor : public QMainWindow
{
    Q_OBJECT

public:
    dungeon_editor();

    void load_dungeon(const QString &dungeon_name);

protected:
    void closeEvent(QCloseEvent *event) override;

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

    QPlainTextEdit *q_plain_text_edit;
    QString current_dungeon;
    QListWidget *dungeon_properties;
};
#endif // MAINWINDOW_H
