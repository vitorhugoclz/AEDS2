""""Programa com a estrutura básica de pilha e filha como objetos"""


class Pilha:
    """"Objeto de exemplifica o funcionamento de uma 'Pilha" """

    def __init__(self, tamanho):
        self. tamanho = tamanho
        self.pilha = list()
    def inserir(self, novo : int):
        """"Inserir um novo valor passado como parametro para a 'Pilha' """

        if len(self.pilha) < self.tamanho:
            self.pilha.append(novo)

        else:
            print("Pilha cheia")


    def remover(self) -> int:
        """" Remove o ultimo elemento da 'Pilha' """

        if len(self.pilha) > 0:
            retornar = self.pilha[-1]
            self.pilha.pop(-1)
            return retornar

        else:
            print("Pilha vazia")
            return None


    def exibir(self):
        """"Monstra através da função print os elementos da 'Pilha' """

        if len(self.pilha) > 0:
            for i in self.pilha:
                print(i)

        else:
            print("Pilha vazia")


class Fila:
    """"Objeto que exemplifica o funcionamento de uma 'Fila' """

    def __init__(self, tamanho):
        self.tamanho = tamanho
        self.fila = []

    def inserir(self, novo : int):
        """"Inseri novo elemento a 'Fila' """
        if len(self.fila) < self.tamanho:
            self.fila.append(novo)

        else:
            print("Fila está cheia")

    def remover(self):
        """"Remove o primeiro elemento da 'Fila' """
        if len(self.fila) > 0:
            retornar = self.fila[0]
            self.fila.pop(0)
            return retornar
        else:
            print("Fila vazia")
            return None

    def exibir(self):
        """"Usa da função print para exibir os elementos da 'Fila' """
        if len(self.fila) > 0:
            for i in self.fila:
                print(i)
        else:
            print("Fila vazia")
