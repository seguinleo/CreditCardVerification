#include "CVerif_CB.h"
#include <QDate>

CVerif_CB::CVerif_CB() {
}

CVerif_CB::~CVerif_CB() {
}

bool CVerif_CB::getDateCB_OK() {
    return dateCB_OK;
}

bool CVerif_CB::getNumeroCB_OK() {
    return numeroCB_OK;
}

bool CVerif_CB::getCarteValide() {
    return carteValide;
}

void CVerif_CB::setCarteValide() {
    if((getNumeroCB_OK() == true) && (getDateCB_OK() == true)) {
        carteValide = true;
    }
    else {
        carteValide = false;
    }
}

void CVerif_CB::VerifierNumeroCB(unsigned char *numerocb) {
    for(int i=0; i<16; i++) {
        numeroCB[i] = numerocb[i] - 0x30;
    }
    int somme = 0, reste = 0, index = 0, N1 = 0;
    index = 1;
    while(index <= 15) {
        N1 = numeroCB[index];
        somme = somme + N1;
        index = index + 2;
    }
    index = 0;
    while(index <= 15) {
        N1 = numeroCB[index];
        N1 = N1 * 2;
        if(N1 > 9) {
            N1 = N1 - 9;
        }
        somme = somme + N1;
        index = index + 2;
    }
    reste = somme%10;
    if(reste == 0) {
        numeroCB_OK = true;
    }
    else {
        numeroCB_OK = false;
    }
}

void CVerif_CB::VerifierDateCB(unsigned char moiscb, int anneecb) {
    QDate DateJour = QDate::currentDate();
    if(moiscb < 13) {
        if(DateJour.year() < anneecb) {
            dateCB_OK = true;
        }
        else {
            if(DateJour.year() <= anneecb) {
                if(DateJour.month() <= moiscb) {
                    dateCB_OK = true;
                }
                else {
                    dateCB_OK = false;
                }
            }
            else {
                dateCB_OK = false;
            }
        }
    }
    else {
        dateCB_OK = false;
    }
}
