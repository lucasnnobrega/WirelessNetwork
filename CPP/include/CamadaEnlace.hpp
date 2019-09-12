#ifndef CAMADAENLACE
#define CAMADAENLACE

class CamadaEnlace
{
private:
    /* data */
public:
    CamadaEnlace(/* args */);
    ~CamadaEnlace();
    void enviaPacote();
    void exibeBackoff();
    void recebePacote();
    void exibeColisao();
    bool acessoAoMeio();
    void addPacote();
};

#endif //CAMADAENLACE
