# include <stdio.h>

int main()
{
    int number_of_commands, digit, counter1 = 0, counter2 = 0;
    char command;
    scanf("%d\n", &number_of_commands);
    int array[number_of_commands];
    for (int i = 0; i < number_of_commands; i ++)
    {
        scanf("%c ", &command);
        if (command == '+')
        {
            scanf("%d\n", &digit);
            array[counter1] = digit;
            counter1 ++;
        }
        if (command == '-')
        {
            printf("%d\n", array[counter2]);
            counter2 ++;
        }
    }
    return 0;
}
