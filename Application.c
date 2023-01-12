#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
int sign = 0;
struct member
{
    char name[30], num[12];
    char Fatname[30], Fatnum[12];
    int age, tk;
    char Intiname[30], email[70];
    char Paddres[150];
    unsigned long int ID;
} AM, MA;
void welcomemessage();
void mainmenu();
void messmanagement();
void membermanagement();
int password();
void ADDmember();
void printmemberinfo(int n);
void Edit_member_info();
void Remove_Member();
void members_money_info();
void ebill();
void Add_mess_Expenses();
void see_mess_Expenses();
int check_number(char a[]);
void change_password();
void resetdata();
void see_developer_Info();
int Check_valid_ID(unsigned long int a);
int Check_valid_ID_Edit(unsigned long int a);
int main()
{
    welcomemessage();
    return 0;
}
void welcomemessage()
{
    COORD c;
    c.X = 45;
    c.Y = 5;

    COORD a;
    a.X = 45;
    a.Y = 4;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), a);
    printf("**********************************************");
    a.Y += 2;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), a);
    printf("**********************************************");
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);

    printf("**WELCOME TO KASHUNDI MESS MANAGMENT SYSTEM.**");

    for (int i = 0; i < 3; i++)
    {
        if (i == 2)
        {
            printf("\n\n    Last chance.\n");
        }

        if (i == 2 && password() == 0)
        {
            printf("\n    Exiting software.\n");
            sleep(2);
            exit(0);
        }

        if (password() == 1)
        {
            mainmenu();
            break;
        }
    }
}
void mainmenu()
{
    if (sign != 0)
    {
        system("cls");
    }
    sign++;
    printf("\n\n\n\n    CHOOSE OPTION: \n");
    printf("    1 . <<MESS MANAGEMENT>> \n");
    printf("    2 . <<MEMBER MANAGEMENT>>\n");
    printf("    3 . <<EXIT>>              \n");
    printf("    ENTER YOUR CHOICE: ");
    char n;
    fflush(stdin);
    scanf("%c", &n);
    switch (n)
    {
    case '1':
        messmanagement();
        break;
    case '2':
        membermanagement();
        break;
    case '3':
        printf("\n    Thank You For Using our Software.\n    This software developed by Tan Vir\n");
        sleep(3);
        exit(0);
    default:
        printf("    Wrong Choice.\n    Try again.");
        sleep(1);
        mainmenu();
        break;
    }
}
void messmanagement()
{
    system("cls");
    printf("\n\n\n    1 . Members Money Info.\n");
    printf("    2 . Edit Mess estimated bill for each member(MONTHLY).\n");
    printf("    3 . Add Mess Expenses.\n");
    printf("    4 . See Mess Expenses.\n");
    printf("    5 . Change Password.\n");
    printf("    6 . Reset programme.\n");
    printf("    7 . Go to Member mangement Section.\n");
    printf("    8 . Return to main menu.\n");
    printf("    9 . EXIT The software.\n");
    char x;
    fflush(stdin);
    printf("    Enter your choice: ");
    scanf("%c", &x);

    switch (x)
    {
    case '1':
        members_money_info();
        break;
    case '2':
        ebill();
        break;
    case '3':
        Add_mess_Expenses();
        break;
    case '4':
        see_mess_Expenses();
        break;
    case '5':
        change_password();
        break;
    case '6':
        resetdata();
        break;
    case '7':
        membermanagement();
        break;
    case '8':
        mainmenu();
        break;
    case '9':
        printf("\n    Thank You For Using our Software.\n    This software developed by Tan Vir\n");
        sleep(2);
        exit(0);
        break;

    default:
        printf("    Wrong Choice.\n    Try again.");
        sleep(2);
        messmanagement();
        break;
    }
}
void membermanagement()
{
    system("cls");
    printf("\n\n    1 . See Member Info.\n");
    printf("    2 . Edit Member Info.\n");
    printf("    3 . Add new Member.\n");
    printf("    4 . Remove Member.\n");
    printf("    5 . Go to Mess mangement Sector.\n");
    printf("    6 . Return to main menu.\n");
    printf("    7 . EXIT The software.\n");

    printf("    Enter Your Choice: ");
    char n;
    fflush(stdin);
    scanf("%c", &n);

    switch (n)
    {
    case '1':
        system("cls");
        printf("\n\n\n    1 . See a Individual Member Info.\n");
        printf("    2 . See all Member's Info.\n");
        int n1;
        printf("\n    Enter Your Choice: ");
        scanf("%d", &n1);
        if (n1 == 1)
            printmemberinfo(1);
        else if (n1 == 2)
            printmemberinfo(-1);
        else
        {
            printf("    Wrong Choice.\n    Try again.");
            sleep(1);
            membermanagement();
        }
        break;
    case '2':
        Edit_member_info();
        break;
    case '3':
        ADDmember();
        break;
    case '4':
        Remove_Member();
        break;
    case '5':
        messmanagement();
        break;
    case '6':
        mainmenu();
        break;
    case '7':
        printf("\n    Thank You For Using our Software.\n    This software developed by Tan Vir\n");
        sleep(3);
        exit(0);
        break;

    default:
        printf("    Wrong Choice.\n    Try again.");
        sleep(1);
        membermanagement();
        break;
    }
}
int password()
{
    char a[21];
    char c, b[21];
    int i = 0;
    FILE *pass;
    pass = fopen("password.txt", "r");
    if (pass == NULL)
    {
    xx:
        printf("\n\n\n\n    Register Your password.\n    Password can't be more than 20 word.\n");
        printf("\n    Enter password       : ");
        scanf(" %[^\n]", b);
        char c[21];
        printf("    Enter password Again : ");
        scanf(" %[^\n]", c);
        if (strcmp(b, c) != 0)
        {
            printf("    Wrong Password.\n    Try Again.");
            sleep(2);
            goto xx;
        }
        pass = fopen("password.txt", "w");
        fprintf(pass, "%s", b);
        printf("\n    Password registerd.\n");
        fclose(pass);
        sleep(2);
        system("cls");
        mainmenu();
    }

    pass = fopen("password.txt", "r");
    fgets(a, 21, pass);
    fclose(pass);

    printf("\n\n\n\n    Enter password: ");
    while ((c = getch()) != 13)
    {
        if (c == 8)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            i--;
            if (i < 0)
                i = 0;
            continue;
        }
        printf("*");
        b[i++] = c;
    }
    b[i] = NULL;
    int flag = 0;

    if (strcmp(a, b) != 0)
    {
        flag = 1;
        printf("\n    Worng Password.");
        printf("\n    Your given password is : %s", b);
        fclose(pass);
        return 0;
    }
    else
    {
        printf("\n\n    Login Successful");
        sleep(1);
        fclose(pass);
        return 1;
    }
}
void ADDmember()
{
    int n, m;
    FILE *ptr, *mem, *fp;
    ptr = fopen("memberinfo.dat", "a+");
    mem = fopen("memnum.txt", "r");
    if (mem == NULL)
    {
        m = 0;
    }
    else
    {
        char a[3];
        fscanf(mem, "%s", a);
        m = atoi(a);
        fclose(mem);
    }

    system("cls");
    printf("\n\n\n    You can not add more than %d member. \n", 25 - m);
    printf("\n    How many member you wanna add: ");
    scanf("%d", &n);

    if (n > 25 - m)
    {
        printf("\n    You can not add more than %d member.  \n    Returning you to member management system");
        sleep(2);
        membermanagement();
    }
    while (n > 0)
    {
        system("cls");

        printf("\n\n\n    Enter New commer's NAME              : ");
        scanf(" %[^\n]", AM.name);

        while (1)
        {
            printf("    Enter New commer's Number            : ");
            scanf(" %[^\n]", AM.num);
            if (check_number(AM.num) == 1)
            {
                break;
            }
            else
                printf("                                           Invalid Number. Try again.\n");
        }

        printf("    Enter New commer's E-Mail Address    : ");
        scanf(" %[^\n]", AM.email);

        printf("    Enter New commer's Gurdian's NAME    : ");
        scanf(" %[^\n]", AM.Fatname);

        while (1)
        {
            printf("    Enter New commer's Gurdian's NUMBER  : ");
            scanf(" %[^\n]", AM.Fatnum);
            if (check_number(AM.Fatnum) == 1)
            {
                break;
            }
            else
                printf("                                           Invalid Number. Try again.\n");
        }

        while (1)
        {
            printf("    Enter New commer's AGE               : ");
            scanf("%d", &AM.age);
            if (AM.age > 60)
            {
                fclose(ptr);
                printf("    opss!A man more then 60 years can't be a member.");
                sleep(3);
                membermanagement();
            }
            break;
        }

        printf("    Enter Institutions NAME              : ");
        scanf(" %[^\n]", AM.Intiname);
        while (1)
        {
            printf("    Enter New commer's ID                : ");
            scanf("%lu", &AM.ID);
            if (Check_valid_ID(AM.ID) == 1)
            {
                printf("                                         Error. A member already using this ID number Try another.\n");
                continue;
            }
            break;
        }
        printf("    Enter New commer's Address(permanent): ");
        scanf(" %[^\n]", AM.Paddres);

        printf("    Enter ammount of money               : ");
        scanf("%d", &AM.tk);
        fwrite(&AM, sizeof(AM), 1, ptr);
        fp = fopen("memID.txt", "a+");
        fwrite(&AM.ID, sizeof(AM.ID), 1, fp);
        fclose(fp);
        printf("\n    Welcome! Now '%s' is a member of Kashundi mess.\n", AM.name);
        m++;
        if (n != 1)
        {
            sleep(3);
        }
        n--;
    }
    fclose(ptr);
    mem = fopen("memnum.txt", "w");
    fprintf(mem, "%d", m);
    fclose(mem);
    printf("\n    Returning you to the studentmangement sector.\n    Enter To Continue");
    getch();
    membermanagement();
}
void printmemberinfo(int n)
{
    FILE *fp;
    fp = fopen("memberinfo.dat", "r");
    if (fp == NULL)
    {
        printf("    There is no member in mess.\n");
        sleep(3);
        membermanagement();
    }

    if (n == -1)
    {
        char a[3];
        FILE *mem;
        mem = fopen("memnum.txt", "r");
        fscanf(mem, "%s", a);
        int m = atoi(a);
        fclose(mem);
        system("cls");
        printf("\n    There are %d member in mess:\n", m);
        while (fread(&AM, sizeof(AM), 1, fp) == 1)
        {
            printf("    NAME                    : %s\n", AM.name);

            printf("    Number                  : %s\n", AM.num);

            printf("    E-MAIL Address          : %s\n", AM.email);

            printf("    Gurdian's NAME          : %s\n", AM.Fatname);

            printf("    Gurdian's Number        : %s\n", AM.Fatnum);

            printf("    AGE                     : %d\n", AM.age);

            printf("    Institutions NAME       : %s\n", AM.Intiname);

            printf("    ID                      : %lu\n", AM.ID);

            printf("    Address                 : %s\n", AM.Paddres);

            if (AM.tk < 0)
            {
                printf("    Have to give            : %d\n\n", (AM.tk * -1));
            }
            else
                printf("    Given Money             : %d\n\n", AM.tk);
        }
    }
    else
    {
        unsigned long int x;
        system("cls");
        printf("\n    Enter member Unique ID:");
        scanf("%lu", &x);
        int found = 0;

        while (fread(&AM, sizeof(AM), 1, fp) == 1)
        {
            int n = AM.ID;
            if (x == n)
            {
                found = 1;
                printf("\n\n    NAME                    : %s\n", AM.name);

                printf("    Number                  : %s\n", AM.num);

                printf("    E-MAIL Address          : %s\n", AM.email);

                printf("    Gurdian's NAME          : %s\n", AM.Fatname);

                printf("    Gurdian's Number        : %s\n", AM.Fatnum);

                printf("    AGE                     : %d\n", AM.age);

                printf("    Institutions NAME       : %s\n", AM.Intiname);

                printf("    ID                      : %lu\n", AM.ID);

                printf("    Address                 : %s\n", AM.Paddres);

                if (AM.tk < 0)
                {
                    printf("    Have to give            : %d\n\n", (AM.tk * -1));
                }
                else
                    printf("    Given Money             : %d\n\n", AM.tk);
                break;
            }
        }
        if (found == 0)
        {
            printf("\n    Invalid Id no.");
        }
    }
    fclose(fp);
    printf("\n    Returning you to the member management sector.\n    Enter any key to continue.");
    getch();
    membermanagement();
}
void Edit_member_info()
{
    unsigned long int n, y;
    system("cls");

    FILE *mem, *nem;
    mem = fopen("memberinfo.dat", "r");
    if (mem == NULL)
    {
        printf("    There is no member in mess.\n");
        sleep(3);
        membermanagement();
    }

    printf("\n\n\n    Enter Unique Id: ");
    scanf("%lu", &n);
    int found = 0;
    while (fread(&AM, sizeof(AM), 1, mem) == 1)
    {
        int x = AM.ID;
        if (x == n)
        {
            found = 1;
            printf("\n    NAME              : %s\n", AM.name);
            strcpy(MA.name, AM.name);

            printf("    Number            : %s\n", AM.num);
            strcpy(MA.num, AM.num);

            printf("    E-Mail Address    : %s\n", AM.email);
            strcpy(MA.email, AM.email);

            printf("    Gurdian's NAME    : %s\n", AM.Fatname);
            strcpy(MA.Fatname, AM.Fatname);

            printf("    Gurdian's NUMBER  : %s\n", AM.Fatnum);
            strcpy(MA.Fatnum, AM.Fatnum);

            printf("    AGE               : %d\n", AM.age);
            MA.age = AM.age;

            printf("    Institutions NAME : %s\n", AM.Intiname);
            strcpy(MA.Intiname, AM.Intiname);

            printf("    ID                : %lu\n", AM.ID);
            MA.ID = AM.ID;

            printf("    Address           : %s\n", AM.Paddres);
            strcpy(MA.Paddres, AM.Paddres);

            printf("    Money             : %d\n", AM.tk);
            MA.tk = AM.tk;

            break;
        }
    }
    fclose(mem);
    if (found == 0)
    {
        printf("\n    Invalid ID no.    \nReturning you to the member management sector.    \nEnter to continue.");
        getch();
        membermanagement();
    }

    printf("\n\n    Which data you wanna correct:  \n");
    printf("     1 . NAME.  \n");

    printf("     2 . Number.  \n");

    printf("     3 . E-mail.  \n");

    printf("     4 . Gurdian's NAME. \n");

    printf("     5 . Gurdian's Number.  \n");

    printf("     6 . Age.  \n");

    printf("     7 . Institutions NAME. \n");

    printf("     8 . ID.  \n");

    printf("     9 . Address. \n");

    printf("    10 . Money.  \n");

    char o;
    printf("\n    Enter Your Choice : ");
    scanf(" %c", &o);
    system("cls");
    switch (o)
    {
    case '1':
        printf("\n\n\n    Enter correct NAME          : ");
        scanf(" %[^\n]", MA.name);

        break;
    case '2':
        while (1)
        {
            printf("\n\n\n    Enter correct Number        : ");
            scanf(" %[^\n]", MA.num);
            if (check_number(MA.num) == 1)
            {
                break;
            }
            else
                printf("                              Invalid Number. Try again.\n");
        }
        break;
    case '3':
        printf("\n\n\n    Enter correct E-Mail Address : ");
        scanf(" %[^\n]", MA.email);
        break;
    case '4':
        printf("\n\n\n    Enter correct gurdian name     : ");
        scanf(" %[^\n]", MA.Fatname);
        break;
    case '5':
        while (1)
        {
            printf("\n\n\n    Enter gurdian's correct number :");
            scanf(" %[^\n]", MA.Fatnum);
            if (check_number(MA.Fatnum) == 1)
            {
                break;
            }
            else
                printf("                                 Invalid Number. Try again.\n");
        }
        break;
    case '6':
        printf("\n\n\n    Enter correct age number : ");
        scanf("%d", &MA.age);
        break;
    case '7':
        printf("\n\n\n    Enter correct institution name : ");
        scanf(" %[^\n]", MA.Intiname);
        break;
    case '8':
        while (1)
        {
            printf("\n\n\n    Enter correct Id number : ");
            scanf("%lu", &MA.ID);
            if (Check_valid_ID_Edit(MA.ID) == 1)
            {
                printf("    Can't change to this ID no.\n    One member already using this ID no.\n    Try a Different number\n");
                continue;
            }
            break;
        }
        break;
    case '9':
        printf("\n\n\n    Enter correct address : ");
        scanf(" %[^\n]", MA.Paddres);
        break;

    case '10':
        printf("\n\n\n    Update Money : ");
        scanf("%d", &MA.tk);
        break;

    default:
        printf("\n\n    Wrong Choice TRY again. ");
        fclose(nem);
        Edit_member_info();
        break;
    }
    mem = fopen("memberinfo.dat", "r");
    nem = fopen("memberinfo1.dat", "w");
    while (fread(&AM, sizeof(AM), 1, mem) == 1)
    {
        if (AM.ID != n)
        {
            fwrite(&AM, 1, sizeof(AM), nem);
        }
        else
        {
            fwrite(&MA, 1, sizeof(MA), nem);
        }
    }
    fclose(mem);
    fclose(nem);

    remove("memberinfo.dat");
    rename("memberinfo1.dat", "memberinfo.dat");

    mem = fopen("memberinfo.dat", "r");
    while (fread(&AM, sizeof(AM), 1, mem) == 1)
    {
        if (AM.ID == MA.ID)
        {
            printf("    NAME                    : %s\n", AM.name);

            printf("    Number                  : %s\n", AM.num);

            printf("    E-MAIL Address          : %s\n", AM.email);

            printf("    Gurdian's NAME          : %s\n", AM.Fatname);

            printf("    Gurdian's Number        : %s\n", AM.Fatnum);

            printf("    AGE                     : %d\n", AM.age);

            printf("    Institutions NAME       : %s\n", AM.Intiname);

            printf("    ID                      : %lu\n", AM.ID);

            printf("    Address                 : %s\n", AM.Paddres);

            printf("    Money                   : %d\n", AM.tk);
            break;
        }
    }
    fclose(mem);
    printf("\n    Returining you to member management part.\n    Enter To Continue");
    getch();
    membermanagement();
}
void Remove_Member()
{
    unsigned long int n, x;
    FILE *mem;
    mem = fopen("memberinfo.dat", "r");
    system("cls");
    if (mem == NULL)
    {
        printf("    There is no member in mess.\n");
        sleep(3);
        membermanagement();
    }
    printf("\n\n\n    Enter Unique Id number: ");
    scanf("%lu", &n);
    int found = 0;
    while (fread(&AM, sizeof(AM), 1, mem) == 1)
    {
        x = AM.ID;
        if (x == n)
        {
            found = 1;
            printf("\n    Name: %s  ->ID: %d Removed From the Mess.\n", AM.name, AM.ID);
            break;
        }
    }
    fclose(mem);

    if (found == 0)
    {
        printf("\n    Invalid ID no.\n    Returning you to the member management sector.\n    Enter to continue.");
        getch();
        membermanagement();
    }

    char a[3];
    FILE *nem1, *nem;

    nem = fopen("memnum.txt", "r");
    fscanf(nem, "%s", a);
    int y = atoi(a);
    fclose(nem);

    nem = fopen("memnum.txt", "w");
    fprintf(nem, "%d", --y);
    fclose(nem);

    nem1 = fopen("memberinfo1.dat", "w");
    nem = fopen("memberinfo.dat", "r");
    while (fread(&AM, sizeof(AM), 1, nem) == 1)
    {
        x = AM.ID;
        if (x == n)
        {
            continue;
        }
        fwrite(&AM, sizeof(AM), 1, nem1);
    }
    fclose(nem);
    fclose(nem1);
    remove("memberinfo.dat");
    rename("memberinfo1.dat", "memberinfo.dat");
    printf("    Returning you to the member management part.\n    Enter To Continue.");
    getch();
    membermanagement();
}
void members_money_info()
{
    int m;
    char a[10], b[3];
    FILE *fp, *ptr;
    ptr = fopen("ebill.txt", "r");
    if (ptr == NULL)
    {
        printf("    You must update a estimated bill for each member.\n\n");
        printf("    Do you want to update estimated bill for each member?\n");
        printf("    1 . Yes.\n    2 . No.\n");
    xx:
        printf("\n    Enter your choice: ");
        char k;
        scanf(" %c", &k);
        switch (k)
        {
        case '1':
            ebill();
            break;

        case '2':
            printf("    Returning you to the mess management part \n");
            sleep(3);
            messmanagement();
            break;
        default:
            printf("    Wrong  choice.\n    Try again.\n");
            sleep(3);
            goto xx;
            break;
        }
    }
    fscanf(ptr, "%s", a);
    m = atoi(a);
    fclose(ptr);
    system("cls");
    fp = fopen("memberinfo.dat", "r");
    if (fp == NULL)
    {
        printf("    There is no member in mess.\n");
        sleep(3);
        messmanagement();
    }

    FILE *mem;
    mem = fopen("memnum.txt", "r");
    fscanf(mem, "%s", b);
    int n = atoi(b);
    fclose(mem);
    system("cls");
    printf("\n    There are %d member in mess.\n", n);

    while (fread(&AM, sizeof(AM), 1, fp) == 1)
    {
        printf("\n    NAME           : %s\n", AM.name);

        printf("    ID             : %lu\n", AM.ID);

        printf("    Given money    : %d", AM.tk);
        if (m - AM.tk > 0)
        {
            printf("\n    -> Have To pay : %d\n", m - AM.tk);
        }
        else
            printf("\n    -> Will get    : %d\n", AM.tk - m);
    }
    fclose(fp);
    printf("\n\n    Returning you to the messmangement sector.\n    Enter To Continue.");
    getch();
    messmanagement();
}
void ebill()
{
    char a[10];
    int m, x;
    FILE *fp;
    fp = fopen("ebill.txt", "r");
    if (fp != NULL)
    {
        fscanf(fp, "%s", a);
        m = atoi(a);
        fclose(fp);
        printf("\n    Current Estimated Bill: %d tk.\n", m);
    }

    printf("    Update estimated bill for each Member: ");
    scanf("%d", &x);
    fp = fopen("ebill.txt", "w");
    fprintf(fp, "%d", x);
    fclose(fp);
    printf("\n    Successfully Updated.\n");
    printf("    Returning you to the mess mangement sector.\n    Press any key to continue.");
    getch();
    messmanagement();
}
void Add_mess_Expenses()
{
    int n, m, sum;
    char a[40], c[10];
    FILE *fp, *ptr;
    fp = fopen("messExpenses.txt", "a+");
    ptr = fopen("totalcost.txt", "r");
    if (ptr == NULL)
    {
        sum = 0;
    }
    else
    {
        fread(&a, sizeof(a), 1, ptr);
        sum = atoi(a);
        fclose(ptr);
    }
    system("cls");
    printf("\n\n\n    How many item you wanna add : ");
    scanf("%d", &n);

    while (n)
    {
        printf("\n    Enter Item Name: ");
        scanf(" %[^\n]", a);
        printf("    Enter Price: ");
        scanf("%d", &m);
        sum = sum + m;
        strcat(a, " = ");
        strcat(a, itoa(m, c, 10));
        strcat(a, " tk");
        fwrite(a, 1, sizeof(a), fp);
        n--;
    }
    ptr = fopen("totalcost.txt", "w");
    itoa(sum, c, 10);
    fwrite(c, 1, sizeof(c), ptr);
    printf("\n    Succesfully Add Expenses.\n");

    fclose(fp);
    fclose(ptr);
    printf("\n    Returning You To the mess management sector.\n    Enter to continue.");
    getch();
    messmanagement();
}
void see_mess_Expenses()
{
    int sum, n = 1;
    char a[40];

    FILE *fp, *ptr;
    fp = fopen("messExpenses.txt", "r");
    if (fp == NULL)
    {
        printf("    There is no member in mess.\n");
        sleep(3);
        messmanagement();
    }
    ptr = fopen("totalcost.txt", "r");
    if (ptr == NULL)
    {
        fclose(fp);
        printf("    Some FILE has been deleted from your device.\n");
        sleep(3);
        messmanagement();
    }

    fread(&a, sizeof(a), 1, ptr);
    fclose(ptr);

    sum = atoi(a);
    system("cls");
    printf("\n\n");
    while (fread(a, sizeof(a), 1, fp) == 1)
    {
        printf("\n    ->%d . %s", n, a);
        n++;
    }

    printf("\n\n    ->->Total Expenses: %d tk.\n", sum);
    fclose(fp);

    printf("\n    Returning You To the mess management sector.\n    Enter to continue.");
    getch();

    messmanagement();
}
int check_number(char a[])
{
    int i;
    for (i = 0; a[i] != NULL && i != 12; i++)
    {
        if (!(a[i] >= '0' && a[i] <= '9'))
            return 0;
    }
    if (i == 11)
        return 1;
    else
        return 0;
}
void change_password()
{
    FILE *pas;
    pas = fopen("password.txt", "r");
    if (pas == NULL)
    {
        printf("    Some file has been delated from your Computer.\n    To Fix, Meet with your developer soon.\n");
        return;
    }
    char pass[21], pass1[21];
    system("cls");
    printf("\n\n\n    Enter Old Password   : ");
    scanf(" %[^\n]", pass);
    fgets(pass1, 20, pas);
    fclose(pas);
    if (strcmp(pass, pass1) != 0)
    {
        printf("    Wrong Password.\n    Returning you to the mess mangement system.");
        sleep(2);
        messmanagement();
    }
    int i = 0;
    printf("\n    password should not exceed 20 words\n");
    while (1)
    {
        int j = 0;
        printf("\n    Enter New Password     : ");
        scanf(" %[^\n]", pass);
        for (j = 0; pass[j] != NULL; j++)
            ;
        if (j > 20)
        {
            printf("\n    password exceeded 20 words.\n    Try Again.\n\n");
            continue;
        }

        i++;
        printf("    Re-Enter New Password  : ");
        scanf(" %[^\n]", pass1);
        if (strcmp(pass, pass1) != 0)
        {
            printf("    Not matched.\n    Try again.");
            if (i == 2)
            {
                printf("\n    Returning you to the mess management system.");
                sleep(2);
                messmanagement();
            }
        }
        else
        {
            printf("\n    Password Successfully Updated");
            break;
        }
    }
    pas = fopen("password.txt", "w");
    fwrite(pass, 1, sizeof(pass), pas);

    fclose(pas);
    printf("\n    Returning you to the mess management system.\n    Enter to continue.");
    getch();
    messmanagement();
}
void resetdata()
{
    system("cls");
    printf("\n\n\n    1.Reset all data.");
    printf("\n    2.Reset software for new month.");

    char n, a[10];
    ;
    printf("\n\n    ->Enter your choice: ");
    fflush(stdin);
    scanf("%c", &n);
    FILE *mem, *nem, *fp;
    switch (n)
    {
    case '1':
        fp = fopen("memberinfo.dat", "w");
        fclose(fp);
        fp = fopen("memnum.txt", "w");
        fclose(fp);
        fp = fopen("messExpenses.txt", "w");
        fclose(fp);
        fp = fopen("totalcost.txt", "w");
        fclose(fp);
        fp = fopen("ebill.txt", "w");
        fclose(fp);
        remove("ebill.txt");
        fp = fopen("memID.txt", "w");
        fclose(fp);
        printf("\n    All data Reseted.\n    Returning you to the mess management part.\n    Enter to continue.");
        getch();
        messmanagement();
        break;
    case '2':
        fp = fopen("ebill.txt", "r");
        fscanf(fp, "%s", a);
        int m2 = atoi(a);
        fclose(fp);
        mem = fopen("memberinfo.dat", "r");
        int flag = 0;
        if (mem == NULL)
        {
            flag == 1;
        }
        if (flag == 0)
        {
            nem = fopen("memberinfo1.dat", "w");
            while (fread(&AM, sizeof(AM), 1, mem) == 1)
            {
                strcpy(MA.name, AM.name);
                strcpy(MA.num, AM.num);
                strcpy(MA.email, AM.email);
                strcpy(MA.Fatname, AM.Fatname);
                strcpy(MA.Fatnum, AM.Fatnum);
                MA.age = AM.age;
                strcpy(MA.Intiname, AM.Intiname);
                MA.ID = AM.ID;
                strcpy(MA.Paddres, AM.Paddres);
                MA.tk = AM.tk - m2;
                fwrite(&MA, 1, sizeof(MA), nem);
            }

            fclose(mem);
            fclose(nem);

            remove("memberinfo.dat");
            rename("memberinfo1.dat", "memberinfo.dat");
        }
        fp = fopen("messExpenses.txt", "w");
        fclose(fp);

        fp = fopen("totalcost.txt", "w");
        fclose(fp);
        printf("\n    Programme reseted for new month.\n    Returning you to the mess management part.\n    Enter to continue.");
        getch();
        messmanagement();
        break;

    default:
        printf("\n    Invalid choice.\n    Try AGAIN.\n    Enter to continue.");
        getch();
        resetdata();

        break;
    }
}
int Check_valid_ID(unsigned long int a)
{
    FILE *mem;
    mem = fopen("memID.txt", "r");
    while (fread(&MA.ID, sizeof(MA.ID), 1, mem))
    {
        if (a == MA.ID)
        {
            fclose(mem);
            return 1;
        }
    }
    fclose(mem);
    return 0;
}
int Check_valid_ID_Edit(unsigned long int a)
{
    FILE *mem;
    mem = fopen("memID.txt", "r");
    while (fread(&AM.ID, sizeof(AM.ID), 1, mem))
    {
        if (a == AM.ID)
        {
            fclose(mem);
            return 1;
        }
    }
    fclose(mem);
    return 0;
}
