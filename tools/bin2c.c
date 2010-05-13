// bin2c.c
//
// convert a binary file into a C source vector
//
// THE "BEER-WARE LICENSE" (Revision 3.1416):
// sandro AT sigala DOT it wrote this file. As long as you retain this notice you can do
// whatever you want with this stuff.  If we meet some day, and you think this stuff is
// worth it, you can buy me a beer in return.  Sandro Sigala
//
// syntax:  bin2c [-c] [-z] <input_file> <output_file>
//
//          -c    add the "const" keyword to definition
//          -z    terminate the array with a zero (useful for embedded C strings)
//
// examples:
//     bin2c -c myimage.png myimage_png.cpp
//     bin2c -z sometext.txt sometext_txt.cpp
//
// Silvio Quadri ... small changes. Add sufix and prefix parameters. 2010
 
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
 
#ifndef PATH_MAX
#define PATH_MAX 1024
#endif
 
int useconst = 0;
int zeroterminated = 0;
char* sufix = NULL;
char* prefix = NULL;
 
int myfgetc(FILE *f)
{
    int c = fgetc(f);
    if (c == EOF && zeroterminated)
    {
        zeroterminated = 0;
        return 0;
    }
    return c;
}
 
void process(const char *ifname, const char *ofname)
{
    FILE *ifile, *ofile;
    ifile = fopen(ifname, "rb");
    if (ifile == NULL)
    {
        fprintf(stderr, "cannot open %s for reading\n", ifname);
        exit(1);
    }

    if( strcmp( ofname, "-" ) == 0 ){
        ofile = stdout;
    } else {
        ofile = fopen(ofname, "wb");
        if (ofile == NULL)
        {
            fprintf(stderr, "cannot open %s for writing\n", ofname);
            exit(1);
        }
    }

    char buf[PATH_MAX], *p;
    const char *cp;
    if ((cp = strrchr(ifname, '/')) != NULL)
    {
        ++cp;
    } else {
        if ((cp = strrchr(ifname, '\\')) != NULL)
            ++cp;
        else
            cp = ifname;
    }
    strcpy(buf, cp);
    for (p = buf; *p != '\0'; ++p)
    {
        if (!isalnum(*p))
            *p = '_';
    }
    fprintf(ofile, "static %sunsigned char %s%s%s[] = {\n", useconst ? "const " : "", 
        prefix ? prefix : "", 
        buf,
        sufix ? sufix : "" );
    int c, col = 1, count = 0;
    while ((c = myfgetc(ifile)) != EOF)
    {
        if (col >= 78 - 6)
        {
            fputc('\n', ofile);
            col = 1;
        }
        fprintf(ofile, "0x%.2x, ", c);
        col += 6;
        count ++;
    }
    fprintf(ofile, "\n};\n");
    fprintf( ofile, "static %sunsigned int %s%s%s_size = %d;\n", useconst ? "const " : "", 
        prefix ? prefix : "", 
        buf, 
        sufix ? sufix : "", 
        count );
 
    fclose(ifile);
    fclose(ofile);
}
 
void usage(void)
{
    fprintf(stderr, "usage: bin2c [-cz] [-p prefix] [-s sufix] <input_file> <output_file>\n");
    exit(1);
}
 
int main(int argc, char **argv)
{
    int  opt;
    while(( opt = getopt( argc, argv, "czs:p:" )) != -1 ){
        switch(opt){
            case 'c':
                useconst = 1;
                break;
            case 'z':
                zeroterminated = 1;
                break;
            case 's':
                sufix = optarg;
                break;
            case 'p':
                prefix = optarg;
                break;
            default:
                usage();
        }
    }

    if( optind + 1 >= argc ){
        usage();
    }

    process(argv[optind], argv[optind + 1]);
    return 0;
}
