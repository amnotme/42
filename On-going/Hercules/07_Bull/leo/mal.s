.name "mal"
.comment "we like wine"

entry:
  sti     r1, %:zork, %1
  sti     r1, %:totes, %1
  sti     r1, %:totes2, %1

live:
  st      r1, 400

totes:
  live    %42
  sti     r1, %:live, %1
  zjmp   %:totes

totes2:
  live    %42
  sti     r1, %:live, %1
  zjmp   %:totes2

zork:
  live    %42
  sti     r1, %:live, %1
  zjmp   %:totes
