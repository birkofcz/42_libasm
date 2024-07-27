/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 13:00:22 by sbenes            #+#    #+#             */
/*   Updated: 2024/07/27 10:53:40 by sbenes           ###   ########.fr       */
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

// Test cases

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
    printf(BOLD "\n:::::: ft_strlen ::::::\n\n" RESET);

    printf(BOLD "size_t ft_strlen(const char *s);\n\n" RESET);
    
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        printf(YELLOW "Test case: [%s]\n" RESET, test_cases[i]);
        printf("ft_strlen: \t%zu \n", ft_strlen(test_cases[i]));
        printf("strlen: \t%zu \n", strlen(test_cases[i]));
        if (ft_strlen(test_cases[i]) != strlen(test_cases[i]))
            printf("Result: " RED "failed\n\n" RESET);
        else
            printf("Result: " GREEN "OK" RESET "\n\n");    
    }

    printf(YELLOW "\nTest case with user input\n" RESET);
    printf("Input string: ");
    char *input = (char *)malloc(100);
    scanf("%s", input);
    printf("ft_strlen: \t%zu \n", ft_strlen(input));
    printf("strlen: \t%zu \n", strlen(input));
    if (ft_strlen(input) != strlen(input))
        printf("Result: " RED "failed\n\n" RESET);
    else
        printf("Result: " GREEN "OK" RESET "\n\n");
    free(input);

    printf("\n");
}

void    test_ft_strcpy()
{
    printf(BOLD "\n:::::: ft_strcpy ::::::\n\n" RESET);

    printf(BOLD "char* ft_strcpy(char *dst, const char *src);\n\n" RESET);
    
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        char destination[ft_strlen(test_cases[i])];
        printf(YELLOW "Test case: [%s]\n" RESET, test_cases[i]);
        printf("ft_strcpy: \t%s \n", ft_strcpy(destination, test_cases[i]));
        printf("strcpy: \t%s \n", strcpy(destination, test_cases[i]));
        if (ft_strlen(test_cases[i]) != strlen(test_cases[i]))
            printf("Result: " RED "failed\n\n" RESET);
        else
            printf("Result: " GREEN "OK" RESET "\n\n");
        
    }

    printf(YELLOW "\nTest case with user input\n" RESET);
    printf("Input string: ");
    char *input = (char *)malloc(100);
    scanf("%s", input);
    char destination[ft_strlen(input)];
    printf("ft_strcpy: \t%s \n", ft_strcpy(destination, input));
    printf("strcpy: \t%s \n", strcpy(destination, input));
    if (ft_strlen(input) != strlen(input))
        printf("Result: " RED "failed\n\n" RESET);
    else
        printf("Result: " GREEN "OK" RESET "\n\n");
    free(input);

    printf("\n");
}

void    test_ft_strcmp()
{

    printf(BOLD "\n:::::: ft_strcmp ::::::\n\n" RESET);

    printf(BOLD "int ft_strcmp(const char *s1, const char *s2);\n\n" RESET);
    
    char *first = "ahoj";
    char *second = "aho";

    printf(YELLOW "Test case: [%s] // [%s]\n" RESET, first, second);
    printf("ft_strcmp: %d\n", ft_strcmp(first, second));
    printf("strcmp: %d\n", strcmp(first, second));
    if (ft_strcmp(first, second) != strcmp(first, second))
        printf("Result: " RED "failed\n\n" RESET);
    else
        printf("Result: " GREEN "OK" RESET "\n\n");


    printf(YELLOW "\nTest case with user input\n" RESET);
    printf("Input first string: ");
    char *first_input = (char *)malloc(100);
    scanf("%s", first_input);
    printf("Input second string: ");
    char *second_input = (char *)malloc(100);
    scanf("%s", second_input);
    printf("ft_strcmp: %d\n", ft_strcmp(first_input, second_input));
    printf("strcmp: %d\n", strcmp(first_input, second_input));
    if (ft_strcmp(first_input, second_input) != strcmp(first_input, second_input))
        printf("Result: " RED "failed\n\n" RESET);
    else
        printf("Result: " GREEN "OK" RESET "\n\n");
    free(first_input);
    free(second_input);


    printf(YELLOW "\nTest case with empty strings\n" RESET);
    first = "";
    second = "";
    printf("ft_strcmp: %d\n", ft_strcmp(first, second));   
    printf("strcmp: %d\n", strcmp(first, second));
    if (ft_strcmp(first, second) != strcmp(first, second))
        printf("Result: " RED "failed\n\n" RESET);
    else
        printf("Result: " GREEN "OK" RESET "\n\n");

    printf("\n");

}

void    test_ft_write()
{
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);
    int fd = 1;
    int ret1, ret2 = 0;

    printf(BOLD "\n:::::: ft_write ::::::\n\n" RESET);

    printf(BOLD "ssize_t ft_write(int fd, const void *buf, size_t count);\n\n" RESET);
    
    
    for (int i = 0; i < case_nr; i++)
    {
        printf(YELLOW "Test case: [%s]" RESET, test_cases[i]);
        printf("\n");
        ret1 = ft_write(fd, test_cases[i], ft_strlen(test_cases[i]));
        printf("\nft_write: \t%d \n", ret1);
        ret2 = write(fd, test_cases[i], ft_strlen(test_cases[i]));
        printf("\nwrite: \t%d \n", ret2);
        if (ret1 != ret2)
            printf(" Result: " RED "failed\n\n" RESET);
        else
            printf(" Result: " GREEN "OK" RESET "\n\n");
    }
   
   // bad input test suite:
    printf(RED "Bad input test suite:\n" RESET);

    // Test ft_write with bad fd
    errno = 0; // Reset errno before the call
    ret1 = ft_write(-1, test_cases[0], ft_strlen(test_cases[0]));
    printf("ft_write with bad fd (-1): \t%d \n", ret1);
    printf(YELLOW "errno" RESET " after ft_write: %d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    // Test write with bad fd
    errno = 0; // Reset errno before the call
    ret2 = write(-1, test_cases[0], ft_strlen(test_cases[0]));
    printf("write with bad fd (-1): \t%d \n", ret2);
    printf(YELLOW "errno" RESET " after write: %d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    // Test ft_write with bad buffer
    errno = 0; // Reset errno before the call
    ret1 = ft_write(fd, NULL, ft_strlen(test_cases[0]));
    printf("\nft_write with bad buffer (NULL): \t%d \n", ret1);
    printf(YELLOW "errno" RESET " after ft_write: %d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    // Test write with bad buffer
    errno = 0; // Reset errno before the call
    ret2 = write(fd, NULL, ft_strlen(test_cases[0]));
    printf("write with bad buffer (NULL): \t%d \n", ret2);
    printf(YELLOW "errno" RESET " after write: %d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));


    // Test ft_write with bad count
    errno = 0; // Reset errno before the call
    ret1 = ft_write(fd, test_cases[0], -1);
    printf("\nft_write with bad count (-1): \t%d \n", ret1);
    printf(YELLOW "errno" RESET " after ft_write: %d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    // Test write with bad count
    errno = 0; // Reset errno before the call
    ret2 = write(fd, test_cases[0], -1);
    printf("write with bad count (-1): \t%d \n", ret2);
    printf(YELLOW "errno" RESET " after write: %d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    printf("\n");   

}

void    test_ft_read()

{ 
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);
    int fd = 0;
    int ret;
    char buffer[100];

    printf(BOLD "\n:::::: ft_read ::::::\n\n" RESET);

    printf(BOLD "ssize_t ft_read(int fd, void *buf, size_t count);\n\n" RESET);

    printf(YELLOW "\nfile reading test: test.txt\n\n" RESET);
    //Test read with file
    int file = open("test.txt", O_RDONLY);
    ret = read(file, buffer, 100);
    printf("read with file: \t%d \n", ret);
    printf("buffer: %s\n", buffer);
    close(file);
    //Test ft_read with file
    file = open("test.txt", O_RDONLY);
    ret = ft_read(file, buffer, 100);
    printf("ft_read with file: \t%d \n", ret);
    printf("buffer: %s\n", buffer);
    close(file);
    
    
    // bad input test suite:
    printf(RED "\nBad input test suite:\n\n" RESET);

    // Test ft_read with bad fd
    errno = 0; // Reset errno before the call
    ret = ft_read(-1, buffer, ft_strlen(test_cases[0]));
    printf("ft_read with bad fd (-1): \t%d \n", ret);
    printf(YELLOW "errno" RESET " after ft_read: \t%d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    // Test read with bad fd
    errno = 0; // Reset errno before the call
    ret = read(-1, buffer, ft_strlen(test_cases[0]));
    printf("read with bad fd (-1): \t%d \n", ret);
    printf(YELLOW "errno" RESET " after read: \t%d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));

    // Test ft_read with bad count
    errno = 0; //
    ret = ft_read(fd, buffer, -1);
    printf("\nft_read with bad count (-1): \t%d \n", ret);
    printf(YELLOW "errno" RESET " after ft_read: \t%d\n", errno);
    printf("EVAL: errno in strerror: %s\n", strerror(errno));
    
    // Test read with bad count
    errno = 0; // Reset errno before the call
    ret = read(fd, buffer, -1);
    printf("read with bad count (-1): \t%d \n", ret);
    printf(YELLOW "errno" RESET " after read: \t%d\n", errno); 
    printf("EVAL: errno in strerror: %s\n", strerror(errno));


    printf(YELLOW "\nSTDIN (FD = 0) reading test. Enter some content twice:" RESET "\n ");

    //Test ft_read with stdin
    //reset buffer
    memset(buffer, 0, 100);
    ret = ft_read(fd, buffer, 100);
    printf("ft_read with stdin: \t%d \n", ret);
    printf("buffer: %s\n", buffer);

    //Test read with stdin
    //reset buffer
    memset(buffer, 0, 100);
    ret = read(fd, buffer, 100);
    printf("read with stdin: \t%d \n", ret);
    printf("buffer: %s\n", buffer);

    printf("\n");
}

void    test_ft_strdup()
{
    printf(BOLD "\n:::::: ft_strdup ::::::\n\n" RESET);
    
    int case_nr = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < case_nr; i++)
    {
        printf(YELLOW "Test case: [%s]\n" RESET, test_cases[i]);
        char *ret = ft_strdup(test_cases[i]);
        printf("ft_strdup: \t%s \n", ret);
        char *ret2 = strdup(test_cases[i]);
        printf("strdup: \t%s \n", ret2);
        if (strcmp(ret, ret2))
            printf("Result: " RED "failed\n\n" RESET);
        else
            printf("Result: " GREEN "OK" RESET "\n\n");
        
    }

    printf(YELLOW "\nTest case with user input\n" RESET);
    printf("Input string: ");
    char *input = (char *)malloc(100);
    scanf("%s", input);
    char *ret = ft_strdup(input);
    printf("ft_strdup: \t%s \n", ret);
    char *ret2 = strdup(input);
    printf("strdup: \t%s \n", ret2);
    if (strcmp(ret, ret2))
        printf("Result: " RED "failed\n\n" RESET);
    else
        printf("Result: " GREEN "OK" RESET "\n\n");

    free(input);

    printf("\n");
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
