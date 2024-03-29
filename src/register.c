#include <stdio.h>
#include <stdlib.h>
#include<get_user_info.h>
#include<main_menu.h>
#include<clear_screen.h>
#include<custom_print.h>
#include<gotoxy.h>
#include<ansi_color_codes.h>

extern yCoord;

void registr(char** Email, int** Level) {
    int choice, i;
    char mail[100];
    char name[100];
    char password[100];
    int highest_score = 0;
    int level;
    struct USER_INFO* user_info = NULL;
    user_info = get_users();
    if (user_info == NULL)
        return 1;

    int total_users = user_info->total_user;
    struct USER* user = user_info->user;

    printCenter("+--------------------------------------+\n", &yCoord);
    printCenter("|            "UWHT"PLEASE REGISTER"RESET"           |\n", &yCoord);
    printCenter("+--------------------------------------+\n", &yCoord);
    printCenter("| Enter Email:                         |\n", &yCoord);
    printCenter("+--------------------------------------+\n", &yCoord);
    printCenter("| Enter Name:                          |\n", &yCoord);
    printCenter("+--------------------------------------+\n", &yCoord);
    printCenter("| Enter Password:                      |\n", &yCoord);
    printCenter("+--------------------------------------+\n", &yCoord);
    printCenter("| 1. Primary                           |\n", &yCoord);
    printCenter("| 2. Secondary                         |\n", &yCoord);
    printCenter("| 3. Higher Secondary                  |\n", &yCoord);
    printCenter("| Select Level (1-3):                  |\n", &yCoord);
    printCenter("+--------------------------------------+\n", &yCoord);

    gotoxy(20 + 15, yCoord - 11);
    // printf("Enter email: ");
    scanf("%s", &mail);

    for (i = 0; i < total_users; i++)
    {
        // char* email = strtok(user[i].email, "\n");
        if (strcmp(user[i].email, mail) == 0)
        {
            gotoxy(20, 2);
            printf(HRED"Email is already registered.." RESET);
            gotoxy(20, yCoord + 1);
            printf(HBLK"Press any key to continue..."RESET);
            getch();
            clear_screen(&yCoord);
            login_prompt(Email, Level);
        }
    }

    while (getchar() != '\n');

    gotoxy(20 + 14, yCoord - 9);
    fgets(name, sizeof(name), stdin);

    gotoxy(20 + 18, yCoord - 7);
    fgets(password, sizeof(password), stdin);

    gotoxy(20 + 22, yCoord - 2);
    do
    {
        //printf("====================================\n");
        // printf("\nSelect Level\n");
        //printf("====================================\n");
        // printf(" 1. Primary\n");
        // printf(" 2. Secondary\n");
        // printf(" 3. Higher Secondary\n\n");
        //printf("====================================\n");
        // printf(" Enter your choice (1-3): ");
        //printf("====================================\n");
        // fflush(stdout);  // make sure the prompt is displayed before input is read
        if (scanf("%d", &choice) != 1)
        {
            clear_screen(&yCoord);
            gotoxy(20, 2);
            printf(HRED"Invalid choice" RESET);
            // while (getchar() != '\n');  // clear input buffer
            // choice = -1;  // set invalid choice to continue loop
            fflush(stdin);
            continue;
        }
        switch (choice)
        {
        case 1:
            level = 1;
            break;
        case 2:
            level = 11;
            break;
        case 3:
            level = 21;
            break;
        default:
            clear_screen(&yCoord);
            gotoxy(20, 2);
            printf(HRED"Invalid choice"RESET);
            break;
        }
    } while (choice < 1 || choice > 3);


    FILE* fp = fopen("D:\\C-C++\\Projects\\ThinkFast\\database\\user_info.txt", "a");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }
    fprintf(fp, "%s\n%s%s%d\n%d\n", mail, name, password, highest_score, level);
    // Flush file buffer to write data immediately
    fflush(fp);
    *Email = &mail;
    *Level = &level;
    clear_screen(&yCoord);
    main_menu();
}
