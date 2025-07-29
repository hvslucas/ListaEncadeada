#include <iostream>
using namespace std;

class Node {
public:
    int valor;
    Node* proximo;

    Node(int v) {
        valor = v;
        proximo = nullptr;
    }
};

class ListaEncadeada {
private:
    Node* inicio;
    int tamanho;

public:
    // 1
    ListaEncadeada() {
        inicio = nullptr;
        tamanho = 0;
    }

    // 2
    bool estaVazia() {
        return tamanho == 0;
    }

    // 3
    int obterTamanho() {
        return tamanho;
    }

    // 4
    int obterValor(int indice) {
        if (indice < 1 || indice > tamanho) {
            cout << "Indice invalido" << endl;
            return -1;
        }

        Node* atual = inicio;
        for (int i = 1; i < indice; i++) {
            atual = atual->proximo;
        }

        return atual->valor;
    }

    void modificarValor(int indice, int valor) {
        if (indice < 1 || indice > tamanho) {
            cout << "Indice invalido" << endl;
            return;
        }

        Node* atual = inicio;
        for (int i = 1; i < indice; i++) {
            atual = atual->proximo;
        }

        atual->valor = valor;
    }

    // 5
    void inserirValor(int indice, int valor) {
        if (indice < 1 || indice > tamanho + 1) {
            cout << "Operacao invalida" << endl;
            return;
        }

        Node* novo = new Node(valor);

        if (indice == 1) {
            novo->proximo = inicio;
            inicio = novo;
        } else {
            Node* anterior = inicio;
            for (int i = 1; i < indice - 1; i++) {
                anterior = anterior->proximo;
            }

            novo->proximo = anterior->proximo;
            anterior->proximo = novo;
        }

        tamanho++;
    }

    // 6
    int retirarValor(int indice) {
        if (indice < 1 || indice > tamanho) {
            cout << "Operacao invalida" << endl;
            return -1;
        }

        Node* removido;
        int valor;

        if (indice == 1) {
            removido = inicio;
            inicio = inicio->proximo;
        } else {
            Node* anterior = inicio;
            for (int i = 1; i < indice - 1; i++) {
                anterior = anterior->proximo;
            }

            removido = anterior->proximo;
            anterior->proximo = removido->proximo;
        }

        valor = removido->valor;
        delete removido;
        tamanho--;
        return valor;
    }

    // imprimir lista
    void imprimir() {
        Node* atual = inicio;
        while (atual != nullptr) {
            cout << atual->valor << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }

    // destrutor
    ~ListaEncadeada() {
        Node* atual = inicio;
        while (atual != nullptr) {
            Node* temp = atual;
            atual = atual->proximo;
            delete temp;
        }
    }
};
