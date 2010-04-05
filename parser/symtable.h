/*
  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.
  Silvio Quadri 2009.
*/

#ifndef   SYMTABLE_H
#define   SYMTABLE_H

typedef  void*  symtable;

symtable*  symtable_init( );
void       symtable_free( symtable* sym);
int        symtable_addsym( symtable* sym, char* name );
int        symtable_adddef( symtable* sym, char* name, int argc, char** argv, char* def );
int        symtable_delsym( symtable* sym, char* name );

int        symtable_exists( symtable* sym, char* name );
int        symtable_argc  ( symtable* sym, char* name );

int        symtable_resolve( symtable* sym, char* name, int argc, char** argv, char** result );



#endif
