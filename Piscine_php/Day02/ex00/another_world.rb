#!/usr/bin/ruby
arr = ARGV
count =  arr.length
def my_special_trim(arr)
	res = []
	arr.split(' ').each do |x|
		arr2 = []
		if (x != '\t' && x != ' ')
			arr2 << x
		end
		res << arr2
	end
	res = res.join(' ')
	return (res)
end

if count >= 1
	puts "#{my_special_trim(arr[0])}"
else 
	print
end
