/*
 * Programa: ex11.c
 * Descrição: Estou criando um sistema PDV, como se o terminal fosse uma maquina resgistradora e de cartao ao mesmo tempo,
 * a qual faz controle de 'estoque de cedulas' e registra todas as vendas para um relatorio final.
 * Autor: Leonardo Trevisol
 * Data de criação: 22.09.2024
 * Última modificação: 22.09.2024
 *
 * Observações:
 *  COISAS A FAZER:
 * - acrescentar os centavos;
 * - vincular as cedulas usadas de troco para dimiuir no estoque de cedulas;
 * - terminar os medotos debito,credito,e vale;
 * - criar o relatorio parcial e final(fechamento).
 * - ...
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculoDeTroco(float valorConta);
int *abrirCaixa(int cedulas);

int main()
{
    char logUser[30], logPassword[30];
    int count = 1;

    printf("\nBem vindo ao PDV do Lele.\n\nDigite login e senha.\n");

    while (count)
    {
        printf("LOGIN:");
        if (fgets(logUser, sizeof(logUser), stdin) != NULL)
        {
            logUser[strcspn(logUser, "\n")] = '\0';

            if (strcmp(logUser, "0") != 0)
            {
                printf("Login errado!Tente novamente\n");
            }
            else
            {
                count = 0;
            }
        }
        else
        {
            printf("ERRO na leitura!\n");
        }
    }
    count = 1;
    while (count)
    {
        printf("SENHA:");
        if (fgets(logPassword, sizeof(logPassword), stdin) != NULL)
        {
            logPassword[strcspn(logPassword, "\n")] = '\0';

            if (strcmp(logPassword, "0") != 0)
            {
                printf("Senha errada!Tente novamente\n");
            }
            else
            {
                count = 0;
            }
        }
        else
        {
            printf("ERRO na leitura!\n");
        }
    }

    int menuActions;
    count = 1;
    int yesOrNo, qntCedulas = 8;
    int valorDeCedulas[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int *vetorCedulas;
    float valorTotal = 0.0;
    float valorPorCedulas[qntCedulas];

    while (count)
    {
        int verificadorDeAbertura;
        int count2 = 1;
        int menuActions2, yesOrNo2, formaDePagamento;
        float valorDeVenda;
        printf("\nMENU INICIAL:\n 1.Abrir Caixa\n 2.Acessar caixa\n 3.Fechamento\n 4.Sair\n");
        scanf("%d", &menuActions);

        switch (menuActions)
        {
        case 1:
            if (verificadorDeAbertura == 0)
            {
                printf("Caixa ja foi aberto!\n\n");
                break;
            }
            vetorCedulas = abrirCaixa(qntCedulas);

            if (vetorCedulas != NULL)
            {
                printf("CAIXA ABERTO COM SUCESSO!\n\n");
                valorTotal = 0.0;
                for (int i = 0; i < qntCedulas; i++)
                {
                    valorPorCedulas[i] = valorDeCedulas[i] * vetorCedulas[i];
                    valorTotal += valorPorCedulas[i];
                    printf("Valor em R$%d,00: R$%.2f\n", valorDeCedulas[i], valorPorCedulas[i]);
                }
            }
            else
            {
                printf("Falha ao abrir a caixa.\n");
            }

            printf("TOTAL EM CAIXA: R$%.2f\nFIM.\n\n", valorTotal);
            verificadorDeAbertura = 0;
            break;
        case 2:
            while (count2)
            {
                printf("\n2.CAIXA:\n\n1.Vender\n2.Relatorio Parcial\n3.Sair\n");
                scanf("%d", &menuActions2);
                switch (menuActions2)
                {
                case 1:
                    printf("Valor total da venda: R$");
                    scanf("%f", &valorDeVenda);
                    printf("\nForma de pagamento:\n1.Dinheiro\n2.Debito\n3.Credito\n4.Vale-refeicao\n\n");
                    scanf("%d", &formaDePagamento);
                    if (formaDePagamento == 1)
                    {
                        calculoDeTroco(valorDeVenda);
                    }

                    break;
                case 2:
                    /* code */
                    break;
                case 3:
                    printf("Tem certeza que deseja sair?\n1.SIM\n2.NAO\n");
                    scanf("%d", &yesOrNo2);
                    if (yesOrNo2 == 1)
                    {
                        printf("\n");
                        count2 = 0;
                    }
                    break;

                default:
                    break;
                }
            }

            break;
        case 3:

            break;
        case 4:
            printf("Tem certeza que deseja sair?\n1.SIM\n2.NAO\n");
            scanf("%d", &yesOrNo);
            if (yesOrNo == 1)
            {
                printf("FIM! Obrigado por usar nosso(meu) sistema!\n");
                count = 0;
            }
            break;
        default:
            break;
        }
    }
    printf("GG");

    return 0;
}

int *abrirCaixa(int cedulas)
{
    int *vetorCedulas = (int *)malloc(cedulas * sizeof(int));
    if (vetorCedulas == NULL)
    {
        printf("ERRO de alocacao!\n");
        return NULL;
    }

    int valorCedulas[] = {1, 2, 5, 10, 20, 50, 100, 200};

    for (int i = 0; i < cedulas; i++)
    {
        printf("Digite a quantidade de cedulas de R$%d,00:", valorCedulas[i]);
        scanf("%d", &vetorCedulas[i]);
    }
    return vetorCedulas;
}

void calculoDeTroco(float valorConta)
{
    int qntDeCedulas;
    float valorBruto, valorTroco;
    printf("Digite o valor fornecido pelo cliente: R$");
    scanf("%f", &valorBruto);

    valorTroco = valorBruto - valorConta;

    if (valorTroco < 0)
    {
        printf("Valor fornecido eh menor que o valor da conta.\n");
    }
    else
    {

        printf("O troco eh de R$%.2f.\n", valorTroco);

        qntDeCedulas = valorTroco / 100;
        valorTroco = valorTroco - (qntDeCedulas * 100);

        printf("%d notas de R$100.\n", qntDeCedulas);

        qntDeCedulas = valorTroco / 50;
        valorTroco = valorTroco - (qntDeCedulas * 50);
        printf("%d notas de R$50.\n", qntDeCedulas);

        qntDeCedulas = valorTroco / 20;
        valorTroco = valorTroco - (qntDeCedulas * 20);
        printf("%d notas de R$20.\n", qntDeCedulas);

        qntDeCedulas = valorTroco / 10;
        valorTroco = valorTroco - (qntDeCedulas * 10);
        printf("%d notas de R$10.\n", qntDeCedulas);

        qntDeCedulas = valorTroco / 5;
        valorTroco = valorTroco - (qntDeCedulas * 5);
        printf("%d notas de R$5.\n", qntDeCedulas);

        qntDeCedulas = valorTroco / 2;
        valorTroco = valorTroco - (qntDeCedulas * 2);
        printf("%d notas de R$2.\n", qntDeCedulas);

        qntDeCedulas = valorTroco;
        printf("%d moedas de R$1.\n", qntDeCedulas);
    }
}
