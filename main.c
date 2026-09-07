#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char *lines[MAX_LINES];
int lineCount = 0;

/* Insert a new line */
void insertLine(int lineNumber, char *text)
{
    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    if (lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    /* Shift lines down */
    for (int i = lineCount; i >= lineNumber; i--)
    {
        lines[i] = lines[i - 1];
    }

    /* Allocate memory for the new line */
    lines[lineNumber - 1] = malloc(strlen(text) + 1);

    if (lines[lineNumber - 1] == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    strcpy(lines[lineNumber - 1], text);

    lineCount++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine(int lineNumber)
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Free memory of the deleted line */
    free(lines[lineNumber - 1]);

    /* Shift lines up */
    for (int i = lineNumber - 1; i < lineCount - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lines[lineCount - 1] = NULL;

    lineCount--;

    printf("Line deleted successfully.\n");
}

/* Display the document */
void displayDocument()
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    printf("\n----- Document -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Display help */
void displayHelp()
{
    printf("\n===== LINE EDITOR HELP =====\n");
    printf("i <line> <text>  - Insert a new line\n");
    printf("d <line>         - Delete a line\n");
    printf("p                - Display document\n");
    printf("h                - Display help\n");
    printf("q                - Quit the editor\n");
    printf("============================\n");
}

/* Free all allocated memory */
void freeMemory()
{
    for (int i = 0; i < lineCount; i++)
    {
        free(lines[i]);
    }
}

int main()
{
    char command;
    int lineNumber;
    char text[MAX_LENGTH];

    printf("=================================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("=================================\n");

    printf("Type 'h' for help.\n");

    while (1)
    {
        printf("\n> ");

        scanf(" %c", &command);

        if (command == 'i')
        {
            scanf("%d", &lineNumber);

            getchar();

            fgets(text, MAX_LENGTH, stdin);

            text[strcspn(text, "\n")] = '\0';

            insertLine(lineNumber, text);
        }

        else if (command == 'd')
        {
            scanf("%d", &lineNumber);

            deleteLine(lineNumber);
        }

        else if (command == 'p')
        {
            displayDocument();
        }

        else if (command == 'h')
        {
            displayHelp();
        }

        else if (command == 'q')
        {
            printf("Exiting editor...\n");
            break;
        }

        else
        {
            printf("Unknown command. Type 'h' for help.\n");
        }
    }

    freeMemory();

    return 0;
}