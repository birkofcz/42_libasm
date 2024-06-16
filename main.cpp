/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:56:50 by sbenes            #+#    #+#             */
/*   Updated: 2024/06/16 16:48:11 by sbenes           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "include/libasm.h"

#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>

//extern int  errno;

void test_ft_strlen();
/* void test_ft_strcpy();
void test_ft_strcmp();
void test_ft_write();
void test_ft_read();
void test_ft_strdup(); */

using function_pointer = void (*)();

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

class Test
{
    private:
        string parameter;
        map<string, void (*)()> test_functions;


};

void test_ft_strlen()
{
    std::cout << ":::::: ft_strlen ::::::" << std::endl << std::endl;
    
    const char *test_cases[] = {
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
};
    
int main(int argc, char **argv)
{
    return 0;
};