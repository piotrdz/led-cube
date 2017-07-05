v 20130925 2
C 40000 40000 0 0 0 title-B.sym
C 45800 42800 1 0 0 8052basic-1.sym
{
T 46100 49950 5 10 0 0 0 0 1
footprint=DIP40
T 49100 49100 5 10 1 1 0 6 1
refdes=U1
T 46100 49350 5 10 0 0 0 0 1
device=8052
}
C 43200 46100 1 0 0 switch-pushbutton-nc-1.sym
{
T 42750 45900 5 10 0 0 0 0 1
device=SWITCH_PUSHBUTTON_NC
}
C 44100 45300 1 180 0 diode-1.sym
{
T 43700 44700 5 10 0 0 180 0 1
device=DIODE
T 43500 45400 5 10 1 1 0 0 1
value=1N48
}
C 43200 42200 1 90 0 capacitor-4.sym
{
T 42100 42400 5 10 0 0 90 0 1
device=POLARIZED_CAPACITOR
T 42500 42400 5 10 0 0 90 0 1
symversion=0.1
T 43400 42300 5 10 1 1 90 0 1
value=10uF
}
C 44500 46200 1 270 0 resistor-2.sym
{
T 44850 45800 5 10 0 0 270 0 1
device=RESISTOR
T 44700 45500 5 10 1 1 0 0 1
value=10k
}
N 43000 43100 43000 46200 4
N 44200 46200 45800 46200 4
C 42500 41500 1 0 0 vcc-1.sym
C 44500 44700 1 0 0 gnd-1.sym
N 44600 45000 44600 45300 4
N 43000 41500 43000 42200 4
N 44600 45100 44100 45100 4
C 43600 43100 1 0 0 capacitor-1.sym
{
T 43800 43800 5 10 0 0 0 0 1
device=CAPACITOR
T 43800 44000 5 10 0 0 0 0 1
symversion=0.1
T 44100 43400 5 10 1 1 0 0 1
value=33pF
}
C 43600 42400 1 0 0 capacitor-1.sym
{
T 43800 43100 5 10 0 0 0 0 1
device=CAPACITOR
T 43800 43300 5 10 0 0 0 0 1
symversion=0.1
T 44100 42700 5 10 1 1 0 0 1
value=33pF
}
C 45200 42600 1 90 0 crystal-1.sym
{
T 44700 42800 5 10 0 0 90 0 1
device=CRYSTAL
T 44500 42800 5 10 0 0 90 0 1
symversion=0.1
T 44800 42300 5 10 1 1 0 0 1
value=11.0592MHz
}
N 44500 43300 45800 43300 4
N 44500 42600 45600 42600 4
C 43500 42000 1 0 0 gnd-1.sym
N 43600 42300 43600 43300 4
N 45600 43000 45600 42600 4
C 50400 45500 1 0 0 74573-1.sym
{
T 50700 49250 5 10 0 0 0 0 1
device=74573
T 52100 49100 5 10 1 1 0 6 1
refdes=U3
T 50700 49450 5 10 0 0 0 0 1
footprint=DIP20
}
N 50400 48700 49400 48700 4
N 50400 48400 49400 48400 4
N 50400 48100 49400 48100 4
N 50400 47800 49400 47800 4
N 50400 47500 49400 47500 4
N 50400 47200 49400 47200 4
N 50400 46900 49400 46900 4
N 50400 46600 49400 46600 4
N 49400 45800 50400 45700 4
N 53300 46600 52400 46600 4
N 53300 46900 52400 46900 4
N 53300 47200 52400 47200 4
N 53300 47500 52400 47500 4
N 53300 47800 52400 47800 4
N 53300 48100 52400 48100 4
N 53300 48400 52400 48400 4
N 53300 48700 52400 48700 4
N 49400 43000 53300 46300 4
N 49400 43300 53300 46000 4
N 49400 43600 53300 45700 4
N 49400 43900 53300 45400 4
N 49400 44200 53300 45100 4
N 49400 44500 53300 44800 4
N 49400 44800 53300 44500 4
N 50300 48700 50300 49600 4
N 50300 49600 56100 49600 4
N 56100 49600 56100 48700 4
N 56100 48700 55900 48700 4
N 50200 48400 50200 49700 4
N 50200 49700 56200 49700 4
N 56200 49700 56200 48400 4
N 56200 48400 55900 48400 4
N 50100 48100 50100 49800 4
N 50100 49800 56300 49800 4
N 56300 49800 56300 48100 4
N 56300 48100 55900 48100 4
N 50000 47800 50000 49900 4
N 50000 49900 56400 49900 4
N 56400 49900 56400 47800 4
N 56400 47800 55900 47800 4
N 49900 47500 49900 50000 4
N 49900 50000 56500 50000 4
N 56500 50000 56500 47500 4
N 56500 47500 55900 47500 4
N 49800 47200 49800 50100 4
N 49800 50100 56600 50100 4
N 56600 50100 56600 47200 4
N 56600 47200 55900 47200 4
C 50000 46100 1 270 0 gnd-1.sym
N 50300 46000 50400 46000 4
C 49800 46100 1 90 0 gnd-1.sym
N 49500 46200 49400 46200 4
N 49700 46900 49700 50200 4
N 49700 50200 56700 50200 4
N 56700 50200 56700 46900 4
N 56700 46900 55900 46900 4
N 49600 46600 49600 50300 4
N 49600 50300 56800 50300 4
N 56800 50300 56800 46600 4
N 56800 46600 55900 46600 4
C 53200 43900 1 90 0 vcc-1.sym
N 53300 43800 53100 43800 4
N 51100 43500 53300 43500 4
N 51100 43500 49600 45400 4
N 49600 45400 49400 45400 4
N 53100 43500 53100 43800 4
C 53300 43300 1 0 0 62256-1.sym
{
T 53600 49250 5 10 0 0 0 0 1
device=62256
T 55600 49100 5 10 1 1 0 6 1
refdes=U4
T 53600 49650 5 10 0 0 0 0 1
footprint=DIP28
}
N 53200 44100 53300 44100 4
N 45600 43000 45800 43000 4
C 45400 44600 1 180 0 output-1.sym
{
T 45300 44300 5 10 0 0 180 0 1
device=OUTPUT
T 43600 44400 5 10 1 1 0 0 1
value=LATCH_OE
}
C 45400 44300 1 180 0 output-1.sym
{
T 45300 44000 5 10 0 0 180 0 1
device=OUTPUT
T 43600 44100 5 10 1 1 0 0 1
value=LATCH_LE
}
N 45400 44500 45800 44500 4
N 45400 44200 45800 44200 4
C 45800 48800 1 180 0 output-1.sym
{
T 45700 48500 5 10 0 0 180 0 1
device=OUTPUT
T 44600 48600 5 10 1 1 0 0 1
value=P1.0
}
C 44500 50400 1 0 0 vcc-1.sym
C 46600 50300 1 90 0 gnd-1.sym
C 41900 46900 1 0 0 max232-1.sym
{
T 42200 49950 5 10 0 0 0 0 1
device=MAX232
T 42200 50150 5 10 0 0 0 0 1
footprint=DIP16
T 44200 49800 5 10 1 1 0 6 1
refdes=U1
}
C 45000 50200 1 0 0 capacitor-4.sym
{
T 45200 51300 5 10 0 0 0 0 1
device=POLARIZED_CAPACITOR
T 45200 50900 5 10 0 0 0 0 1
symversion=0.1
T 45000 50200 5 10 0 1 0 0 1
footprint=RCY100P
T 45000 50100 5 10 1 1 0 0 1
value=1uF
}
C 41500 49500 1 180 0 capacitor-4.sym
{
T 41300 48400 5 10 0 0 180 0 1
device=POLARIZED_CAPACITOR
T 41300 48800 5 10 0 0 180 0 1
symversion=0.1
T 41500 49500 5 10 0 1 0 0 1
footprint=RCY100P
T 40700 48900 5 10 1 1 0 0 1
value=1uF
}
C 41700 50500 1 0 0 capacitor-4.sym
{
T 41900 51600 5 10 0 0 0 0 1
device=POLARIZED_CAPACITOR
T 41900 51200 5 10 0 0 0 0 1
symversion=0.1
T 41700 50500 5 10 0 1 0 0 1
footprint=RCY100P
T 41700 50500 5 10 1 1 0 0 1
value=1uF
}
C 40600 47100 1 0 0 capacitor-4.sym
{
T 40800 48200 5 10 0 0 0 0 1
device=POLARIZED_CAPACITOR
T 40800 47800 5 10 0 0 0 0 1
symversion=0.1
T 40600 47100 5 10 0 1 0 0 1
footprint=RCY100P
T 40600 47100 5 10 1 1 0 0 1
value=1uF
}
N 44700 50400 45000 50400 4
N 46300 50400 45900 50400 4
N 41900 49300 41500 49300 4
N 41900 48700 40400 48700 4
N 40400 48700 40400 49300 4
N 40600 49300 40400 49300 4
C 40700 47900 1 0 0 capacitor-4.sym
{
T 40900 49000 5 10 0 0 0 0 1
device=POLARIZED_CAPACITOR
T 40900 48600 5 10 0 0 0 0 1
symversion=0.1
T 40700 47900 5 10 0 1 0 0 1
footprint=RCY100P
T 40700 47900 5 10 1 1 0 0 1
value=1uF
}
N 41900 48100 41600 48100 4
N 41900 48400 40400 48400 4
N 40400 48400 40400 48100 4
N 40700 48100 40400 48100 4
C 43100 50600 1 90 0 gnd-1.sym
N 41900 49000 41600 49000 4
N 41600 49000 41600 50700 4
N 41500 47300 41500 47800 4
N 41900 47800 41500 47800 4
C 40100 47400 1 270 0 gnd-1.sym
N 40400 47300 40600 47300 4
N 42800 50700 42600 50700 4
N 44500 47500 44600 47500 4
N 44600 47500 45400 45400 4
N 45400 45400 45800 45400 4
N 45800 45700 45100 45700 4
N 45100 45700 44500 47200 4
C 40400 42000 1 0 0 DB9-1.sym
{
T 41400 44900 5 10 0 0 0 0 1
device=DB9
}
N 41600 44100 41900 44100 4
N 41900 44100 41900 47200 4
N 41600 43500 41800 43500 4
N 41800 43500 41800 47500 4
N 41800 47500 41900 47500 4
C 41700 41500 1 0 0 gnd-1.sym
N 41600 42300 41800 42300 4
N 41800 42300 41800 41800 4
C 45800 48500 1 180 0 output-1.sym
{
T 45700 48200 5 10 0 0 180 0 1
device=OUTPUT
T 44600 48300 5 10 1 1 0 0 1
value=P1.1
}
C 45800 48200 1 180 0 output-1.sym
{
T 45700 47900 5 10 0 0 180 0 1
device=OUTPUT
T 44600 48000 5 10 1 1 0 0 1
value=P1.2
}
C 45800 47900 1 180 0 output-1.sym
{
T 45700 47600 5 10 0 0 180 0 1
device=OUTPUT
T 44600 47700 5 10 1 1 0 0 1
value=P1.3
}
C 45800 47600 1 180 0 output-1.sym
{
T 45700 47300 5 10 0 0 180 0 1
device=OUTPUT
T 44600 47400 5 10 1 1 0 0 1
value=P1.4
}
C 45800 47300 1 180 0 output-1.sym
{
T 45700 47000 5 10 0 0 180 0 1
device=OUTPUT
T 44600 47100 5 10 1 1 0 0 1
value=P1.5
}
C 45800 47000 1 180 0 output-1.sym
{
T 45700 46700 5 10 0 0 180 0 1
device=OUTPUT
T 44600 46800 5 10 1 1 0 0 1
value=P1.6
}
C 45800 46700 1 180 0 output-1.sym
{
T 45700 46400 5 10 0 0 180 0 1
device=OUTPUT
T 44600 46500 5 10 1 1 0 0 1
value=P1.7
}
N 42700 41500 43000 41500 4
N 43200 46200 43000 46200 4
N 43200 45100 43000 45100 4
N 41600 50700 41700 50700 4
