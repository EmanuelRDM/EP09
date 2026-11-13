#include <stdlib.h>
#include <string.h>
#include "team.h"

struct team {
    int id;
    char *name;
    int wins;
    int draws;
    int losses;
    int goals_scored;
    int goals_conceded;
};

Team* team_create(int id, const char* name) {
    Team* novo_time = (Team*) malloc(sizeof(struct team));
    if (novo_time == NULL) return NULL;
    
    novo_time->id = id;
    
    novo_time->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
    strcpy(novo_time->name, name);
    
    novo_time->wins = 0;
    novo_time->draws = 0;
    novo_time->losses = 0;
    novo_time->goals_scored = 0;
    novo_time->goals_conceded = 0;
    
    return novo_time;
}

void team_free(Team* time_alvo) {
    if (time_alvo != NULL) {
        free(time_alvo->name);
        free(time_alvo);
    }
}

int team_get_id(Team* time_alvo) { return time_alvo->id; }
const char* team_get_name(Team* time_alvo) { return time_alvo->name; }
int team_get_wins(Team* time_alvo) { return time_alvo->wins; }
int team_get_draws(Team* time_alvo) { return time_alvo->draws; }
int team_get_losses(Team* time_alvo) { return time_alvo->losses; }
int team_get_goals_scored(Team* time_alvo) { return time_alvo->goals_scored; }
int team_get_goals_conceded(Team* time_alvo) { return time_alvo->goals_conceded; }