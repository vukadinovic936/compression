/*
 * @author Andrea C. G. Mennucci
 *
 * @file arith_simple.cc
 *
 * @copyright (C) 2010-2019 Andrea C. G. Mennucci
 *
 * The new BSD License is applied to this software, see LICENSE.txt
 *
 * The  simple program  compresses or decompresses standard input to standard output
 * it keeps an updated table of symbol frequencies
 *
 *
 * Note that the encoded file is actually a text file, where bits are written
 * as characters '0' and '1'
 */

#define AC_representation_bitsize 20

#include "arith_code.cc"

#include <functional>

#include <stdio.h>
#include "math.h"
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <inttypes.h>
#include <fstream>

// initialize the frequency tables supposing that the input is text
#define  TEXTLIKE_PROBABILITIES

// print table of frequencies
// #define PRINT_TABLE

//////////////////////////////////////////////////////////////////

const int  n_symbols=257, my_eof=256, freq_boost = 32;

int flag_eof=0;
void decoder_callback(int s, void *p)
{
  AC::Decoder * D =  (AC::Decoder *)p;
  assert( AC::NO_SYMBOL !=  s);
  s = s - AC::MIN_SYMBOL;
  if(flag_eof) {
    ; // may receive a FLUSH_SYMBOL here
  } else if( s != my_eof ) {
    // good symbol
  std::ofstream myfile;
  myfile.open ("decoded.txt", std::ios_base::app);
  myfile << (char) s;
  myfile.close();
  //fputc(s, stdout);

    // update the frequency table for next upcoming symbol
    D->frequencies[s] += freq_boost;
    // reduce the frequencies if too high for the encoder precision
    AC::renormalize_frequencies(D->frequencies, n_symbols);
    // update the cumulative_frequencies from the frequencies
    D->frequencies2cumulative_frequencies();
  } else {
    // we reached end of file
    flag_eof = 1;
    D->prepare_for_deflush();
  }
}

///////////////////////////////////////////////////////////////////////////////

void encoder_callback(	int b, void *p)
{
  std::ofstream myfile;
  myfile.open ("temp.zen", std::ios_base::app);
  myfile << b;
  myfile.close();
  //fputc(b+'0',stdout);
}


/////////////////////////////////////////////////////////////////////////////

int print_help(char *cmd)
{
  printf("Usage: %s flag \n\
\n\
The  simple program  compresses or decompresses standard input to standard output\n\
Note that the encoded output is actually text, where bits are written\n\
as characters '0' and '1'.\n\
\n\
Flags:\n\
  -C encode\n\
  -D decode\n\
", cmd);
    return 0;
}

#include "frequencies.cc"

#ifdef TEXTLIKE_PROBABILITIES
#define initialize_frequencies initialize_frequencies_dickens
#else
#define initialize_frequencies initialize_frequencies_nonnull
#endif

int
main(int argc, char * argv[])
{
  char *cmdname = argv[0];

  int check_n_arguments =  argc == 2  ;

  if ( ! check_n_arguments ) {
     print_help(cmdname);
     return 0;
   }

  // initialize frequency tables
  AC::F_t *cum_freq = new AC::F_t[n_symbols+1];
  AC::F_t *freq = new AC::F_t[n_symbols];
  initialize_frequencies(freq);
  AC::freq2cum_freq(cum_freq,freq,  n_symbols);

#ifdef PRINT_TABLE
  fprintf(stderr,"initial table\n");
  AC::print_table_cum_freq_ascii(freq, cum_freq, n_symbols, stderr);
#endif


  if ( 0==strcmp(argv[1] , "-C") ) {
    //////////////// ENCODER
    AC::Encoder *E = new AC::Encoder(encoder_callback) ;
    E -> verbose_stream = stderr;
    // store frequencies in encoder, for convenience
    E->frequencies = freq;
    E->cumulative_frequencies = cum_freq;
    E->max_symbol = n_symbols;
    int i;
    while(EOF !=  ( i = fgetc(stdin) )) {
      // input symbol in encoder (using frequencies stored inside encoder)
      E->input_symbol(i+AC::MIN_SYMBOL);
      // boost frequency of seen symbols
      E->frequencies[i] += freq_boost;
      // reduce the frequencies if too high for the encoder precision
      AC::renormalize_frequencies(E->frequencies, n_symbols);
      // update the cumulative_frequencies from the frequencies
      E->frequencies2cumulative_frequencies();
    }
    // send eof
    E->input_symbol(my_eof + AC::MIN_SYMBOL);
    E->flush();
    printf("\n");

    {
      uint64_t ns = E->number_input_symbols(), nb = E->number_output_bits();
      fprintf(stderr," input symbols %" PRIu64  " output bits %" PRIu64  ",\n ratio %f bits per symbol\n",
	      ns,nb,(double)nb/(double)ns);
    }
    /////////////////// end of encoder code
  } else   if ( 0==strcmp(argv[1] , "-D") ) {
    //////////////////// DECODER
    AC::Decoder * D= new AC::Decoder(decoder_callback);
    D -> verbose_stream = stderr;
    // we must store frequencies in decoder, since the decoder
    // must know them in advance for each symbol that it is trying to decode
    D->frequencies = freq;
    D->cumulative_frequencies = cum_freq;
    D->max_symbol = n_symbols;
    int b;
    while(EOF !=  ( b = fgetc(stdin) ) ) {
      if( b == '0' || b == '1')
	D->input_bit(b-'0');
      else if (b>=32 && b <= 126)
	fprintf(stderr, "input '%c' ignored\n", b);
    }
    if(!flag_eof)
      fprintf(stderr,"\n*** internal error, did not receive EOF, \n");
    ////////////////
  } else {
    fprintf(stderr,"Unrecognized option: %s\n\n",argv[1]);
    print_help(cmdname);
    return(-1);
  }

#ifdef PRINT_TABLE
  fprintf(stderr,"*******\nfinal table\n");
  AC::print_table_cum_freq_ascii(freq, cum_freq, n_symbols, stderr);
#endif

  return 0;
}
