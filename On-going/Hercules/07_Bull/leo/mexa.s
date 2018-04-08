.name "Leo"
.comment "taco slayer"

entry:
	sti			r1, %:zork, %1
	sti			r1, %:ardef, %1
	sti			r1, %:avdef, %1
	sti			r1, %:entry_l1, %1

entry_l1:
	live		%42
	ld			%439025904, r2
	ld			%0, r16
	fork		%:avdef

zork:
	live		%42
	zjmp		%:zork


ardef:
	live		%42
	st			r2, -400
	zjmp		%:ardef


avdef:
	live		%42
	st			r2, 400
	zjmp		%:avdef
