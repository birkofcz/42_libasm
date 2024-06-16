/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:00:22 by sbenes            #+#    #+#             */
/*   Updated: 2024/06/16 16:47:37 by sbenes           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "include/libasm.h"

extern int  errno;

void    test_ft_strlen()
{
    printf(":::::: ft_strlen ::::::\n\n");
    
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

    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        printf("Test case: [%s]\n", test_cases[i]);
        printf("ft_strlen: \t%zu \n", ft_strlen(test_cases[i]));
        printf("strlen: \t%zu \n\n", strlen(test_cases[i]));
    }
}

int main(int argc, char **argv)
{

    char *parameter = argv[1];

    if(!strcmp(parameter, "ft_strlen"))
        test_ft_strlen();

/*     printf(":::::: ft_strlen ::::::\n\n");
    
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

    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        printf("Test case: [%s]\n", test_cases[i]);
        printf("ft_strlen: \t%zu \n", ft_strlen(test_cases[i]));
        printf("strlen: \t%zu \n\n", strlen(test_cases[i]));
    }

    printf(":::::: ft_strcpy ::::::\n\n"); */
    
    return 0;
}

