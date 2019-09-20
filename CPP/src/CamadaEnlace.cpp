//#include "../include/CamadaEnlace.hpp"
//
//CamadaEnlace::CamadaEnlace(/* args */)
//{
//}
//
//CamadaEnlace::~CamadaEnlace()
//{
//}
//
//void CamadaEnlace::enviaPacote()
//{
//    /*
//    #Envia os pacotes para outros nós
//    def enviaPacote(self):
//        self._acessoAoMeio = self.acessoAoMeio()
//        #Verifica se o meio está livre
//        if(self._acessoAoMeio == True):
//            #Vefifica se a lista de pacotes para envio da camada da física está vazia
//            if(self._camadaFisica._pacotesEnviados != []):
//                #Verifica se o no não está em backoff
//                if(self._backoff == 0):
//                    #Envia pacote pela camada fisica
//                    self._camadaFisica.enviaPacote()
//                #Caso contrário
//                else:
//                    #Add o no na lista global de proximo a enviar
//                    proximoAEnviar.append(self._camadaFisica._id)
//                    #Subtrai backoff
//                    self._backoff = (self._backoff - 1)
//        #Caso o meio esteja ocupado o host entrará em backoff
//        else:
//            #Vefifica se a lista de pacotes para envio da camada da física está vazia
//            if(self._camadaFisica._pacotesEnviados != []):
//                #Verifica se o no não está em backoff
//                if(self._backoff == 0):
//                    #coloca no em backoff
//                    self._backoff = randint(1, 8)
//                    #Exibe backoff
//                    self.exibeBackoff(self._camadaFisica._id, self._backoff)
//                    #Add o no na lista global de proximo a envir
//                    proximoAEnviar.append(self._camadaFisica._id)
//    */
//}
//
//void CamadaEnlace::exibeBackoff(){
//    //print("Id\n", id, ": No entrou em Backoff, valor: ", backoff)
//};
//void CamadaEnlace::recebePacote(){
//    /*
//    #Verifica se mais de uma pacote chegou no instante, detecta colisão
//        if(len(self._camadaFisica._pacotesRecebidos) > 1):
//            self._camadaFisica._pacotesRecebidos.clear()
//            self.exibeColisao(self._camadaFisica._id)
//        #Caso não haja colisão
//        else:
//            #Verifica se existe pacote para receber
//            if(len(self._camadaFisica._pacotesRecebidos) == 1):
//                pacote = self._camadaFisica._pacotesRecebidos.pop(0)
//                cabecalho = pacote.getCabecalhoEnlace()
//                #Verifica se o pacote é para aquele no
//                if(cabecalho._macDestino == self._camadaFisica._id):
//                    #Add pacote a lista de lidos
//                    self._pacotesLidos.append(pacote)
//                elif(cabecalho._macDestino  == -1):
//
//                    #Add pacote a lista de lidos
//                    self._pacotesLidos.append(pacote)
//    */
//};
//
//void CamadaEnlace::exibeColisao(){
//    //print("Houve Colisão neste no \nID: ", id)
//};
//
//bool CamadaEnlace::acessoAoMeio()
//{
//    /*
//    if(self._camadaFisica._pacotesRecebidos == []):
//        return True
//    else:
//        return False
//    */
//
//    if (self._camadaFisica._pacotesRecebidos == [])
//    {
//        return true;
//    }
//    else
//    {
//        return False;
//    }
//};
//
//void CamadaEnlace::addPacote(){
//    /*
//    cabecalho = Cabecalho("ENLACE", self._camadaFisica._id, macDestino, 0, -1, -1, -1)
//    pacote.addCabecalho(cabecalho)
//    self._camadaFisica._pacotesEnviados.append(pacote)
//    */
//};
//