#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 5
#define MAX_ATTEMPTS 6
#define MAX_WORDS 2309  // Total number of five-letter words

// Structure to hold the word database
typedef struct {
    char words[MAX_WORDS][MAX_WORD_LENGTH + 1];
    int num_words;
} WordDatabase;

// Function to load the word database
void load_word_database(WordDatabase *db, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }

    db->num_words = 0;
    while (fscanf(file, "%s", db->words[db->num_words]) != EOF) {
        db->num_words++;
    }

    fclose(file);
}

// Function to validate a word
int validate_word(WordDatabase *db, char *word) {
    int len = strlen(word);

    if (len != MAX_WORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    for (int i = 0; i < db->num_words; i++) {
        if (strcmp(db->words[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to play the game
void play_game(WordDatabase *db) {
    srand(time(NULL));
    char chosen_word[MAX_WORD_LENGTH + 1];
    strcpy(chosen_word, db->words[rand() % db->num_words]);

    for (int attempt = 0; attempt < MAX_ATTEMPTS; attempt++) {
        printf("Enter a 5-letter word: ");
        char guess[MAX_WORD_LENGTH + 1];
        scanf("%s", guess);

        if (!validate_word(db, guess)) {
            printf("Invalid word. Please enter a 5-letter word from the Wordle list.\n");
            attempt--;
            continue;
        }

        int correct_letters = 0;
        int misplaced_letters = 0;
        for (int i = 0; i < MAX_WORD_LENGTH; i++) {
            if (guess[i] == chosen_word[i]) {
                correct_letters++;
                printf("%c [green] ", guess[i]);
            } else if (strchr(chosen_word, guess[i]) != NULL) {
                misplaced_letters++;
                printf("%c [yellow] ", guess[i]);
            } else {
                printf("%c [gray] ", guess[i]);
            }
        }
        printf("\n");

        if (correct_letters == MAX_WORD_LENGTH) {
            printf("Congratulations, you won!\n");
            return;
        }
    }

    printf("Sorry, you lost. The correct word was %s.\n", chosen_word);
}

int main() {
    WordDatabase db;

    load_word_database(&db, "~/Documents/TP_Wordle/wordle_Lakshana/ressource/bdd_wordle.txt");
    play_game(&db);

    return 0;
}
