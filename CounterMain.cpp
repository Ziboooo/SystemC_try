#include "TestbenchDesign1.h"
#include "Counter8bit.h"
#include "Adder.h"

SC_MODULE(CounterMain){
    sc_clock clock;
    sc_signal<bool> reset_s, enable_s;
    sc_signal<sc_uint<8> > counter_out_s;
    sc_signal <sc_logic> A_s,B_s,CIN_s;
    sc_signal<sc_logic> SUM_s,COUT_s;
    sc_signal <sc_logic> error_s;

    Adder adder1;
    Counter8bit counter;
    TestbenchDesign1 test1;

    //sc_clock clock("SystemClock", 2, 0.5, true),
SC_CTOR(CounterMain): clock("SystemClock", 10, 0.5, true), counter("Counter1"),test1("Test1"), adder1("BitAdder1"){

            adder1.A(A_s);
            adder1.B(B_s);
            adder1.Cin(CIN_s);
            adder1.sum(SUM_s);
            adder1.Cout(COUT_s);

            test1.clock(clock);
            test1.TA(A_s);
            test1.TB(B_s);
            test1.TCin(CIN_s);
            test1.TSum(SUM_s);
            test1.TCout(COUT_s);
            test1.error(error_s);
            test1.reset(reset_s);
            test1.enable(enable_s);


        counter.clock(clock);
        counter.reset(reset_s);
        counter.enable(enable_s);
        counter.counter_out(counter_out_s);


    }
};
SC_MODULE_EXPORT(CounterMain);
