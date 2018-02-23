#!/usr/bin/ruby

args = ARGV

def parse(str)
	days = ["lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"]
	months = ["janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "novembre", "decembre"]
	nums = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
	spaces = 0
	day = 0
	month = 0
	numbers = 0
	colons = 0
	spaces = str.count(' ')
	return (false) if spaces != 4
	narr = []
	nums = []
	narr = str.split(' ')
	narr = narr.map {|x| x.downcase}
	p narr
	narr.each do |x|
		day = 1 if days.include?(x)
		month = 1 if months.include?(x)
		if nums.include?(x)
			x.split('').each do |y|
				numbers = numbers + 1 if numbers.include?(y)
				colons = colons + 1 if y == ':'	
			end
		end
		if x.include?(':') && x.count(':') == 2
			nums = x.split(':')
			nums.each_with_index do |x, y|
				x = x.to_i
		puts "it'here 1"
				return false if y == 0 && (x < 0 || x > 23)
		puts "it'here 2"
				return false if y == 1 && (x < 0 || x > 59)
		puts "it'here 3"
				return false if y == 2 && (x < 0 || x > 59)
		puts "it'here"
			end
		end
	end
	return false if (day != 1 || month != 1 || (numbers != 11 || number != 12))
	narr[5] = nums[0]
	narr[6] = nums[1]
	narr[7] = nums[2]
	p narr
	return narr
end

if args.length == 1
	if parse(args[0]) == false
		puts "Wrong format!"
	else
		puts narr
	end
else
	print
end
