#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    carteCB = new CVerif_CB();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PB_Verifier_clicked() {
    CVerif_CB verif;
    int annee;
    unsigned char mois;
    unsigned char *numerocb = new unsigned char[16];
    char *numerocb2 = new char[16];
    strcpy(numerocb2, ui->LE_Numero->text().toLatin1());

    for(int i=0; i<16; i++) {
        numerocb[i] = numerocb2[i];
    }

    verif.VerifierNumeroCB(numerocb);
    annee = ui->LE_Annee->text().toInt();
    mois = (unsigned char)ui->LE_Mois->text().toInt();
    verif.VerifierDateCB(mois,annee);
    verif.setCarteValide();

    if(verif.getCarteValide() == true) {
        ui->label_Verification->setText("Valid card !");
    }
    else {
        if(verif.getNumeroCB_OK() == true) {
            ui->label_Verification->setText("Invalid date");
        }
        else {
            ui->label_Verification->setText("Invalid number");
        }
    }
}

void MainWindow::on_PB_Quitter_clicked() {
     exit(0);
}
