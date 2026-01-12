#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

enum Materia{
    informatica,
    matematica,
    fisica,
    chimica,
    biologia
};
struct Voto
{
    Materia materia;
    int valore;
    char data[11];
};

struct alunno{
    char nome[30];
    char cognome[30];
    Voto voti[10];
};

bool isValidDate(const char* date) {
    if (strlen(date) != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i])) return false;
    }
    int year = atoi(date);
    int month = atoi(date + 5);
    int day = atoi(date + 8);
    if (year < 1900 || year > 2100) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    // Basic check for days in month (not perfect, but sufficient)
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return false;
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (leap ? 29 : 28)) return false;
    }
    return true;
}

void addStudent(alunno studenti[], int &studentCount){
    if(studentCount >= 50){
        printf("Limite studenti raggiunto\n");
        return;
    }
    alunno nuovo = {};
    printf("Inserisci nome: ");
    scanf("%29s", nuovo.nome);
    printf("Inserisci cognome: ");
    scanf("%29s", nuovo.cognome);
    studenti[studentCount]=nuovo;
    studentCount++;
}
void viewStudents(alunno studenti[], int studentCount){
    for(int i=0;i<studentCount;i++){
        printf("Studente %d: %s %s\n", i+1, studenti[i].nome, studenti[i].cognome);
        for(int j=0;j<10;j++){
            if(studenti[i].voti[j].valore==0) continue;
            printf("  Voto %d: Materia %d, Valore %d, Data %s\n", j+1, studenti[i].voti[j].materia, studenti[i].voti[j].valore, studenti[i].voti[j].data);
        }
    }
}

void addGrade(alunno &studente){
    for(int i=0;i<10;i++){
        if(studente.voti[i].valore==0){
            int mat;
            int val;
            char data[11];
            printf("Inserisci materia (0-Informatica, 1-Matematica, 2-Fisica, 3-Chimica, 4-Biologia): ");
            if(scanf("%d",&mat)!=1) return;
            if(mat<0 || mat>4){
                printf("Materia non valida\n");
                return;
            }
            printf("Inserisci valore voto: ");
            if(scanf("%d",&val)!=1) return;
            if(val<1 || val>10){
                printf("Valore voto non valido\n");
                return;
            }
            printf("Inserisci data (YYYY-MM-DD): ");
            if(scanf("%10s",data)!=1) return;
            if(!isValidDate(data)){
                printf("Data non valida\n");
                return;
            }
            studente.voti[i].materia=(Materia)mat;
            studente.voti[i].valore=val;
            snprintf(studente.voti[i].data,11,"%s",data);
            return;
        }
    }
    printf("Limite voti raggiunto per questo studente\n");
}

void viewGrades(alunno &studente){
    printf("Voti per %s %s:\n", studente.nome, studente.cognome);
    for(int i=0;i<10;i++){
        if(studente.voti[i].valore==0) continue;
        printf("  Voto %d: Materia %d, Valore %d, Data %s\n", i+1, studente.voti[i].materia, studente.voti[i].valore, studente.voti[i].data);
    }
}

void deleteGrade(alunno &studente){
    int votoIndex;
    printf("Inserisci il numero del voto da eliminare (1-10): ");
    if(scanf("%d",&votoIndex)!=1) return;
    if(votoIndex<1 || votoIndex>10){
        printf("Numero voto non valido\n");
        return;
    }
    if(studente.voti[votoIndex-1].valore==0){
        printf("Voto non esistente\n");
        return;
    }
    for(int i=votoIndex-1;i<9;i++){
        studente.voti[i]=studente.voti[i+1];
    }
    studente.voti[9].valore=0; // azzera l'ultimo voto
    studente.voti[9].materia = informatica;
    studente.voti[9].data[0] = '\0';
    printf("Voto eliminato\n");
}

void manageStudent(alunno &studente){
    bool tf=true;
    while(tf){
        printf("Gestione studente %s %s:\n", studente.nome, studente.cognome);
        printf("1. Aggiungi voto\n2. Visualizza voti\n3. Elimina voto\n4. Torna al menu principale\n");
        int scelta;
        if(scanf("%d",&scelta)!=1) return;
        switch(scelta){
            case 1:
                addGrade(studente);
                break;
            case 2:
                viewGrades(studente);
                break;
            case 3:
                deleteGrade(studente);
                break;
            case 4:
                tf=false;
                break;
            default:
                printf("Scelta non valida\n");
        }
    }
}

void mediaVoti(alunno &studente){
    int somma=0;
    int count=0;
    for(int i=0;i<10;i++){
        if(studente.voti[i].valore!=0){
            somma+=studente.voti[i].valore;
            count++;
        }
    }
    if(count==0){
        printf("Nessun voto presente per %s %s\n", studente.nome, studente.cognome);
        return;
    }
    float media=(float)somma/count;
    printf("La media voti di %s %s e': %.2f\n", studente.nome, studente.cognome, media);
}

void mediaMateria(alunno studenti[], int studentCount, Materia materia){
    int somma=0;
    int count=0;
    for(int i=0;i<studentCount;i++){
        for(int j=0;j<10;j++){
            if(studenti[i].voti[j].materia==materia && studenti[i].voti[j].valore!=0){
                somma+=studenti[i].voti[j].valore;
                count++;
            }
        }
    }
    if(count==0){
        printf("Nessun voto presente per la materia %d\n", materia);
        return;
    }
    float media=(float)somma/count;
    printf("La media voti per la materia %d e': %.2f\n", materia, media);
}

void mediaMateriaStudente(alunno &studente, Materia materia){
    int somma=0;
    int count=0;
    for(int i=0;i<10;i++){
        if(studente.voti[i].materia==materia && studente.voti[i].valore!=0){
            somma+=studente.voti[i].valore;
            count++;
        }
    }
    if(count==0){
        printf("Nessun voto presente per la materia %d per %s %s\n", materia, studente.nome, studente.cognome);
        return;
    }
    float media=(float)somma/count;
    printf("La media voti per la materia %d di %s %s e': %.2f\n", materia, studente.nome, studente.cognome, media);
}

int main() {
    
    alunno studenti[50] = {};
    int studentCount = 0;
    bool tf=true;
    while(tf){
        printf("1. Aggiungi studente\n2. Visualizza studenti\n3. Gestisci studente\n4. Calcola media voti studente\n5. Calcola media materia\n6. Esci\n");
        int scelta;
        if (scanf("%d",&scelta) != 1) return 0;
        int idx;
        switch(scelta){
            case 1:
                addStudent(studenti, studentCount);
                break;
            case 2:
                viewStudents(studenti, studentCount);
                break;
            case 3:
                if(studentCount==0){
                    printf("Nessuno studente presente\n");
                    break;
                }
                printf("Seleziona studente (1-%d): ", studentCount);
                if(scanf("%d", &idx) != 1) break;
                if(idx < 1 || idx > studentCount){
                    printf("Indice studente non valido\n");
                    break;
                }
                manageStudent(studenti[idx-1]);
                break;
            case 4:
                if(studentCount==0){
                    printf("Nessuno studente presente\n");
                    break;
                }
                printf("Seleziona studente (1-%d): ", studentCount);
                if(scanf("%d", &idx) != 1) break;
                if(idx < 1 || idx > studentCount){
                    printf("Indice studente non valido\n");
                    break;
                }
                mediaVoti(studenti[idx-1]);
                break;
            case 5:
                if(studentCount==0){
                    printf("Nessuno studente presente\n");
                    break;
                }
                printf("Seleziona studente (1-%d): ", studentCount);
                if(scanf("%d", &idx) != 1) break;
                if(idx < 1 || idx > studentCount){
                    printf("Indice studente non valido\n");
                    break;
                }
                printf("Inserisci materia (0-Informatica, 1-Matematica, 2-Fisica, 3-Chimica, 4-Biologia): ");
                int mat;
                if(scanf("%d",&mat)!=1) break;
                if(mat<0 || mat>4){
                    printf("Materia non valida\n");
                    break;
                }
                mediaMateriaStudente(studenti[idx-1], (Materia)mat);
                break;
            case 6:
                tf=false;
                break;
            default:
                printf("Scelta non valida\n");
        }
    }



    return 0;
}