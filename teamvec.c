#include <stdlib.h>
#include "teamvec.h"
#include "team.h"

struct teamvec {
    int tamanho;
    int capacidade;
    Team** dados;
};

TeamVec* tv_create() {
    TeamVec* vetor_times = (TeamVec*) malloc(sizeof(struct teamvec));
    if (vetor_times == NULL) return NULL;
    
    vetor_times->tamanho = 0;
    vetor_times->capacidade = 2;
    vetor_times->dados = (Team**) malloc(vetor_times->capacidade * sizeof(Team*));
    
    return vetor_times;
}

void tv_insert(TeamVec* vetor_times, Team* novo_time) {
    if (vetor_times->tamanho == vetor_times->capacidade) {
        vetor_times->capacidade *= 2;
        vetor_times->dados = (Team**) realloc(vetor_times->dados, vetor_times->capacidade * sizeof(Team*));
    }
    
    vetor_times->dados[vetor_times->tamanho++] = novo_time;
}

int tv_size(TeamVec* vetor_times) {
    return vetor_times->tamanho;
}

Team* tv_get(TeamVec* vetor_times, int indice) {
    if (indice >= 0 && indice < vetor_times->tamanho) {
        return vetor_times->dados[indice];
    }
    return NULL;
}

void tv_free(TeamVec* vetor_times) {
    if (vetor_times != NULL) {
        free(vetor_times->dados);
        free(vetor_times);
    }
}