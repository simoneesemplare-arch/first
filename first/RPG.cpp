#include <stdio.h>
#include <cstdlib>
#include <time.h>

struct Effect{
    char name[20];
    int duration;
    int healthChangePerTurn;
    int manaChangePerTurn;
    int speedChange;
    int stunTurns;
    int poisonStacks;
};

struct Ability{
    char name[20];
    int damage;
    int manaCost;
    int manaHeal;
    int effectIndex;
};

struct Classe{
    char name[20];
    int health;
    int mana;
    int ability[4];
    int speed;
};
struct minion{
    char name[20];
    int health;
    int attack;
    int speed;
    Ability ability[2];
};

void playerTurn(int scelta,int npcPg,Classe classi[],Ability abilita[], int abilitaCount){
        for(int i=0;i<4;i++){
            int abilitaIndex=classi[scelta-1].ability[i];
            if (abilitaIndex < 0 || abilitaIndex >= abilitaCount) continue;
            printf("%d. %s (Damage: %d, Mana Cost: %d, Mana Heal: %d)\n", i+1, abilita[abilitaIndex].name, abilita[abilitaIndex].damage, abilita[abilitaIndex].manaCost, abilita[abilitaIndex].manaHeal);
        }
        int abilitaScelta;
        if (scanf("%d",&abilitaScelta) != 1) return;
        if (abilitaScelta < 1 || abilitaScelta > 4) {
            printf("Scelta abilita' non valida\n");
            return;
        }
        int abilIndex = classi[scelta-1].ability[abilitaScelta-1];
        if (abilIndex < 0 || abilIndex >= abilitaCount) {
            printf("Abilita' non valida\n");
            return;
        }

        // mana check
        if (classi[scelta-1].mana < abilita[abilIndex].manaCost) {
            printf("Mana insufficiente per usare %s\n", abilita[abilIndex].name);
            return;
        }

        // consuma mana
        classi[scelta-1].mana -= abilita[abilIndex].manaCost;
        if (classi[scelta-1].mana < 0) classi[scelta-1].mana = 0;

        // se l'abilità ha damage negativo è una cura (applicata al caster)
        if (abilita[abilIndex].damage < 0) {
            classi[scelta-1].health -= abilita[abilIndex].damage; // damage negativo -> +health
        } else {
            classi[npcPg].health -= abilita[abilIndex].damage;
        }

        // applica eventuale manaHeal al caster
        if (abilita[abilIndex].manaHeal != 0) {
            classi[scelta-1].mana += abilita[abilIndex].manaHeal;
        }
}

void npcTurn(int scelta,int npcPg,Classe classi[],Ability abilita[], int abilitaCount){
    int choice = rand() % 4;
    int abilitaIndex = classi[npcPg].ability[choice];
    if (abilitaIndex < 0 || abilitaIndex >= abilitaCount) return;
    printf("NPC usa %s!\n", abilita[abilitaIndex].name);

    // mana check for NPC
    if (classi[npcPg].mana < abilita[abilitaIndex].manaCost) {
        printf("NPC non ha mana per usare %s\n", abilita[abilitaIndex].name);
        return;
    }
    classi[npcPg].mana -= abilita[abilitaIndex].manaCost;
    if (classi[npcPg].mana < 0) classi[npcPg].mana = 0;

    if (abilita[abilitaIndex].damage < 0) {
        // cura l'NPC
        classi[npcPg].health -= abilita[abilitaIndex].damage;
    } else {
        classi[scelta-1].health -= abilita[abilitaIndex].damage;
    }

    if (abilita[abilitaIndex].manaHeal != 0) {
        classi[npcPg].mana += abilita[abilitaIndex].manaHeal;
    }
}

void clear_ansi() {
    printf("\e[1;1H\e[2J");
}
void printStatus(Classe classi[],int scelta,int npcPg){
    printf("Player - Health: %d, Mana: %d\n",classi[scelta-1].health,classi[scelta-1].mana);
    printf("NPC - Health: %d, Mana: %d\n",classi[npcPg].health,classi[npcPg].mana);
}

int main() {
    srand((unsigned)time(NULL));
    Effect effetti[] = {
        {"None", 0, 0, 0, 0, 0, 0},            //0
        {"Burn", 3, -5, 0, 0, 0, 0},           //1
        {"Freeze", 2, -10, 0, -5, 1, 0},       //2
        {"Poison", 4, -7, 0, 0, 0, 1},         //3
        {"Stun", 1, 0, 0, 0, 3, 0},            //4
        {"Regeneration", 3, 10, 0, 0, 0, 0},   //5
        {"Mana Drain", 3, 0, -5, 0, 0, 0},     //6
        {"Speed Boost", 2, 0, 0, 10, 0, 0}     //7
    };
    Ability abilita[] = {
        {"Fireball", 50, 30, 0,0},         //0
        {"Ice Spike", 40, 20, 0,0},        //1
        {"Heal", -30, 30, 0,0},            //2
        {"Lightning Bolt", 60, 35, 0,0},   //3
        {"Axe Slash", 30, 5, 0,0},         //4
        {"Berserk", 70, 50, 0,0},          //5
        {"Rest", -15, 0, 25,0},            //6
        {"Ice Beam", 20, 25, 0,0},         //7
        {"Poison Dart", 25, 15, 0,3},      //8
        {"Stunning Blow", 15, 20, 0,4},    //9
        {"Shadow Step", 0, 20, 15,7},      //10
        {"Holy Light", 40, 25, 0,5}        //11
    };
    bool tf=true;

    Classe classi[] = {
            {"Mage", 100, 200, {0, 1, 2, 3}, 7},          //0
            {"Warrior", 200, 100, {4, 5, 6, 2}, 10},      //1
            {"Rogue", 150, 150, {7, 4, 2, 0}, 12},        //2
            {"Paladin", 180, 120, {2, 4, 6, 3}, 8},       //3
            {"Necromancer", 120, 220, {0, 7, 5, 2}, 6}    //4
        };
    int length = sizeof(classi) / sizeof(classi[0]);
    int abilitaCount = sizeof(abilita) / sizeof(abilita[0]);

    int npcPg = rand() % length;
    
    printf("Scegli la tua classe:\n");
    for (int i = 0; i < length; i++) {
        printf("%d. %s (Health: %d, Mana: %d, Speed: %d)\n", i+1, classi[i].name, classi[i].health, classi[i].mana, classi[i].speed);
    }
    int scelta;
    if (scanf("%d", &scelta) != 1) return 0;
    if (scelta < 1 || scelta > length) {
        printf("Scelta classe non valida\n");
        return 0;
    }

    // assicurati che npcPg sia diverso dal player
    while (npcPg == scelta-1) npcPg = rand() % length;

    bool game=true;

    while(game){
            if(classi[scelta-1].speed>=classi[npcPg].speed){
                printf("scegli un'abilità:\n");
                playerTurn(scelta,npcPg,classi,abilita, abilitaCount);
                if(classi[npcPg].health<=0){
                    printf("Hai vinto!\n");
                    game=false;
                }
                else{
                    npcTurn(scelta,npcPg,classi,abilita, abilitaCount);
                    if(classi[scelta-1].health<=0){
                        printf("Hai perso!\n");
                        game=false;
                    }
                }
            }else{
                npcTurn(scelta,npcPg,classi,abilita, abilitaCount);
                if(classi[scelta-1].health<=0){
                    printf("Hai perso!\n");
                    game=false;
                }else{
                    printf("scegli un'abilità:\n");
                    playerTurn(scelta,npcPg,classi,abilita, abilitaCount);
                    if(classi[npcPg].health<=0){
                        printf("Hai vinto!\n");
                        game=false;
                    }
                }
            }
            printStatus(classi,scelta,npcPg);
        }
    return 0;
}