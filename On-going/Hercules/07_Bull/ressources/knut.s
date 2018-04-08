.name "knut"
.comment "Grob"

st r1, 6
live %00
ld %720, r2;
st r2, -19
ld %3489662465, r3
st r3, -28
ld %00, r2
zjmp %:fill
start:
ld %01, r10 ; 00 00 00 01
st r10, -330
st r1, -331
ld %190055686, r10 ; 0b 54 05 06
st r10, -339
ld %67763801, r10; 04 09 fe 59;%67763761, r10;%67763764, r10 ; 04 09 fe 31
st r10, -347
ld %00, r4
zjmp %-369
fill:
fork %:separator
live %0
fork %:second
live %0
ld %190054915, r2 ;0b540203
ld %-19, r3
ld %190056198, r5 ; 0b540706
ld %-410, r6;%-450, r6 ; dist
ld %190056454, r7 ; 0b 54 08 06
ld %190054915, r8 ; 0b 54 02 03
ld %00, r4
zjmp %:start
second:
live %0
ld %67764195, r2 ;04 09 ff a2
ld %-15, r3
ld %67763804, r5;%67763764, r5 ;04 09 fe 34
ld %-406, r6;%-446, r6 ; dist
ld %67763804, r7;04 09 fe 5c;%67763764, r7; 04 09 fe 34
ld %67764200, r8 ; 04 09 ff e8
ld %00, r4
zjmp %:start
separator:
live %0
fork %:fourth
live %0
ld -227, r2 ; le r1
ld %-23, r3 ;distance
ld -239, r5 ; le r1
ld %-414, r6;%-454, r6
ld -251, r7
ld -256, r8
ld %00, r4
zjmp %:start
fourth:
live %0
ld %01, r2
ld %-27, r3
ld %201432321, r5;0c 01 9d 01;%201442561, r5 ;0c 01 c5 01;%01, r5
ld %-418, r6;%-458, r6
ld %01, r7
ld %01, r8
ld %00, r4
zjmp %:start
