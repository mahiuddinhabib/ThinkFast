#ifndef MCQ_READER_H
#define MCQ_READER_H

/* struct MCQ
{
    char text[100];
    char options[4][50];
    char correct_option;
};

struct MCQ_QUESTIONS
{
    int total_question;
    struct MCQ *mcq;
};

struct MCQ_QUESTIONS *read_mcq(char *filename); */

int display_mcq(char* filename, char* mail, int** Level, int isOnline, int time_limit);

#endif // MCQ_READER_H

