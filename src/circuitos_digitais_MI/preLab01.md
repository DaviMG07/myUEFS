# Pré Lab 01

## a)

cada LE possui dois modos de operação: "Normal mode" e "Dynamic Arithmetic Mode"

diferenças:

Normal mode é ideal para aplicações lógicas gerais e funções combinacionais, enquanto que Dynamic Arithmetic Mode é ideal para operações aritméticas como somadoras, contadores, comparadores, acumuladoras e funções de paridade de múltiplos bits;
Normal mode utiliza  

Normal Mode
The normal mode is suitable for general logic applications and combinational
functions. In normal mode, four data inputs from the LAB local interconnect are
inputs to a four-input LUT (see Figure 2–7). The Quartus II Compiler automatically
selects the carry-in or the data3 signal as one of the inputs to the LUT. Each LE can use
LUT chain connections to drive its combinational output directly to the next LE in the
LAB. Asynchronous load data for the register comes from the data3 input of the LE.
LEs in normal mode support packed registers.

Dynamic Arithmetic Mode
The dynamic arithmetic mode is ideal for implementing adders, counters,
accumulators, wide parity functions, and comparators. An LE in dynamic arithmetic
mode uses four 2-input LUTs configurable as a dynamic adder/subtractor. The first
two 2-input LUTs compute two summations based on a possible carry-in of 1 or 0; the
other two LUTs generate carry outputs for the two chains of the carry-select circuitry.
As shown in Figure 2–8, the LAB carry-in signal selects either the carry-in0 or
carry-in1 chain. The selected chain’s logic level in turn determines which parallel sum
is generated as a combinational or registered output. For example, when
implementing an adder, the sum output is the selection of two possible calculated
sums:
data1 + data2 + carry in0
or
data1 + data2 + carry-in1
The other two LUTs use the data1 and data2 signals to generate two possible carry-out
signals: one for a carry of 1 and the other for a carry of 0. The carry-in0 signal acts
as the carry-select for the carry-out0 output and carry-in1 acts as the carry-
select for the carry-out1 output. LEs in arithmetic mode can drive out registered
and unregistered versions of the LUT output.
The dynamic arithmetic mode also offers clock enable, counter enable, synchronous
up/down control, synchronous clear, synchronous load, and dynamic
adder/subtractor options. The LAB local interconnect data inputs generate the
counter enable and synchronous up/down control signals. The synchronous clear
and synchronous load options are LAB-wide signals that affect all registers in the
LAB. The Quartus II software automatically places any registers that are not used by
the counter into other LABs. The addnsub LAB-wide signal controls whether the LE
acts as an adder or subtractor.


## b)

240

## c)

10

## d)

4
