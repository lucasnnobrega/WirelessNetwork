#ifndef CAMADAREDE
#define CAMADAREDE

class CamadaRede
{
private:
    /* data */
public:
    CamadaRede(/* args */);
    ~CamadaRede();
    void enviaRREP(macDestino, sequencia, rota);
    void enviaRREQ(macDestino);
    void recebePacote();
    void addPacote(macDestino, mensage, tempo);
    void enviaPacote();
    void exibePacote();
};

#endif //CAMADAREDE
