#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <stdexcept>
#include <bitset>
#include <sstream>
#include <iomanip>
using namespace std;

int menu();

void conversao();

void conversao_tipo_binario();

void operacao_binaria();

void ajuda();

void documentacao();

void conversao_de_fracao();


void base_para_mesma_base(int base_atual, int base_convertida, int numero_atual);

int base_2_para_base_10(int base_atual, int base_convertida, int numero_atual);

vector<int> base_10_para_base_2_unificado(double numero_atual, int precisao);

vector<int> base_10_para_base_2(int numero_atual);

vector<double> base_10_para_base_2_double(double numero_atual);

void base_qualquer_para_base_2(int base_atual, int base_convertida, int numero_atual);

void base_qualquer_para_base_10(int base_atual, int base_convertida, int numero_atual);

void base_qualquer_para_base_qualquer(int base_atual, int base_convertida, int numero_atual);

void base_10_para_base_qualquer(int base_atual, int base_convertida, int numero_atual);

void base_2_para_base_qualquer(int base_atual, int base_convertida, int numero_atual);

void base_10_para_base_16(int base_atual, int base_convertida, int numero_atual);

void base_2_para_base_16(int base_atual, int base_convertida, int numero_atual);

void base_16_para_base_10(int base_atual, int base_convertida, int numero_atual, string numero_atual_string);

void base_16_para_base_2(int base_atual, int base_convertida, int numero_atual, string numero_atual_string);

void sinal_magnitude(vector<int> &armazenar_SM, int numero_base_10);

vector<int> complemento_de_um(vector<int> &armazenar_C1, int numero_base_10);

vector<int> complemento_de_dois(vector<int> &armazenar_C2, int numero_base_10);

void soma(int operando1, int operando2);

void subtracao(int operando1, int operando2);

void multiplicacao (int operando1, int operando2);

void divisao(int operando1, int operando2);

vector<double> obter_digitos(double numero ,int precisao);

void padronizar_binario(vector<int> &binario, int tamanho_fixo);

void conversao_binario_para_fracao(string fracionario_em_binario);

void conversao_decimal_para_fracao(double fracionario_em_decimal);

double decimal_binario_para_decimal_base10(string fracionario_em_binario);

string doubleParaString(double numero);

int main() {
    int opc_main;
    while (true) {
        opc_main = menu(); //a ação escolhida pelo usuário vai para opc_main
        switch (opc_main) {
            //opc_main em um switch case para acessar a opção que o usuário escolheu
            case 1:
                conversao();
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;

            case 2:
                conversao_tipo_binario();
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;

            case 3:
                conversao_de_fracao();
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;

            case 4:
                operacao_binaria();
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;

            case 5:
                ajuda();
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;
            case 6:
                //documentacao();
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                break;
            case 7:
                cout << "Saindo...\n";
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                return 0;

            default:
                cout << "Opcao invalida!\n";
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                menu();
                break;
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
    cout << "[2] - Conversao tipo de binario.\n";
    cout << "[3] - Conversao de fracao.\n";
    cout << "[4] - Operacao binaria.\n";
    cout << "[5] - Ajuda.\n";
    cout << "[6] - Documentacao\n";
    cout << "[7] - Sair.\n";
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
            base_10_para_base_2(numero_atual);
        } else if (base_convertida == 2 && base_atual != 16) {
            base_qualquer_para_base_2(base_atual, base_convertida, numero_atual);
        } else if (base_atual != 16 && base_convertida == 10) {
            base_qualquer_para_base_10(base_atual, base_convertida, numero_atual);
        } else if (base_atual != 2 && base_atual != 10 && base_convertida != 2 && base_convertida != 10 &&
                   base_convertida != 16) {
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

int base_2_para_base_10(int base_atual, int base_convertida, int numero_atual) {
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
    return numero_convertido;
}

vector<int> base_10_para_base_2(int numero_atual) {
    vector<int> digitos;
    int numero_atual_copia = abs(numero_atual);
    while (numero_atual_copia > 0) {
        digitos.insert(digitos.begin(), numero_atual_copia % 2);
        numero_atual_copia /= 2;
    }
    if (digitos.empty()) {
        digitos.push_back(0);
    }
    return digitos;
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

void conversao_tipo_binario() {
    int numero_base_10;
    vector<int> armazenar_SM;
    vector<int> armazenar_C1;
    vector<int> armazenar_C2;

    cout << "Informe um numero inteiro na base 10: ";
    cin >> numero_base_10;


    armazenar_SM = base_10_para_base_2(numero_base_10);
    armazenar_C1 = base_10_para_base_2(numero_base_10);
    armazenar_C2 = base_10_para_base_2(numero_base_10);
    cout << "Sinal Magnitude: " << endl;
    sinal_magnitude(armazenar_SM, numero_base_10);

    armazenar_C1 = complemento_de_um(armazenar_C1, numero_base_10);
    cout << "Complemento de Um: " << endl;
    for (int bit: armazenar_C1) {
        cout << bit;
    }
    cout << endl;

    armazenar_C2 = complemento_de_dois(armazenar_C2, numero_base_10);
    cout << "Complemento de Dois: " << endl;
    for (int bit: armazenar_C2) {
        cout << bit;
    }
    cout << endl;
}

void padronizar_binario(vector<int> &binario, int tamanho_fixo) {
    while (binario.size() < tamanho_fixo) {
        binario.insert(binario.begin(), 0);
    }
}

void sinal_magnitude(vector<int> &armazenar_SM, int numero_base_10) {
    if (numero_base_10 >= 0) {
        armazenar_SM.insert(armazenar_SM.begin(), 0); // Adiciona bit de sinal positivo
    } else {
        armazenar_SM.insert(armazenar_SM.begin(), 1);
    }
    padronizar_binario(armazenar_SM, 8);

    for (int bit: armazenar_SM) {
        cout << bit;
    }
    cout << endl;
}

vector<int> complemento_de_um(vector<int> &armazenar_C1, int numero_base_10) {
    padronizar_binario(armazenar_C1, 8);
    if (numero_base_10 >= 0) {
        return armazenar_C1;
    } else {
        for (int i = 0; i < armazenar_C1.size(); i++) {
            armazenar_C1[i] = (armazenar_C1[i] == 0) ? 1 : 0;
        }
        return armazenar_C1;
    }
}

vector<int> complemento_de_dois(vector<int> &armazenar_C2, int numero_base_10) {
    armazenar_C2 = complemento_de_um(armazenar_C2, numero_base_10);
    int carry = 1;
    for (int i = armazenar_C2.size() - 1; i >= 0 && carry; i--) {
        if (armazenar_C2[i] == 0) {
            armazenar_C2[i] = 1;
            carry = 0;
        } else {
            armazenar_C2[i] = 0;
        }
    }
    return armazenar_C2;
}

vector<int> intParaVector(int operando);

vector<int> intParaVector(int numero) {
    vector<int> resultado;
    if (numero == 0) {
        resultado.push_back(0);
        return resultado;
    }
    while (numero > 0) {
        resultado.insert(resultado.begin(), numero % 2);
        numero /= 2;
    }
    return resultado;
}

void operacao_binaria() {
    int opc = 0;

    while (opc != 5) {
        cout << "\nInforme a operacao desejada:\n";
        cout << "[1] Soma\n";
        cout << "[2] Subtracao\n";
        cout << "[3] Multiplicacao\n";
        cout << "[4] Divisao\n";
        cout << "[5] Voltar ao menu principal\n";
        cout << "Opcao: ";
        cin >> opc;

        if (opc == 5) {
            cout << "Saindo do menu de operacoes...\n";
            break;
        }

        string binStr1, binStr2;
        cout << "Informe o primeiro operando (em binario): ";
        cin >> binStr1;
        cout << "Informe o segundo operando (em binario): ";
        cin >> binStr2;

        try {
            // Converte strings binárias em inteiros
            int operando1 = stoi(binStr1, nullptr, 2);
            int operando2 = stoi(binStr2, nullptr, 2);

            switch (opc) {
                case 1:
                    cout << "A soma entre " << binStr1 << " b2 e " << binStr2 << " b2 = ";
                    soma(operando1, operando2);
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                    break;
                case 2:
                    cout << "A subtracao entre " << binStr1 << " b2 e " << binStr2 << " b2 = ";
                    subtracao(operando1, operando2);
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                    break;
                case 3:
                    cout << "A multiplicacao entre " << binStr1 << " b2 e " << binStr2 << " b2 = ";
                    multiplicacao(operando1, operando2);
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                    break;
                case 4:
                    cout << "A divisao entre " << binStr1 << " b2 e " << binStr2 << " b2 = ";
                    divisao(operando1, operando2);
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                    break;
                default:
                    cout << "Opcao invalida!\n";
                cout << "Pressione ENTER para continuar...\n";
                cin.ignore();
                cin.get();
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << "Erro: Entrada invalida. Certifique-se de inserir números binários válidos.\n";
        } catch (const out_of_range& e) {
            cout << "Erro: Valor fora do intervalo permitido.\n";
        }
    }
}

void soma(int operando1, int operando2) {
    int resultado = operando1 + operando2;
    cout << bitset<32>(resultado) << " b2 ---> " << resultado << " b10\n";
}

void subtracao(int operando1, int operando2) {
    int resultado = operando1 - operando2;
    if (resultado < 0) {
        cout << "Resultado negativo: ";
    }
    cout << bitset<32>(resultado) << " b2 ---> " << resultado << " b10\n";
}

void multiplicacao(int operando1, int operando2) {
    int resultado = operando1 * operando2;
    cout << bitset<32>(resultado) << " b2 ---> " << resultado << " b10\n";
}

void divisao(int operando1, int operando2) {
    vector<int> divisao_em_vector;

    // Verifica se a divisão é válida
    if (operando2 == 0) {
        cout << "Erro: Divisão por zero não é permitida.\n";
        return;
    }

    double resultado = static_cast<double>(operando1) / operando2; // Calcula o quociente em formato double
    int parte_inteira = static_cast<int>(resultado); // Parte inteira do quociente
    double parte_decimal = resultado - parte_inteira; // Parte decimal do quociente

    // Converte a parte inteira para binário
    divisao_em_vector = base_10_para_base_2(parte_inteira);

    // Converte a parte decimal para binário
    vector<double> parte_decimal_vector = base_10_para_base_2_double(parte_decimal);

    // Exibe os resultados
    cout << "A divisao entre " << bitset<3>(operando1) << " b2 e " << bitset<3>(operando2) << " b2 e igual a: \n";
    cout << "Parte inteira: ";
    for (int bit : divisao_em_vector) {
        cout << bit;
    }
    cout << " b2 ---> " << parte_inteira << " b10\n";

    cout << "Parte decimal: ";
    for (double bit : parte_decimal_vector) {
        cout << bit;
    }
    cout << " b2 ---> " << parte_decimal << " b10\n";
}

vector<double> base_10_para_base_2_double(double numero_atual) {
    int parte_inteira = static_cast<int>(numero_atual);
    double parte_decimal = numero_atual - parte_inteira;

    // Parte decimal em binário
    vector<double> parte_decimal_vector = obter_digitos(parte_decimal, 10);
    return parte_decimal_vector;
}

vector<double> obter_digitos(double parte_decimal, int precisao) {
    vector<double> digitos_binarios;

    while (parte_decimal > 0 && precisao > 0) {
        parte_decimal *= 2;
        if (parte_decimal >= 1) {
            digitos_binarios.push_back(1);
            parte_decimal -= 1;
        } else {
            digitos_binarios.push_back(0);
        }
        precisao--;
    }

    return digitos_binarios;
}

vector<int> base_10_para_base_2_unificado(double numero_atual, int precisao = 10) {
    int parte_inteira = static_cast<int>(numero_atual);
    double parte_decimal = numero_atual - parte_inteira;

    // Converte a parte inteira para binário
    vector<int> resultado = base_10_para_base_2(parte_inteira);

    // Adiciona um separador lógico (representando o ponto decimal, por exemplo -1)
    resultado.push_back(-1);

    // Converte a parte decimal para binário
    vector<int> parte_decimal_vector;
    vector<double> parte_decimal_double = obter_digitos(parte_decimal, precisao);
    for (double bit : parte_decimal_double) {
        parte_decimal_vector.push_back(static_cast<int>(bit));
    }

    resultado.insert(resultado.end(), parte_decimal_vector.begin(), parte_decimal_vector.end());
    return resultado;
}

void conversao_de_fracao() {
    int opc;
    double fracionario_em_decimal;
    string fracionario_em_binario_string;

    cout << "Escolha qual o tipo da conversao de fracao: " << endl;
    cout << "[1] - binario para decimal." << endl;
    cout << "[2] - decimal para binario." << endl;
    cin >> opc;

    if (opc == 1) {
        cout << "Informe o numero fracionario (em binario): " << endl;
        cin >> fracionario_em_binario_string;
        conversao_binario_para_fracao(fracionario_em_binario_string);
    } else {
        cout << "Informe o numero fracionario (em decimal): " << endl;
        cin >> fracionario_em_decimal;
        conversao_decimal_para_fracao(fracionario_em_decimal);
    }
}

void conversao_binario_para_fracao(string fracionario_em_binario) {
    size_t pos_ponto = fracionario_em_binario.find('.');
    string parte_inteira_str = fracionario_em_binario.substr(0, pos_ponto);
    int parte_inteira = stoi(parte_inteira_str);
    parte_inteira = base_2_para_base_10(2, 10, parte_inteira);

    double parte_decimal = decimal_binario_para_decimal_base10(fracionario_em_binario);

    double resultado_final = parte_inteira + parte_decimal;
    cout << "O numero " << fracionario_em_binario << " em decimal eh " << resultado_final << endl;
}

double decimal_binario_para_decimal_base10(string fracionario_em_binario) {
    vector<int> valores_decimal;
    double resultado = 0.0;

    size_t pos_ponto = fracionario_em_binario.find('.');
    if (pos_ponto != string::npos) {
        for (size_t i = pos_ponto + 1; i < fracionario_em_binario.size(); ++i) {
            if (fracionario_em_binario[i] == '1' || fracionario_em_binario[i] == '0') {
                valores_decimal.push_back(fracionario_em_binario[i] - '0');
            }
        }
    }

    for (size_t i = 0; i < valores_decimal.size(); ++i) {
        resultado += valores_decimal[i] * pow(2, -(static_cast<int>(i) + 1));
    }

    return resultado;
}

string doubleParaString(double numero) {
    ostringstream conversor;
    conversor << fixed << setprecision(20) << numero;
    return conversor.str();
}

void conversao_decimal_para_fracao(double fracionario_em_decimal) {
    int parte_inteira = static_cast<int>(fracionario_em_decimal);
    double parte_fracionaria = fracionario_em_decimal - parte_inteira;

    string binario_inteiro = "";
    string binario_fracionario = "";

    // Parte inteira
    if (parte_inteira == 0) {
        binario_inteiro = "0";
    } else {
        while (parte_inteira > 0) {
            binario_inteiro = to_string(parte_inteira % 2) + binario_inteiro;
            parte_inteira /= 2;
        }
    }

    // Parte fracionária (limite de 10 dígitos)
    int limite = 10;
    while (parte_fracionaria > 0 && limite > 0) {
        parte_fracionaria *= 2;
        int bit = static_cast<int>(parte_fracionaria);
        binario_fracionario += to_string(bit);
        parte_fracionaria -= bit;
        limite--;
    }

    cout << "O numero em binario eh: " << binario_inteiro;
    if (!binario_fracionario.empty()) {
        cout << "." << binario_fracionario;
    }
    cout << endl;
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
