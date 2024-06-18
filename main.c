/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:00:22 by sbenes            #+#    #+#             */
/*   Updated: 2024/06/18 16:58:51 by sbenes           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "include/libasm.h"

extern int  errno;
void    test_ft_strlen();
void    test_ft_strcpy();

char *test_cases[] = {
        "Hello World!",
        "",
        "A",
        "1234567890",
        "!@#$%^&*()_+",
        "This is a very long strinThis is a very long stringThis is a very long stringThis is a very long stringThis is a very long stringThis is a very long stringThis is a very long string\n",
        "String with newline\ncharacter",
        "String with\ttab character"
};

void    test_ft_strlen()
{
    printf(":::::: ft_strlen ::::::\n\n");
    
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        printf("Test case: [%s]\n", test_cases[i]);
        printf("ft_strlen: \t%zu \n", ft_strlen(test_cases[i]));
        printf("strlen: \t%zu \n", strlen(test_cases[i]));
        if (ft_strlen(test_cases[i]) != strlen(test_cases[i]))
            printf("Result: " RED "failed\n\n" RESET);
        else
            printf("Result: " GREEN "OK" RESET "\n\n");
        
    }
}

void    test_ft_strcpy()
{
    printf(":::::: ft_strcpy ::::::\n\n");
    
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        char destination[ft_strlen(test_cases[i])];
        printf("Test case: [%s]\n", test_cases[i]);
        printf("ft_strcpy: \t%s \n", ft_strcpy(destination, test_cases[i]));
        printf("strcpy: \t%s \n", strcpy(destination, test_cases[i]));
        if (ft_strlen(test_cases[i]) != strlen(test_cases[i]))
            printf("Result: " RED "failed\n\n" RESET);
        else
            printf("Result: " GREEN "OK" RESET "\n\n");
        
    }
}

int main(int argc, char **argv)
{

    char *parameter = argv[1];

    if(!strcmp(parameter, "ft_strlen"))
        test_ft_strlen();
    else if(!strcmp(parameter, "ft_strcpy"))
        test_ft_strcpy();
    
    
    return 0;
}

