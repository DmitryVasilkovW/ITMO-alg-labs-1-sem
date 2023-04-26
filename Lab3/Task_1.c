# include <stdio.h>
# include <stdlib.h>
# include <mm_malloc.h>

typedef struct list
{
    int ID;
    struct list *next;
} t_list;

t_list *create_node(int set_ID)
{
    t_list *node = (t_list *)malloc(sizeof(t_list));
    node -> ID = set_ID;
    node -> next = NULL;
    return node;
}

void back(t_list **list, int set_ID)
{
    t_list *element = create_node(set_ID);
    t_list *tmp = *list;
    while (tmp -> next != NULL)
    {
        tmp = tmp -> next;
    }
    tmp -> next = element;
}

int main()
{
    int number_of_commands, digit;
    char command;
    scanf("%d\n", &number_of_commands);
    t_list *list = create_node(0);
    for (int i = 0; i < number_of_commands; i ++)
    {
        scanf("%c ", &command);
        if (command == '+')
        {
            scanf("%d\n", &digit);
            back(&list, digit);
        }
        if (command == '-')
        {
            list = list -> next;
            printf("%d\n", list -> ID);
        }
    }
    return 0;
}

