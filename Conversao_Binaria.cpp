#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

int menu();

void conversao();

void operacao_binaria();

void ajuda();

void documentacao();

void base_para_mesma_base(int base_atual, int base_convertida, int numero_atual);

void base_2_para_base_10(int base_atual, int base_convertida, int numero_atual);

void base_10_para_base_2(int base_atual, int base_convertida, int numero_atual);

void base_qualquer_para_base_2(int base_atual, int base_convertida, int numero_atual);

void base_qualquer_para_base_10(int base_atual, int base_convertida, int numero_atual);

void base_qualquer_para_base_qualquer(int base_atual, int base_convertida, int numero_atual);

void base_10_para_base_qualquer(int base_atual, int base_convertida, int numero_atual);

void base_2_para_base_qualquer(int base_atual, int base_convertida, int numero_atual);

void base_10_para_base_16(int base_atual, int base_convertida, int numero_atual);

void base_2_para_base_16(int base_atual, int base_convertida, int numero_atual);

void base_16_para_base_10(int base_atual, int base_convertida, int numero_atual, string numero_atual_string);

void base_16_para_base_2(int base_atual, int base_convertida, int numero_atual, string numero_atual_string);

int main() {
    int opc_main;
    while (true) {
        opc_main = menu(); //a ação escolhida pelo usuário vai para opc_main
        switch (opc_main) {
            //opc_main em um switch case para acessar a opção que o usuário escolheu
            case 1:
                conversao();
                cout << "\nFim da conversao. Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;
            case 2:


                //operacao_binaria();
                system("pause");

                break;
            case 3:


                ajuda();
                system("pause");

                break;
            case 4:


                //documentacao();
                system("pause");

                break;
            case 5:
                cout << "Saindo...\n";
                system("pause");

                return 0;
                break;
            default:
                cout << "Opcao invalida!\n";
                system("pause");

            //menu();
        }
    }
}

int menu() {
    int opc_menu;
    cout << " _______________________________________________________\n";
    cout << "| BEM VINDO AO PROGRAMA DE CONVERSAO E OPERACAO BINARIA | \n";
    cout << " -------------------------------------------------------\n";
    cout << "Informe qual acao voce deseja fazer: \n";
    cout << "[1] - Conversao binaria.\n";
    cout << "[2] - Operacao binaria.\n";
    cout << "[3] - Ajuda.\n";
    cout << "[4] - Documentacao\n";
    cout << "[5] - Sair.\n";
    cin >> opc_menu;
    return opc_menu;
}

void conversao() {
    int base_atual, base_convertida;
    int numero_atual;
    string numero_atual_string = "";

    cout << "Informe qual o numero (digite 0 se for hexadecimal): ";
    cin >> numero_atual;

    if (numero_atual == 0) {
        cout << "Informe qual o numero hexadecimal: ";
        cin >> numero_atual_string;
        cout << "Informe a base do numero que sera convertido (2,8,10,16 ou outra): ";
        cin >> base_convertida;

        base_atual = 16;

        if (base_convertida == 10) {
            base_16_para_base_10(base_atual, base_convertida, numero_atual, numero_atual_string);
        } else if (base_convertida == 2) {
            base_16_para_base_2(base_atual, base_convertida, numero_atual, numero_atual_string);
        } else {
            cout << "Conversao de hexadecimal para essa base ainda nao implementada.\n";
        }
    } else {
        cout << "Informe a base atual do numero (2,8,10,16 ou outra): ";
        cin >> base_atual;
        cout << "Informe a base do numero que sera convertido (2,8,10,16 ou outra): ";
        cin >> base_convertida;

        if (base_atual == base_convertida) {
            base_para_mesma_base(base_atual, base_convertida, numero_atual);
        } else if (base_atual == 2 && base_convertida == 10) {
            base_2_para_base_10(base_atual, base_convertida, numero_atual);
        } else if (base_atual == 10 && base_convertida == 2) {
            base_10_para_base_2(base_atual, base_convertida, numero_atual);
        } else if (base_convertida == 2 && base_atual != 16) {
            base_qualquer_para_base_2(base_atual, base_convertida, numero_atual);
        } else if (base_atual != 16 && base_convertida == 10) {
            base_qualquer_para_base_10(base_atual, base_convertida, numero_atual);
        } else if (base_atual != 2 && base_atual != 10 && base_convertida != 2 && base_convertida != 10 && base_convertida != 16) {
            base_qualquer_para_base_qualquer(base_atual, base_convertida, numero_atual);
        } else if (base_atual == 10 && base_convertida != 2 && base_convertida != 10 && base_convertida != 16) {
            base_10_para_base_qualquer(base_atual, base_convertida, numero_atual);
        } else if (base_atual == 2 && base_convertida != 2 && base_convertida != 10 && base_convertida != 16) {
            base_2_para_base_qualquer(base_atual, base_convertida, numero_atual);
        } else if (base_atual == 10 && base_convertida == 16) {
            base_10_para_base_16(base_atual, base_convertida, numero_atual);
        } else if (base_atual == 2 && base_convertida == 16) {
            base_2_para_base_16(base_atual, base_convertida, numero_atual);
        } else {
            cout << "Conversao nao implementada.\n";
        }
    }
}

void base_para_mesma_base(int base_atual, int base_convertida, int numero_atual) {
    //base_para_mesma_base
    {
        cout << numero_atual << " b" << base_atual << " ---> " << numero_atual << " b" << base_atual << "\n";
    }
}


void base_2_para_base_10(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    numero_em_string = to_string(numero_atual);
    for (int i = numero_em_string.size() - 1; i >= 0; i--) {
        digitos.push_back(numero_em_string[i] - '0');
    }
    for (int i = 0; i < numero_em_string.size(); i++) {
        if (numero_em_string[i] == '1') {
            somador += pow(2, numero_em_string.size() - 1 - i);
        }
        numero_convertido = somador;
    }
    cout << numero_atual << " b" << base_atual << " ---> " << numero_convertido << " b" << base_convertida << "\n";
}


void base_10_para_base_2(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    digitos.clear();
    int numero_atual_copia = numero_atual;
    while (numero_atual_copia > 0) {
        digitos.push_back(numero_atual_copia % 2);
        numero_atual_copia /= 2;
    }
    cout << numero_atual << " b" << base_atual << " ---> ";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        // Inverte a ordem dos dígitos
        cout << digitos[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_qualquer_para_base_2(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    numero_em_string = to_string(numero_atual);
    for (int i = 0; i < numero_em_string.size(); i++) {
        somador += pow(base_atual, numero_em_string.size() - 1 - i) * (numero_em_string[i] - '0');
    }
    while (somador > 0) {
        digitos.push_back(somador % 2);
        somador /= 2;
    }
    numero_convertido = somador;
    cout << numero_atual << " b" << base_atual << " ---> ";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        // Inverte a ordem dos dígitos
        cout << digitos[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_qualquer_para_base_10(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    numero_em_string = to_string(numero_atual);
    for (int i = 0; i < numero_em_string.size(); i++) {
        somador += pow(base_atual, numero_em_string.size() - 1 - i) * (numero_em_string[i] - '0');
    }
    numero_convertido = somador;
    cout << numero_atual << " b" << base_atual << " ---> " << numero_convertido << " b" << base_convertida << "\n";
}


void base_qualquer_para_base_qualquer(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    numero_em_string = to_string(numero_atual);
    for (int i = 0; i < numero_em_string.size(); i++) {
        somador += pow(base_atual, numero_em_string.size() - 1 - i) * (numero_em_string[i] - '0');
    }
    while (somador > 0) {
        digitos.push_back(somador % base_convertida);
        somador /= base_convertida;
    }
    numero_convertido = somador;
    cout << numero_atual << " b" << base_atual << " ---> ";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        // Inverte a ordem dos dígitos
        cout << digitos[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_10_para_base_qualquer(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    numero_em_string = to_string(numero_atual);
    for (int i = 0; i < numero_em_string.size(); i++) {
        somador += pow(base_atual, numero_em_string.size() - 1 - i) * (numero_em_string[i] - '0');
    }
    while (somador > 0) {
        digitos.push_back(somador % base_convertida);
        somador /= base_convertida;
    }
    numero_convertido = somador;
    cout << numero_atual << " b" << base_atual << " ---> ";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        cout << digitos[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_2_para_base_qualquer(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    numero_em_string = to_string(numero_atual);
    somador = 0;
    for (int i = 0; i < numero_em_string.size(); i++) {
        if (numero_em_string[i] == '1') {
            somador += pow(2, numero_em_string.size() - 1 - i);
        }
    }
    numero_convertido = somador; // Define o número na base 10
    somador = 0;
    // Converte base 10 para a nova base
    while (numero_convertido > 0) {
        digitos.push_back(numero_convertido % base_convertida);
        numero_convertido /= base_convertida;
    }
    cout << numero_atual << " b" << base_atual << " ---> ";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        cout << digitos[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_10_para_base_16(int base_atual, int base_convertida, int numero_atual) {
    auto numero_original = numero_atual;
    string numero_em_string = "";

    while (numero_atual > 0) {
        int resto = numero_atual % 16;
        if (resto > 9) {
            numero_em_string.push_back('A' + (resto - 10)); // Insere no início
        } else {
            numero_em_string.push_back('0' + resto); // Insere no início
        }
        numero_atual /= 16;
    }

    cout << numero_original << " b" << base_atual << " ---> ";
    for (int i = numero_em_string.size() - 1; i >= 0; i--) {
        // Imprime os dígitos na ordem correta
        cout << numero_em_string[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_2_para_base_16(int base_atual, int base_convertida, int numero_atual) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    auto numero_original = numero_convertido;
    numero_em_string = to_string(numero_atual);
    for (int i = numero_em_string.size() - 1; i >= 0; i--) {
        digitos.push_back(numero_em_string[i] - '0');
    }
    for (int i = 0; i < numero_em_string.size(); i++) {
        if (numero_em_string[i] == '1') {
            somador += pow(2, numero_em_string.size() - 1 - i);
        }
        numero_convertido = somador;
        auto numero_original = somador;
    }
    numero_em_string.clear();
    while (numero_convertido > 0) {
        int resto = numero_convertido % 16;
        if (resto > 9) {
            numero_em_string.push_back('A' + (resto - 10));
        } else {
            numero_em_string.push_back('0' + resto);
        }
        numero_convertido /= 16;
    }
    cout << numero_atual << " b" << base_atual << " ---> ";
    for (int i = numero_em_string.size() - 1; i >= 0; i--) {
        cout << numero_em_string[i];
    }
    cout << " b" << base_convertida << "\n";
}


void base_16_para_base_10(int base_atual, int base_convertida, int numero_atual, string numero_atual_string) {
    string numero_em_string;
    vector<int> digitos;
    int numero_convertido, somador = 0;
    //string numero_atual_string;

    for (int i = 0; i < numero_atual_string.size(); i++) {
        char caractere = numero_atual_string[i]; // Pega o caractere original

        int valor = isdigit(caractere)
                        ? caractere - '0' // Se for número (0-9), converte normalmente
                        : caractere - 'A' + 10; // Se for letra (A-F), converte para 10-15

        somador += pow(base_atual, numero_atual_string.size() - 1 - i) * valor;
    }

    numero_convertido = somador;
    cout << numero_atual_string << "b" << base_atual
            << " ---> " << numero_convertido << " b" << base_convertida << "\n";
}


void base_16_para_base_2(int base_atual, int base_convertida, int numero_atual, string numero_atual_string) {
    string numero_em_string;
    int numero_convertido, somador = 0;
    //string numero_atual_string;
    for (int i = 0; i < numero_atual_string.size(); i++) {
        char caractere = numero_atual_string[i]; // Pega o caractere original

        int valor = isdigit(caractere)
                        ? caractere - '0' // Se for número (0-9), converte normalmente
                        : caractere - 'A' + 10; // Se for letra (A-F), converte para 10-15

        somador += pow(base_atual, numero_atual_string.size() - 1 - i) * valor;
    }

    numero_convertido = somador;
    int numero_conertido = numero_convertido;
    vector<int> digitos;

    while (numero_conertido > 0) {
        digitos.push_back(numero_conertido % 2);
        numero_conertido /= 2;
    }
    cout << numero_atual_string << " b" << base_atual << " ---> ";
    for (int i = digitos.size() - 1; i >= 0; i--) {
        // Inverte a ordem dos dígitos
        cout << digitos[i];
    }
    cout << " b" << base_convertida << "\n";
}

void ajuda() {
    ifstream arquivo_ajuda("ajuda.txt");
    string linha;

    if (!arquivo_ajuda) {
        cout << "Erro ao abrir arquivo!";
        return;
    }
    while (getline(arquivo_ajuda, linha)) {
        cout << linha << "\n";
    }
    arquivo_ajuda.close();
}
