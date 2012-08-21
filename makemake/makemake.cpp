#include <iostream>
#include <cstdlib>
#include <cstring>

#include "dirlist.h"
#include "write.h"

bool debug( false );

int main( int argc, char **argv ){
  string header_file( "header.mak" );
  string programs_file( "programs.mak" );

  // Flag indicates whether the CCFLAGS and CFLAGS output should
  // have -g debugging option omitted
  bool noDebugFlag( false );

  // Flag indicates using gnu compiler
  // bool useGCC = false;
  bool useGCC = true;

  // check gnu compiler make or sun compiler make
  // if first letter of executable is 'g' then gnu otherwise sun

  char *exename = argv[0];
  char c;

  while((c = *exename++)) {
    if(c == '/') {
      argv[0] = exename;
    }
  }
  if(argv[0][0] == 'g') {
    useGCC = true;
  }

  //
  // Process command line options
  //
  while( argc--, *++argv != 0 && **argv == '-' ){
    if( strcmp( *argv, "-header" ) == 0 && argv[ 1 ] != 0 ){
      header_file = *++argv;
      argc--;
    } else if( strcmp( *argv, "-no-header" ) == 0 ){
      header_file = "//";
    } else if( strcmp( *argv, "-programs" ) == 0 && argv[ 1 ] != 0 ){
      programs_file = *++argv;
      argc--;
    } else if( strcmp( *argv, "-no-programs" ) == 0 ){
      programs_file = "//";
    } else if(strcmp("-no-debug",*argv) == 0){
      noDebugFlag = true;
    } else {
      switch( *++*argv ){
      case 'd':
        debug = true;
        break;

      default:
        cerr << "Invalid option: -" << **argv << endl;
        exit( 1 );
      }
    }
  }

  //
  // Read the current directory (and cmd line arguments) to find 
  // file names.
  //
  DirList dirlist( argc, argv );

  //
  // Now write the makefile
  //
  Write write( dirlist, noDebugFlag, useGCC, header_file, programs_file );

  return 0;
}
