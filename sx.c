//StreamXor
//not intended to be safe!
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char** argv){
  int inchar;
  int argi;
  int opt;
  int nskip=0;
  while(1){//handle options
    opt=getopt(argc,argv,"s:");
    if(-1==opt){
      break;
    }else if('s'==opt){//option: skip
      nskip=atoi(optarg);
    }//unknown options are handled by getopt
  }
  while((nskip--)>0){//skip the first several chars
    inchar=fgetc(stdin);
    if(feof(stdin)){
      exit(0);
    }else{
      fputc(inchar,stdout);
    }
  }
  while(optind<argc){//stream xor if there are stream numbers
    for(argi=optind; argi<argc; argi++){
      inchar=fgetc(stdin);
      if(feof(stdin)){
        exit(0);
      }else{
        fputc(inchar^atoi(argv[argi]), stdout);
      }
    }
  }
  return 0;
}
