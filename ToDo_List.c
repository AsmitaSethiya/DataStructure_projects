#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct node
{
    char data[100];
    struct node *add; 
};

struct node *start = NULL, *temp = NULL, *prev = NULL, *next = NULL, *NEW = NULL;

void WelcomeUser();
void CreateToDo();
void InsertToDo();
void DeleteToDo();
void seeToDo();

void main()
{
    int choice;

    WelcomeUser();

    while(1)
    {
        system("CLS");
        system("color 3F");
        printf("\n\t\tPress 1 to Create Your ToDos\n\n");
        printf("\t\tPress 2 to Update your TODo into list\n\n");
        printf("\t\tPress 3 to Delete your ToDo from list\n\n");
        printf("\t\tPress 4 to See your ToDo\n\n"); 
        printf("\t\tPress 5 to exit\n\n");

        printf("\n\t\tEnter your choice:   ");
        scanf("%d", &choice);

        switch(choice)    
        {
            case 1:
                CreateToDo();
                break;
            case 2:
                InsertToDo();
                break;
            case 3:
                DeleteToDo();
                break;
            case 4:
                seeToDo();
                break;
            case 5:
                exit(0);
            default:
                printf("\n\t\tInvalid choice, Please Reenter valid choice......\n");                    
                break;
        }   
    }
}


void WelcomeUser()
{
    system("color 3F");
    printf("\n\n\n\n\n");
    printf("\t------------------------------------------------------------------------------------------------------\n\n");
    printf("\t************************************* YOUR TODO LIST APP *******************************************\n\n");
    printf("\t------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\t\t*******************************WELCOME*******************************\n\n\n\n\n\n\n\n\n\t");
    system("pause");
}

void CreateToDo()
{
 
    char ch;

    system("CLS");

    start = (struct node *)malloc(sizeof(struct node));

    printf("\n\tADD it......\n\n");
    fflush(stdin);
    printf("\t");
    gets(start -> data);

    start -> add = NULL;
    temp = start;


    printf("\n\tTo add more TODOs Press 'Y': ");
    scanf(" %c", &ch);

    while(ch == 'y' || ch == 'Y')
    {
        printf("\n\tADD it......\n\n");
        
        NEW = (struct node *)malloc(sizeof(struct node));
        fflush(stdin);
        printf("\t");
        gets(NEW -> data);
        NEW -> add = NULL;
        temp -> add = NEW;
        temp = NEW;

        printf("\n\tTo add more ToDos Press 'Y':  ");
        scanf(" %c", &ch);
    }
    printf("\n");
    printf("\t");
    system("pause");
}   


void InsertToDo()
{
    system("CLS");
    int position, i = 1, count = 0;

    if(start == NULL)
    {
        printf("\n\tToDos List is empty\n");
    } 
    else
    {
        NEW = (struct node *)malloc(sizeof(struct node));
            
        printf("\n\tEnter position where you want to add ToDo:  ");
        scanf("%d", &position);

        printf("\n\tAdd it......\n\n");
        fflush(stdin);
        printf("\t");
        gets(NEW -> data);
        NEW -> add = NULL;

        if(position == 1)
        {
            NEW -> add = start;
            start = NEW;
        }
        else
        {
            temp = start;
            while(temp != NULL)
            {
                count++;
                temp = temp -> add;
            }

            if(position > count + 1)
            {
                printf("\n\tInvalid Position, It can not be more than %d\n", count + 1);
            }
            else if(position == count)
            {
                temp = start;
                while(temp -> add != NULL)
                {
                    temp = temp -> add;
                }

                temp -> add = NEW;
            }
            else
            {
                next = start;
                while(i < position)
                {
                    prev = next;
                    next = next -> add;
                    i++;
                }
                prev -> add = NEW;
                NEW -> add = next;
            }
        }

    }
    printf("\n");
    printf("\t");
    system("pause");
}

void DeleteToDo()
{
    system("CLS");
    int number, count = 0, i = 1;

    if(start == NULL)
    {
        printf("\n\tToDo list is empty\n\n");
    }
    else
    {
        printf("\n\tEnter the number of ToDo you want to Delete: ");
        scanf("%d", &number);

        if(number == 1)
        {
            temp = start;
            start = start -> add;
            printf("\n\tDeleted ToDo is:");
            puts(temp -> data);
            printf("\n\tYour ToDo is successfully Deleted\n");
            free(temp);
        }
        else
        {
            temp = start;
            while(temp != NULL)
            {
                count++;
                temp = temp -> add;
            }

            if(number > count)
            {
                printf("\n\tInvalid number, it can't be more than %d \n", count);
            }
            else if(number == count)
            {
                next  = start;
                while(next -> add != NULL)
                {
                    prev = next;
                    next = next -> add;
                }
                    
                printf("\n\tDeleted ToDo is: ");
                puts(next -> data);
                printf("\n\tYour Todo is successfully deleted\n");
                free(next);
                prev -> add = NULL;
            }
            else
            {
                next  = start;
                while(i < number)
                {
                    prev = next;
                    next = next -> add;
                    i++;
                }
                temp = next;
                next = next -> add;
                printf("\n\tDeleted ToDo is: ");
                puts(temp -> data);
                printf("\n\tYour ToDo is successfully deleted\n");
                free(temp);
                prev -> add = next;
            }
        }
    }
    printf("\n");
    printf("\t");
    system("pause");
}

void seeToDo()
{
    system("CLS");
    if(start == NULL)
    {
        printf("\nToDo list is empty......\n");
    }
    else
    {
        temp = start;
        int count = 1;
        while(temp != NULL)
        {
            printf("\n");
            printf("\t%d) ", count);
            puts(temp -> data);
            fflush(stdin);
            count++;
            temp  = temp -> add;
            printf("\n");
        }
    }
    printf("\n");
    printf("\t");
    system("pause");
} 
