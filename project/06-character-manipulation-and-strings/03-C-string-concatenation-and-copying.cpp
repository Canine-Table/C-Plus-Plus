#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>


int main(int argc, char **argv){

    {

        char dest[50] {"Hello"};
        const char src[]{" World! "};

        // Concatenation
        std::strcat(dest,src);
        std::strcat(dest,"Goodbye World!");

        /*
            When using std::strcat you need to make sure the dest string is large enough to hold the concatenation.
        */

        std::cout
            << dest
            << std::endl;

    }

    /*
        Remember to put the null character at the end of the char array in order to terminate it.
        Null character will let you print to the terminal: '\0'

        std::strcat will start overriding up to the last null character
            'a','\0','b' + 'c','\0' = ac
    */

    {

        char *p_dest = new char[30] {'F','i','r','e','l','o','r','d','\0'};
        char *p_src = new char[30] {',',' ','T','h','e',' ','P','h','e','n','i','x',' ','K','i','n','g','!','\0'};

        std::strcat(p_dest,p_src);

        std::cout
            << p_dest
            << std::endl;

        delete p_dest;
        p_dest = nullptr;

        delete p_src;
        p_src = nullptr;

    }

    /*
        std::strncat:

            Concatenates n characters from src to dest and returns a pointer to the result string
            Signature:
                char *strncat(char *dest, const char *src, std::size_t count
    */

    {

        char n_dest[32] {'H','e','l','\0'};
        const char n_src[] {'l','o',' ','W','o','r','l','d','w','d','s','g','j','\0'};

        std::strncat(n_dest,n_src,8);

        std::cout
            << n_dest
            << std::endl;

    }

    /*
        std::strcpy:
            Signature:
                char *strcpy(char *dest, const char *src);
    */

    {

        const char *c_src {"C++ is a multipurpose programming language.\0"};
        char *c_dest {new char[std::strlen(c_src) + 1]}; // +1 for the null character, This contains garbage data because it has not been initialized just declared.

        std::strcpy(c_dest,c_src);

        std::cout
            << &c_dest
            << ": "
            << c_dest
            << "\n"
            << &c_src
            << ": "
            << c_dest
            << std::endl;

        delete c_dest;
        c_dest = nullptr;

    }

    /*
        std::strncpy:
            Copy n characters from src to dest
            Signature:
                char *strncpy(char *dest, const char *src, std::size_t count);
    */

    {

        char cn_src_1[] {'H','e','l','\0'};
        const char cn_src_2[] {'l','o',' ','W','o','r','l','d','w','6','s','a','s','\0'};
        std::strncat(cn_src_1,cn_src_2,12);

        char cn_dest[std::size(cn_src_1)];
        std::strncpy(cn_dest,cn_src_1,11);

        std::cout
            << &cn_dest
            << ": "
            << cn_dest
            << "\n"
            << &cn_src_1
            << ": "
            << cn_src_1
            << "\n"
            << &cn_src_2
            << ": "
            << cn_src_2
            << std::endl;

    }

    return 0;
}
