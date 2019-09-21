from funcaoDistancia import alcance
from pacote import Pacote
from listas import nos
from listas import indicesParaVer


class CamadaFisica:

    def __init__(self, x, y, id, cobertura, bateria):
        self._x = x
        self._y = y
        self._id = id
        self._cobertura = cobertura
        self._bateria = bateria
        self._vizinhos = []
        self._pacotesEnviados = []
        self._pacotesRecebidos = []
        self._pacotesSalvos = []

    def encontraVizinhos(self):
        """
        Descobre nós vizinhos com base no alcance e da posicao e os add na lista
        """
        self._bateria -= 1
        #print("Bateria:", _bateria)
        for no in nos:
            # se o nó não for ele mesmo e se puder alcançá-lo
            if((no._id != self._id) and (alcance(self._x, self._y, self._cobertura, no._camadaRede._camadaEnlace._camadaFisica._x, no._camadaRede._camadaEnlace._camadaFisica._y))):
                # se o não estiver na lista de vizinhos
                if(no not in self._vizinhos):
                    # add a lista de vizinhos
                    self._vizinhos.append(no)

    def recebePacote(self, pacote):
        """
        Recebe pacote
        """
        # Add a lista global
        indicesParaVer.append(self._id)
        # Add a lista local de recebidos
        self._pacotesRecebidos.append(pacote)

    def enviaPacote(self):
        """
        Envia pacote para todos os vizinhos
        """
        # Encontra e add os vizinhos na lista
        self.encontraVizinhos()
        # Percorre vizinhos
        for no in self._vizinhos:
            # Envia pacote aos vizinhos
            no._camadaRede._camadaEnlace._camadaFisica.recebePacote(
                self._pacotesEnviados[0])
        # Add o pacote na lista de salvos
        self._pacotesSalvos.append(self._pacotesEnviados.pop(0))
