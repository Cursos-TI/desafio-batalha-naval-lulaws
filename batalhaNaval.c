// INÍCIO DO COMENTÁRIO ORIGINAL NO ARQUIVO
//#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

//int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

//    return 0;
//}
// FIM DO COMENTÁRIO ORIGINAL

// INÍCIO DO CÓDIGO
#include <stdio.h>

// protótipo de função recursiva
void mostrarTab(int tab[10][10], int linha);

int main() {
	
	int tabuleiro[10][10] = {0}; // declarando o tabuleiro, já cheio de 0s
	int navio1=2,navio2=3,navio3=4,navio4=5;
	
	// os navios estão numerados no campo no formato i + 1, para ajudar na identificação visual
	// navio4=navio3=navio1=navio2; // a função comentada à esquerda faria todos usarem 3
	
	// todos os navios serão orientados nos comentários iniciando pela parte superior esquerda
	// sendo então de cima para baixo e da esquerda para a direita
	
	// as posições dos navios são descritas abaixo:
	
	// Navio 1 (linha 2, coluna 4, 3 casas na vertical)
	tabuleiro[1][3]=navio1;
	tabuleiro[2][3]=navio1;
	tabuleiro[3][3]=navio1;
	
	// Navio 2 (linha 1, coluna 1, 4 casas na horizontal)
	tabuleiro[0][0]=navio2;
	tabuleiro[0][1]=navio2;
	tabuleiro[0][2]=navio2;
	tabuleiro[0][3]=navio2;
	
	// Navio 3 (linha 5, coluna 2, 4 casas rumo à diagonal inferior direita)
	tabuleiro[4][1]=navio3;
	tabuleiro[5][2]=navio3;
	tabuleiro[6][3]=navio3;
	tabuleiro[7][4]=navio3;
	
	// Navio 4 (linha 7, coluna 8, 3 casas rumo à diagonal inferior esquerda)
	tabuleiro[6][7]=navio4;
	tabuleiro[7][8]=navio4;
	tabuleiro[8][9]=navio4;
	
	// decidi tornar a exibição do tabuleiro em função recursiva
	mostrarTab(tabuleiro,0); // formato (tabuleiro[i][j],linha)
	
	return 0;
}

// função recursiva para mostrar o tabuleiro
void mostrarTab(int tab[10][10],int linha) {
	
	char coluna[10];
	for (int i = 0;i<10;i++) {
		coluna[i]='A'+i; // populando as colunas com A até J
	}
	
	// letras das colunas
	if (linha==0){
		printf("\t"); // usando espaçamento tabulado
		for(int hor = 0;hor<10;hor++){
			printf("%c\t",coluna[hor]);
		}
		printf("\n\n\n");
	}
	
	// número das linhas
	printf("%2d\t",linha+1); // modificador 2 no %d para garantir espaço para 2 caracteres
	
	// linha do tabuleiro
	for(int col=0;col<10;col++){
		printf("%d\t",tab[linha][col]);
	}
	printf("\n\n\n"); // espaçamento um pouco exagerado mas apropriado para as tabulações
	
	// recursividade
	if (linha < 9){mostrarTab(tab,linha+1);}
}// fim da função recursiva mostrarTab

// FIM DO CÓDIGO