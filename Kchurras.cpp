/* 
    Título: Kchurras  
    Descrição: Um programa de terminal que te ajuda a calcular o preço de um churrasco, com ajuda de uma pequena IA
    que vai lhe ajudar a tomar as deciosões corretas para acertar no churrasco.
    Versão: 1.2.0
    Autor: Kevin Rodrigues de Souza
*/
#include <iostream>
using namespace std;

/* CONSTANTES DE CONSUMO PARA CONFIGURAÇÃO DO PROGRAMA */
#define PORCENTAGEM_DE_GUARNICAO_E_UTENCILIOS .2 // O quanto em porcentagem representa a guarnição em um churrasco e custos com descartáveis e outros.

// Gramas de carne por pessoa
#define GRAMAS_DE_CARNE_POR_HOMEM 500 // g de carne por homem
#define GRAMAS_DE_CARNE_POR_MULHER 400 // g de carne por mulher
#define GRAMAS_DE_CARNE_POR_CRIANCAS 200 // g de carne por criança

// ml de Bebida por pessoa
#define ML_CERVEJA_HOMENS 2500 // ml
#define ML_CERVEJA_MULHERES  2000 //  ml
#define ML_REFRI_CRIANCAS 600 // ml

// Quantidade de carvão em kg por pessoa 
#define KG_CARVAO_POR_PESSOA .5

/* =================================================== */

/* CONSTANTES DOS PREÇOS DOS PRODUTOS */
const float PRECO_CARNE_KILO = 34.80;
const float PRECO_CERVEJA_ML = 0.008733;  
const float PRECO_REFRI_ML = 0.003727;
const float PRECO_GUARNICAO_KG = 6.00;

const float PRECO_LINGUICA_KILO = 20.90;
const float PRECO_ASA_KILO = 16.39;
const float PRECO_CARVAO_KG = 6.58;

/* =================================== */

/* 
    Fonte dos valores: https://www.sociedadedacarne.com.br/blog/como-calcular-quantidade-de-carne-para-churrasco/
    Fonte dos preços: https://www.casafriburgo.com.br/ , acessado em 06/07/21 as 8h
    Fonte da quantidade de carvão: https://gshow.globo.com/tv/noticia/aprenda-como-acender-uma-churrasqueira-e-a-preparar-a-brasa-perfeita-para-o-seu-churrasco.ghtml
    "Mas de forma geral pode-se dizer que para um churrasco preparado para dez pessoas, um saco de carvão de 5 kg de boa qualidade é suficiente."

    Contra File Friboi kg -> 34,80
    Cerveja Brahma Chopp 355 Ml Long Neck -> 3,10 355ml
    Guarana Antarctica 1,5L -> 5,59
    Arroz Fighera 2kg Tp1 -> 11,99

    Linguica Sadia Churrasco 500G -> 10,45 500g
    Asa De Frango KG -> 16,39 Kg     
 
    Carvão Bianor 5Kg -> 32,90 und

*/

/* CONSTANTES DE IA
Essas constantes serão usadas pra interagir com o programa fornecendo uma Inteligência Artificial primitiva
*/
const int IAMuitasPessoas = 15; // Número que represente uma quantidade dita como 'muitas pessoas'
const float IAPercentMuitosBebem = .6; // Porcentagem para se considerar que 'muitos bebem', De 0.0 - 1.0, não incluso crianças.
/* ================= */

/* Prototypes de funções */

int input(string text);
int inputPositive(string text);
char toLower(char c);

/* ===================== */

int main()
{
    // Cabeçalho do programa
    cout << " ========== Bem vindo ao Kchurras ============ " << endl;
    cout << "@:)Vou lhe ajudar a calcular o seu churrasco" << endl;
    cout << "@:) Ok, Vamos la. Primeiramente, me conte um pouco sobre os participante..." << endl;

    // 1.0 Coleta de dados do usuário
    int totalHomens= 0, totalMulheres = 0, totalCriancas = 0;
    
    // #Verificar se somente há criacaças,  caso sim exigir que um adulto esteja presente;
    do {
        cout << "Participantes: \n";
        totalHomens = inputPositive("\t Homens : ");
        totalMulheres = inputPositive("\t Mulheres: ");
        totalCriancas = inputPositive("\t Crianças: ");

        if (totalMulheres + totalHomens == 0 && totalCriancas > 0)
        {
            cout << "@:< Segundo as regras, as crianças nao podem ir sozinhas ao churrasco, por favor, reveja os participantes." << endl; 
        }
    } while (totalMulheres+ totalHomens == 0 && totalCriancas > 0);

    // #ia Com base na quantidade fazer um interação diferente
    int totalParticipante = totalHomens + totalMulheres + totalCriancas; // Total de pessoas que participam do churrasco
    if(totalParticipante >= IAMuitasPessoas)
        cout << "@:) Heheh que beleza, a festa vai ser grande hein!\n\n";
    else if (totalParticipante > 0)
        cout << "@:) Um churraquinho cai bem.\n\n";
    else
    {
        cout << "@:( Ora, nao vai ter churrasco?\n";
        cout << "@:) Quando precisar de mim, basta me chamar, voce sabe onde me encontrar.\n\n";
        return 0;
    }
    
    // 1.1 Coleta de dados do usuário, um pouco mais...
    cout << "@:) Ta certo, ta certo, que tal mais detalhes... " << endl;
    
    
    /* #ia somente perguntar sobre determinado tipo de pessoa se esta estiver presente
    Ex: não perguntar sobre mulheres se elas não forem */
    
    int totalHomensQueBebem = -1;
    int totalMulheresQueBebem = -1;

    if (totalHomens > 0)
    {
        cout << "Dos Homens, quantos bebem cerveja? : \n";
        // verificar se a quantidade que bebe é menor ou igual ao total de homens
        do {
            totalHomensQueBebem = inputPositive("\tHomens que bebem: ");
            if(totalHomensQueBebem > totalHomens)
                cout << "\t@:| Nao entendi muito bem, voce colocou uma valor maior do que a quantidade de homens\n";
        }
        while(totalHomensQueBebem < 0 || totalHomensQueBebem > totalHomens);
    }

    if (totalMulheres > 0)
    {
        cout << "Das Mulheres, quantas bebem cerveja? : \n";
        // verificar se a quantidade que bebe é menor ou igual ao total de homens
        do {
            totalMulheresQueBebem = inputPositive("\tMulheres que bebem: ");
             if(totalMulheresQueBebem > totalMulheres || totalHomensQueBebem < 0 )
                cout << "\t@:| Nao entendi muito bem, voce colocou uma valor maior do que a quantidade de mulheres\n";
        }
        while(totalMulheresQueBebem < 0 || totalMulheresQueBebem > totalMulheres);
    }


    /* #ia com base na quantidade fazer um interação diferente
     dependendo da quantidade de pessoas que bebem, tipo + de 60%, falar 
     Uau, já sei que cerveja não pode faltar! Hehe. */
    // Aqui pode ocorrer uma divisão por zero
    if((totalHomensQueBebem + totalMulheresQueBebem) > 0 && totalParticipante-totalCriancas/(totalHomensQueBebem + totalMulheresQueBebem) >= IAPercentMuitosBebem)
    {
        cout << "@;) Uau, ja sei que cerveja nao pode faltar! Hehe.\n";
    }
    
    
    // 2.0 Quem vai pagar a conta
    /* 
        Essa parte é a responsável por determinar quem pagará a conta, com tantas formas distintas para pagar a conta
        vamos ver como a ia pode nos ajudar.
    */

    bool homensPagam = false, mulheresPagam = false, criacasPagam = false;
    int quemPagaAConta = -1; // 0-Homens|1-Mulheres| 2-Homens Mulheres/2 | 3-Homens/2 mulheres | 4- Homens, mulheres crianca/2 | 5 - homens criancas/2 | 6 mulheres criancas/2 | 7 homem e mulher | 8 mulheres h/2 c/2 | 9 homens m/2 c/2
    // 2.1 Quem vai pagar a conta - Coleta de dados
    // Repete até que algum adulto esteja disposto a pagar a conta
    while (!homensPagam && !mulheresPagam)
    {
        cout << "@:) Ok, agora me diz, quem vai pagar a conta? " << endl;
        char resposta; // variavel para guardar temporariamente as respostas as perguntas
        
        // homens pagam
        if (totalHomens > 0)
        {
            cout << "@:> Os homens pagam? (s/n): ";
            do
            {
                cin >> resposta;
                resposta = toLower(resposta);
                if (resposta != 's' && resposta != 'n')
                {
                    cout << "\tUse apenas 's' ou 'n'. Tente novamente.\n";
                    cout << "@:> Os homens pagam? (s/n): ";
                }

            } while (resposta != 's' && resposta != 'n');

            homensPagam = (resposta == 's') ? true : false; // se a resposta for 's', as criancas pagam, caso contrario nao
        }

        // mulheres pagam
        if (totalMulheres > 0)
        {
            cout << "@:> As mulheres pagam? (s/n): ";
            do
            {
                cin >> resposta;
                resposta = toLower(resposta);
                if (resposta != 's' && resposta != 'n')
                {
                    cout << "\tUse apenas 's' ou 'n'. Tente novamente.\n";
                    cout << "@:> As mulheres pagam? (s/n): ";
                }

            } while (resposta != 's' && resposta != 'n');

            mulheresPagam = (resposta == 's') ? true : false; // se a resposta for 's', as criancas pagam, caso contrario nao
        }

        // criancas pagam somente se um adulto for pagar
        if (totalCriancas > 0 && (homensPagam || mulheresPagam))
        {
            cout << "@:> As criacas pagam? (s/n): ";
            do
            {
                cin >> resposta;
                resposta = toLower(resposta);
                if (resposta != 's' && resposta != 'n')
                {
                    cout << "\tUse apenas 's' ou 'n'. Tente novamente.\n";
                    cout << "@:> As criacas pagam? (s/n): ";
                }

            } while (resposta != 's' && resposta != 'n');

            criacasPagam = (resposta == 's') ? true : false; // se a resposta for 's', as criancas pagam, caso contrario nao
        }

        // 2.2 Quem vai pagar a conta - Análise de possibilidades

        if (homensPagam && !mulheresPagam)
        {
            if (criacasPagam)
            {
                cout << "\n@;) Os cavalheiros pagam inteira e as criancas pagam meia.\n";
                quemPagaAConta = 5;
            }
            else
            {
                cout << "\n@;) Deixe a conta com os cavalheiros. ";
                quemPagaAConta = 0;
            }
        }
        else if (!homensPagam && mulheresPagam)
        {
            if (criacasPagam)
            {
                cout << "\n@;) As damas pagam inteira e as criancas pagam meia.\n";
                quemPagaAConta = 6;
            }
            else
            {
                cout << "\n@;) Deixe a conta com as damas.\n";
                quemPagaAConta = 1;
            }
        }
        else if (homensPagam && mulheresPagam)
        {
            cout << "\n@;) Vamos dividir essa conta.\n";
            resposta = 'a'; // seta para um valor inválido;

            cout << "Quem paga meia, Homens(h), Mulheres(m) ou  Nenhum dos dois(n)? (h/m/n): ";
            do
            {
                cin >> resposta;
                resposta = toLower(resposta);
                if (resposta != 'h' && resposta != 'm' && resposta != 'n')
                {
                    cout << "\tUse apenas 'h', 'm', 'n'. Tente novamente.\n";
                    cout << "Quem paga meia, Homens(h), Mulheres(m) ou  Nenhum dos dois(n)? (h/m/n): ";
                }

            } while (resposta != 'h' && resposta != 'm' && resposta != 'n' );

            if (resposta == 'h')
            {
            
                if (criacasPagam)
                {
                    cout << "\n@;) Mulheres pagam inteira e homens e criancas pagam meia. ";
                    quemPagaAConta = 8;
                }
                else
                {
                    cout << "\n@;) Mulheres pagam inteira e homens pagam meia. ";
                    quemPagaAConta = 3;
                }


            }
            else if (resposta == 'm')
            {
                if (criacasPagam)
                {
                    cout << "\n@;) Homens pagam inteira e mulheres e criancas pagam meia. ";
                    quemPagaAConta = 9;
                }
                else
                {
                    cout << "\n@;) Homens pagam inteira e mulheres pagam meia. ";
                    quemPagaAConta = 2;
                }
            }
            else
            {
                if (criacasPagam)
                {
                    cout << "\n@;) Criancas pagam meia.\n";
                    quemPagaAConta = 4;
                }
                else
                {
                    cout << "\n@;) Somente homens e mulheres pagam.\n";
                    quemPagaAConta = 7;

                }
            }

        }
        else
            cout << "\n@:? Vamos la, nada sai de graca.\n";
    }

    // 3.0 - Calculando as Despesas
    /* 
        Como funciona o cálculo das quantidade de alimentos e bebidas:
            Alimentos:
                100% Churrasco = PORCENTAGEM_DE_GUARNICAO_E_UTENCILIOS + O restante. Ex: 0.2 + 0.8;
                Dos 100 do churrasco, ou .8 do total de carnes, temos:
                    100 % de carnes = .6 carne, .2 asa , 2. linguiça
            Bebidas:
                Multiplicação dos ml por pessoas * total de pessoas que bebem, incluindo as criancas com o refri.

            Carvão:
                KG_CARVAO_POR_PESSOA * totalParticipante 
    */
   
    // 3.1 Calculo da quantidade de alimentos e bebidas

    float totalCarneKg = (GRAMAS_DE_CARNE_POR_HOMEM * totalHomens + GRAMAS_DE_CARNE_POR_MULHER * totalMulheres + GRAMAS_DE_CARNE_POR_CRIANCAS * totalCriancas)/1000; // valor em Kg
    float totalCervejaMl = ML_CERVEJA_HOMENS * totalHomensQueBebem + ML_CERVEJA_MULHERES * totalMulheres;
    float totalRefriMl = ML_REFRI_CRIANCAS * totalCriancas;
    float totalCarvao = KG_CARVAO_POR_PESSOA * totalParticipante; // valor em Kg

    float totalGuarnicao = (totalCarneKg * PORCENTAGEM_DE_GUARNICAO_E_UTENCILIOS); // valor em Kg
    totalCarneKg = totalCarneKg * (1-PORCENTAGEM_DE_GUARNICAO_E_UTENCILIOS);

    float totalAsa = totalCarneKg * .2; // valor em Kg
    float totalLinguica = totalCarneKg * .2; // valor em Kg
    totalCarneKg = totalCarneKg * .6;

    // POG - Gambiarra para desenvolvimento, para testar única funcionalidade com ooção de liga e desliga.
    if (true)
    {
        cout << "\n ===== Resumo da Quantidade de Alimentos e Bebidas =====" << endl;
        cout << "\tTotal de Alimentos...: " << totalCarneKg + totalAsa + totalLinguica << "Kg." << endl;
        cout << "\tTotal de Carne.......: " << totalCarneKg << "Kg."<< endl;
        cout << "\tTotal de Asa.........: " << totalAsa << "Kg."<< endl;
        cout << "\tTotal de Linguica....: " << totalLinguica << "Kg."<< endl;
        

        cout << "\tTotal de Guarnicao...: " << totalGuarnicao << "Kg."<< endl;
        cout << "\tTotal de Carvao......: " << totalCarvao << "kg."<< endl;

        cout << "\tTotal de Cerveja.....: " << totalCervejaMl << "ml."<< endl;
        cout << "\tTotal de Refrigerante: " << totalRefriMl/1000 << "l."<< endl;
    }

    // 3.2 Calculo dos preços dos alimentos e beibidas
    // POG - Gambiarra para desenvolvimento, para testar única funcionalidade com ooção de liga e desliga.

    double totalGeral = 0;
    if (true)
    {
        cout << "\n ===== Resumo dos precos de Alimentos e Bebidas =====" << endl;
        cout << "\t Valor Alimentos...: R$" << (totalCarneKg * PRECO_CARNE_KILO + totalAsa * PRECO_ASA_KILO + totalLinguica * PRECO_LINGUICA_KILO) << "(Kg)." << endl;
        totalGeral = (totalCarneKg * PRECO_CARNE_KILO + totalAsa * PRECO_ASA_KILO + totalLinguica * PRECO_LINGUICA_KILO);
        
        cout << "\t Valor Carne.......: R$" << totalCarneKg * PRECO_CARNE_KILO << endl;
        cout << "\t Valor Asa.........: R$" << totalAsa * PRECO_ASA_KILO << "(kg)."<< endl;
        cout << "\t Valor Linguica....: R$" << totalLinguica * PRECO_LINGUICA_KILO << "(kg)."<< endl;
        

        cout << "\t Valor Guarnicao...: R$" <<  totalGuarnicao * PRECO_GUARNICAO_KG << "(kg)."<< endl;
        totalGeral += (totalGuarnicao * PRECO_GUARNICAO_KG);
        cout << "\t Valor Carvao......: R$" << (totalCarvao * PRECO_CARVAO_KG)  << "(kg)."<< endl;
        totalGeral += (totalCarvao * PRECO_CARVAO_KG);
        cout << "\t Valor Cerveja.....: R$" << (totalCervejaMl * PRECO_CERVEJA_ML) << "(ml)."<< endl;
        totalGeral += (totalCervejaMl * PRECO_CERVEJA_ML);
        cout << "\t Valor Refrigerante: R$" <<  (totalRefriMl * PRECO_REFRI_ML) << "(ml)."<< endl;
        totalGeral += (totalRefriMl * PRECO_REFRI_ML);

        printf("\t Valor Total.......: R$ %.2f\n", totalGeral);
    }

    // 3.3 Divisão da conta entre os pagantes

    float precoHomem = 0, precoMulher = 0, precoCrianca = 0; 
    cout << "\n==== Preco do churrasco ====\n";
    if (quemPagaAConta == 0)
        precoHomem = totalGeral/totalHomens;
    else if (quemPagaAConta == 1)
        precoMulher = totalGeral/totalMulheres;
    else if (quemPagaAConta == 2)
    {
        // Homem * inteira + mulher * (inteira/2) = totalGeral 
        float inteira = totalGeral/(totalHomens + totalMulheres/2.0 );
        precoMulher = inteira/2;
        precoHomem = inteira;

    }

    // mulher * inteira + homem * (inteira/2) = totalGeral 
    else if (quemPagaAConta == 3)
    {
        float inteira = totalGeral/(totalMulheres + totalHomens/2.0 );

        precoMulher = inteira;
        precoHomem = inteira/2;

    }
    // mulher * inteira + homem * inteira + criancas * (inteira/2) = totalGeral 
    else if (quemPagaAConta == 4)
    {
        float inteira = totalGeral/(totalMulheres + totalHomens + totalCriancas/2.0 );

        precoMulher = inteira;
        precoHomem = inteira;
        precoCrianca = inteira/2;
    }
    // homens * inteira + criancas * (inteira/2) = totalGeral 
    else if (quemPagaAConta == 5)
    {
        float inteira = totalGeral/( totalHomens + totalCriancas/2.0 );

        precoHomem = inteira;
        precoCrianca = inteira/2;

    }
    // mulheres * inteira + criancas * (inteira/2) = totalGeral 
    else if (quemPagaAConta == 6)
    {
        float inteira = totalGeral/( totalMulheres + totalCriancas/2.0 );

        precoMulher = inteira;
        precoCrianca = inteira/2;
    }
    // mulheres * inteira + criancas * (inteira/2) = totalGeral 
    else if (quemPagaAConta == 7)
    {
        float inteira = totalGeral/( totalMulheres + totalMulheres);
        precoMulher = inteira;
        precoHomem = precoMulher;

    }
    // mulheres * inteira + criancas * (inteira/2) + homens * (inteira/2)  = totalGeral 
    else if (quemPagaAConta == 8)
    {
        float inteira = totalGeral/( totalMulheres + (totalHomens+totalCriancas)/2.0);

        precoMulher = inteira;
        precoHomem = inteira/2;
        precoCrianca = precoHomem;

    }
    // homens * inteira + criancas * (inteira/2) + mulheres * (inteira/2)  = totalGeral 
    else if (quemPagaAConta == 9)
    {
        float inteira = totalGeral/( totalHomens + (totalMulheres+totalCriancas)/2.0);

        precoMulher = inteira/2;
        precoHomem = inteira;
        precoCrianca = precoMulher;
    }

    printf("Homens.....:R$ %.2f\n",precoHomem);
    printf("Mulheres...:R$ %.2f\n",precoMulher);
    printf("Criancas...:R$ %.2f\n",precoCrianca);

    return 0;
}


/* Implementação das funções */
/** 
*    Escreve na tela o text e retorna o int respondido no terminal
*/
int input(string text)
{
    cout << text;
    int tmp;
    cin >>tmp;
    return tmp;
}
/** 
*    Escreve na tela o text e retorna o int respondido no terminal somente se for >=0
*/
int inputPositive(string text)
{
    int tmp = -1;

    cout << text;
    cin >>tmp;

    while (tmp < 0)
    { 
        cout << "\t Digite um valor maior ou igual a zero. Tente novamente.\n";
        cout << text;
        cin >>tmp;
    }
   
    return tmp;
}
/* Converta para letra minúscula caso seja maiúscula, base nos conhecimentos da tabela ASCII */
char toLower(char c)
{
    if (c >= 65 && c <= 90)
        return c+32;
    return c;
}
/* ===================== */
