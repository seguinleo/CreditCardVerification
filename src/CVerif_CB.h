#ifndef CVERIF_CB_H
#define CVERIF_CB_H

class CVerif_CB
{
private:
    unsigned char numeroCB[16];
    bool numeroCB_OK;
    bool carteValide;
    bool dateCB_OK;

public:
    CVerif_CB();
    ~CVerif_CB();
    void VerifierNumeroCB(unsigned char *numerocb);
    void VerifierDateCB(unsigned char moiscb, int anneecb);
    bool getNumeroCB_OK();
    bool getDateCB_OK();
    bool getCarteValide();
    void setCarteValide();
};

#endif // CVERIF_CB_H
