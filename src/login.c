#include<stdio.h>
#include<get_user_info.h>
#include<login_prompt.h>
#include<custom_print.h>
#include<gotoxy.h>
#include<ansi_color_codes.h>

extern yCoord;

int login(char** Email, int** Level) {
  struct USER_INFO* user_info = NULL;
  char mail[100], pass[100];
  int is_valid = 0, i;

  user_info = get_users();
  if (user_info == NULL)
    return 1;

  int total_users = user_info->total_user;
  struct USER* user = user_info->user;

  printCenter("+--------------------------------------+\n", &yCoord);
  printCenter("|             "UWHT"PLEASE LOGIN"RESET"             |\n", &yCoord);
  printCenter("+--------------------------------------+\n", &yCoord);
  printCenter("| Enter Email:                         |\n", &yCoord);
  printCenter("+--------------------------------------+\n", &yCoord);
  printCenter("| Enter Password:                      |\n", &yCoord);
  printCenter("+--------------------------------------+\n", &yCoord);

  gotoxy(20 + 15, yCoord - 4);
  scanf("%s", &mail);

  for (i = 0; i < total_users; i++)
  {
    // char* email = strtok(user[i].email, "\n");
    if (strcmp(user[i].email, mail) == 0)
    {
      is_valid = 1;
      break;
    }
  }

  if (!is_valid)
  {
    gotoxy(20, 2);
    printf(BRED"You are not registered!"RESET);
    gotoxy(20, yCoord + 1);
    printf(HBLK"Press any key to continue..."RESET);
    getch();
    clear_screen(&yCoord);
    login_prompt(Email, Level);
    // return 1;
  }

  gotoxy(20 + 18, yCoord - 2);
  char ch;
  int j=0;
  while ((ch = _getch()) != 13) //character 13 is enter
  {
    pass[j] = ch;
    j++;
    printf("*");
  }
  pass[j] = '\0';
  // scanf("%s", &pass);
  // char* password = strtok(user[i].password, "\n");
  if (strcmp(user[i].password, pass) != 0)
  {
    gotoxy(20, 2);
    printf(BRED"Incorrect password\x1b[0m"RESET);
    gotoxy(20, yCoord+1);
    printf(HBLK"Press any key to continue..."RESET);
    getch();
    clear_screen(&yCoord);
    login_prompt(Email, Level);
    // return 1;
  }

  *Email = &user[i].email;
  *Level = &user[i].level;
  clear_screen(&yCoord);
  main_menu();
  return 0;
}