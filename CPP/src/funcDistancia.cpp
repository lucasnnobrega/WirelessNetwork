#include "../include/funcDistancia.hpp"

bool alcance(int centroX, int centroY, double raio, int x, int y)
{
    // calculo de distância usando a fórmula de distância entre dois pontos
    double distancia = std::sqrt(std::pow((centroX - x), 2) + std::pow((centroY - y), 2));
    // se alcancar retorna verdadeiro
    if (distancia <= raio)
    {
        return true;
    }
    // caso contrario retorna falso
    else
    {
        return false;
    }
}