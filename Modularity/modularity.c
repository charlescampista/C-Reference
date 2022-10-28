#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

typedef struct {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float media;
    int isAprovado;
    int isAtivo;
} Aluno;

int qtd = 2;
Aluno turma[2];
float mediaAprovacao = 7;

float calcularMediaAluno(float n1,float n2, float n3,float n4) {
    float media = (n1+n2+n3+n4)/4;
    return media;
}

void calcularAprovacaoAluno(Aluno *aluno) {
    float media = calcularMediaAluno(aluno->nota1, aluno->nota2, aluno->nota3, aluno->nota4);
    aluno->media = media;
    if(media >= mediaAprovacao) {
        aluno->isAprovado = 1;
    } else {
        aluno->isAprovado = 0;
    }
}

void lerDadosAlunos() {
    setbuf(stdin,NULL);
    for(int i=0; i<qtd; i++) {
        printf("\n Digite matricula do aluno %d: ", i+1);
        scanf("%d",&turma[i].matricula);
        setbuf(stdin,NULL);
        printf("\n Digite o nome aluno %d: ", i+1);
        fgets(turma[i].nome,50,stdin);
        setbuf(stdin,NULL);
        printf("\n Digite a nota 1 do aluno");
        scanf("%f",&turma[i].nota1);
        setbuf(stdin,NULL);
        printf("\n Digite a nota 2 do aluno");
        scanf("%f",&turma[i].nota2);
        setbuf(stdin,NULL);
        printf("\n Digite a nota 3 do aluno");
        scanf("%f",&turma[i].nota3);
        setbuf(stdin,NULL);
        printf("\n Digite a nota 4 do aluno");
        scanf("%f",&turma[i].nota4);
        setbuf(stdin,NULL);
        turma[i].isAtivo = 1;
        calcularAprovacaoAluno(&turma[i]);
    }
}

void mostrarAlunosAprovados() {
    setbuf(stdin,NULL);
    system("clear");
    printf("\n Alunos Aprovados");
    printf("\n -----------");
    for(int i=0; i<qtd; i++) {
        if(turma[i].isAprovado)
            printf("\nNome: %s",turma[i].nome);
    }
}


void mostrarAlunosReprovados() {
    setbuf(stdin,NULL);
    system("clear");
    printf("\n Alunos Reprovados");
    printf("\n -----------");
    for(int i=0; i<qtd; i++) {
        if(!turma[i].isAprovado)
            printf("\nNome: %s",turma[i].nome);
    }
}

void mostrarMediaAlunos() {
    setbuf(stdin,NULL);
    system("clear");
    printf("\n Media Alunos");
    printf("\n -----------");
    for(int i=0; i<qtd; i++) {
        printf("\nNome: %s",turma[i].nome);
        printf("\nMedia: %.1f",turma[i].media);
        printf("\n -----------");
    }
}

void mostrarAlunos() {
    setbuf(stdin,NULL);
    system("clear");
    for(int i=0; i<qtd; i++) {
        printf("\n -----------");
        printf("\nMatricula: %d",turma[i].matricula);
        printf("\nNome: %s",turma[i].nome);
        printf("\nNota1: %.1f",turma[i].nota1);
        printf("\nNota2: %.1f",turma[i].nota2);
        printf("\nNota3: %.1f",turma[i].nota3);
        printf("\nNota4: %.1f",turma[i].nota4);
        printf("\nAtivado: %s", turma[i].isAtivo ? "Sim" : "Não");
        printf("\nAprovado: %s", turma[i].isAprovado ? "Sim" : "Não");
    }
}

int main() {
    int opcao = -1;
    char trash;
    do {
        scanf("%c",&trash);
        setbuf(stdin,NULL);
        system("clear");
        printf("\nEscolha:");
        printf("\n1 - Inserir Dados Alunos");
        printf("\n2 - Mostrar Alunos Aprovados");
        printf("\n3 - Mostrar Alunos Reprovados");
        printf("\n4 - Mostrar Media Alunos");
        printf("\n5 - Mostrar Alunos");
        printf("\n - - - - - - - - -");
        printf("\n9 - Sair");
        printf("\nDigite sua escolha:");
        scanf("\n%d", &opcao);

        switch (opcao) {
            case 1:
                lerDadosAlunos();
                break;
            case 2:
                mostrarAlunosAprovados();
                break;
            case 3:
                mostrarAlunosReprovados();
                break;
            case 4:
                mostrarMediaAlunos();
                break;
            case 5:
                mostrarAlunos();
                break;
        }


        setbuf(stdin,NULL);
    } while(opcao != 9);
    return 0;
}


