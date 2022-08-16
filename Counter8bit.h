#include "systemc.h"
SC_MODULE(Counter8bit){
      sc_in_clk clock;
      sc_in<bool>  reset;
      sc_in<bool>  enable;
      sc_out<sc_uint<8> > counter_out;

      sc_uint<8> count;
      void incr_count (){

          while (true){
              if (enable.read() == true){
                  if (reset.read() == true){
                      count = 0;
                      counter_out.write(count);
                  }
              
                  else {
                      count = count + 1;
                      counter_out.write (count);
                  }
              }
              wait();
          }
      }
          SC_CTOR(Counter8bit){
              SC_THREAD(incr_count);
              sensitive << clock.pos();
              count = 0;
          }
  
};