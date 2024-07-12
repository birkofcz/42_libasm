/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:00:22 by sbenes            #+#    #+#             */
/*   Updated: 2024/07/12 16:59:37 by sbenes           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


#include "include/libasm.h"

extern int  errno;
void    test_ft_strlen();
void    test_ft_strcpy();
void    test_ft_strcmp();
void    test_ft_write();
void    test_ft_read();
void    test_ft_strdup();

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

void    test_ft_strcmp()
{
    char *first = "ahoj";
    char *second = "aho";

    printf("ft_strcmp: %d\n", ft_strcmp(first, second));
    printf("strcmp: %d\n", strcmp(first, second));
    

}

void    test_ft_write()
{
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);
    int fd = 1;
    int ret;

    printf(":::::: ft_write ::::::\n\n");
    
    for (int i = 0; i < case_nr; i++)
    {
        printf("Test case: [%s]\n", test_cases[i]);
        ret = ft_write(fd, test_cases[i], ft_strlen(test_cases[i]));
        printf("ft_write: \t%d \n", ret);
        ret = write(fd, test_cases[i], ft_strlen(test_cases[i]));
        printf("write: \t%d \n", ret);
        if (ret != ft_write(fd, test_cases[i], ft_strlen(test_cases[i])))
            printf("Result: " RED "failed\n\n" RESET);
        else
            printf("Result: " GREEN "OK" RESET "\n\n");
    }

    // bad input test suite:
/*     printf("Bad input test suite:\n");
    ret = ft_write(-1, test_cases[0], ft_strlen(test_cases[0]));
    printf("ft_write with bad fd (-1): \t%d \n", ret);
    printf("echo $?: %i \n", system("echo $?"));
    printf("errno: %d\n", errno);   
    ret = write(-1, test_cases[0], ft_strlen(test_cases[0]));
    printf("write with bad fd (-1): \t%d \n", ret);
    printf("echo $?: %i \n", system("echo $?"));
    printf("errno: %d\n", errno); */
   
   // bad input test suite:
    printf("Bad input test suite:\n");

    // Test ft_write with bad fd
    errno = 0; // Reset errno before the call
    ret = ft_write(-1, test_cases[0], ft_strlen(test_cases[0]));
    printf("ft_write with bad fd (-1): \t%d \n", ret);
    printf("errno after ft_write: %d\n", errno);

    // Test write with bad fd
    errno = 0; // Reset errno before the call
    ret = write(-1, test_cases[0], ft_strlen(test_cases[0]));
    printf("write with bad fd (-1): \t%d \n", ret);
    printf("errno after write: %d\n", errno);

    // Test ft_write with bad buffer
    errno = 0; // Reset errno before the call
    ret = ft_write(fd, NULL, ft_strlen(test_cases[0]));
    printf("ft_write with bad buffer (NULL): \t%d \n", ret);
    printf("errno after ft_write: %d\n", errno);

    // Test write with bad buffer
    errno = 0; // Reset errno before the call
    ret = write(fd, NULL, ft_strlen(test_cases[0]));
    printf("write with bad buffer (NULL): \t%d \n", ret);
    printf("errno after write: %d\n", errno);

    // Test ft_write with bad count
    errno = 0; // Reset errno before the call
    ret = ft_write(fd, test_cases[0], -1);
    printf("ft_write with bad count (-1): \t%d \n", ret);
    printf("errno after ft_write: %d\n", errno);

    // Test write with bad count
    errno = 0; // Reset errno before the call
    ret = write(fd, test_cases[0], -1);
    printf("write with bad count (-1): \t%d \n", ret);
    printf("errno after write: %d\n", errno);

}

void    test_ft_read()
{ 
}  

void    test_ft_strdup()
{
}

/// ----- MAIN ----- ////

int main(int argc, char **argv)
{

    char *parameter = argv[1];

    if(!strcmp(parameter, "ft_strlen"))
        test_ft_strlen();
    else if(!strcmp(parameter, "ft_strcpy"))
        test_ft_strcpy();
    else if (!strcmp(parameter, "ft_strcmp"))
        test_ft_strcmp();
   else if (!strcmp(parameter, "ft_write"))
        test_ft_write();
   else if (!strcmp(parameter, "ft_read"))
        test_ft_read();
   else if (!strcmp(parameter, "ft_strdup"))
        test_ft_strdup();
    else
        printf("Invalid parameter\n");
   
    
    
    return 0;
}
