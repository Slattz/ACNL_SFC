#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_Boot9_triggered();
    void on_BTN_RV_clicked();
    void on_BTN_Present_clicked();

    void on_BTN_Present_Make_clicked();

    void on_BTN_RV_Make_clicked();

    void on_actionAbout_triggered();

    void on_BTN_About_clicked();

private:
    Ui::MainWindow *ui;
    QString m_exedir;
    QString m_outdir;
};

#endif // MAINWINDOW_H
