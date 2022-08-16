
#include "systemc.h"

SC_MODULE(TestbenchDesign1){
      sc_in_clk clock;
      sc_out<sc_logic> TA,TB,TCin;
      sc_out<sc_logic> error;
      sc_in<sc_logic> TSum, TCout;
      sc_out<bool> enable, reset;

      void testprocess(){
          error.write(SC_LOGIC_0);
          enable.write(true);
          reset.write(true);
          wait(); // reset the counter
          enable.write(false);
          reset.write(false);
           // CHECK 000
          TA.write(SC_LOGIC_0);
          TB.write(SC_LOGIC_0);
          TCin.write(SC_LOGIC_0);
          wait();
          if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_0)
                 {error.write(SC_LOGIC_0);
                 enable.write(false);}
                  
          else 
                 {error.write(SC_LOGIC_1); enable.write(true);}
         

          // check 110
          TA.write(SC_LOGIC_1);
          TB.write(SC_LOGIC_1);
          TCin.write(SC_LOGIC_0);
          wait();
          if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1)
                    {error.write(SC_LOGIC_0);enable.write(false);}
          else
                    {error.write(SC_LOGIC_1);enable.write(true);}
          
 
          //check 100
          TA.write(SC_LOGIC_1);
          TB.write(SC_LOGIC_0);
          TCin.write(SC_LOGIC_0);
           wait();
          if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0)
                    {error.write(SC_LOGIC_0);enable.write(false);}
          else
                    {error.write(SC_LOGIC_1);enable.write(true);}



          //check 001
          TA.write(SC_LOGIC_0);
          TB.write(SC_LOGIC_0);
          TCin.write(SC_LOGIC_1);
           wait();
          if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0)
                    {error.write(SC_LOGIC_0);enable.write(false);}
          else
                    {error.write(SC_LOGIC_1);enable.write(true);}


          //check 101
          TA.write(SC_LOGIC_1);
          TB.write(SC_LOGIC_0);
          TCin.write(SC_LOGIC_1);
        wait();
          if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1)
                    {error.write(SC_LOGIC_0);enable.write(false);}
          else
                    {error.write(SC_LOGIC_1);enable.write(true);}

          
          //check 111
          TA.write(SC_LOGIC_1);
          TB.write(SC_LOGIC_1);
          TCin.write(SC_LOGIC_1);
               wait();
          if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_1)
                    {error.write(SC_LOGIC_0);enable.write(false);}
          else
                    {error.write(SC_LOGIC_1);enable.write(true);}

      }
SC_CTOR(TestbenchDesign1)
	{SC_THREAD(testprocess);
         sensitive << clock.pos();
}
};