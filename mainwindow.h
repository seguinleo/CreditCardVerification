#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CVerif_CB.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_PB_Verifier_clicked();
    void on_PB_Quitter_clicked();

private:
    Ui::MainWindow *ui;

    CVerif_CB *carteCB;
};

#endif // MAINWINDOW_H
