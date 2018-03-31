# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.rb                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/30 21:37:30 by lhernand          #+#    #+#              #
#    Updated: 2018/03/31 00:05:44 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require 'fileutils'

def create_ignore
	open(".gitignore", 'w') do |f|
		f.puts '# Compiled source #'
		f.puts '###################'
		f.puts '*.com'
		f.puts '*.class'
		f.puts '*.dll'
		f.puts '*.exe'
		f.puts '*.o'
		f.puts '*.so'
		f.puts 
		f.puts '# Packages #'
		f.puts '############'
		f.puts '# it\'s better to unpack these files and commit the raw source'
		f.puts '# git has its own built in compression methods'
		f.puts '*.7z'
		f.puts '*.dmg'
		f.puts '*.gz'
		f.puts '*.iso'
		f.puts '*.jar'
		f.puts '*.rar'
		f.puts '*.tar'
		f.puts '*.zip'
		f.puts 
		f.puts '# Logs and databases #'
		f.puts '######################'
		f.puts '*.log'
		f.puts '*.sql'
		f.puts '*.sqlite'
		f.puts 
		f.puts '# OS generated files #'
		f.puts '######################'
		f.puts '.DS_Store'
		f.puts '.DS_Store'
		f.puts '._*'
		f.puts '.Spotlight-V100'
		f.puts '.Trashes'
		f.puts 'ehthumbs.db'
		f.puts 'Thumbs.db'
	end
end

def	make_author
	File.open('author', 'w') do |f|
		f.puts "#{ENV['USER']}"
	end
end

def make_file(file_name)
	File.open(file_name, 'w') do |f|
		f.puts "#Your file has been created ^_^#"
		f.puts 
	end
end

def make_makefile
	File.open("Makefile", 'w') do |f|
		f.puts "MAKE = make -C"
		f.puts "LIB = libft"
		f.puts "NAME ="
		f.puts "CC = gcc"
		f.puts "CFLAGS = -Wall -Wextra -Werror"
		f.puts "CFILES = $(LIB)/libft.a"
		f.puts
		f.puts "LIBM = $(MAKE) $(LIB) re"
		f.puts "LIBC = $(MAKE) $(LIB) clean"
		f.puts "LIBF = $(MAKE) $(LIB) fclean"
		f.puts "OBJECTS = $(CFILES:.c=.o)"
		f.puts
		f.puts "all: $(NAME)"
		f.puts
		f.puts "$(NAME):"
		f.puts "		@$(LIBM)"
		f.puts "		@$(CC) $(CFLAGS) -o $(NAME) -I $(CFILES)"
		f.puts
		f.puts "clean:"
		f.puts "		@$(LIBC)"
		f.puts "		@$/bin/rm -f $(OBJECTS)"
		f.puts
		f.puts "fclean:"
		f.puts "		@$(LIBF)"
		f.puts "		@$(/bin/rm -f $(OBJECTS) $(NAME)"
		f.puts
		f.puts "re: fclean all"
		f.puts
		f.puts ".PHONY: all, clean, fclean, re"
	end
end

def make_src
	dir_name = "/src"
	lib_name = "/libft"
	begin
		Dir.mkdir("#{ENV['PWD']}#{dir_name}")
	rescue
		puts "Your src folder is already there... so I'm just going to leave that alone"
	end
end

def copy_src
	dest_folder = "#{Dir.getwd}/src/"
	puts "Where's your libft? "
	lib_dir = gets.chomp.strip
	lib_dir = Dir["#{lib_dir}/*"]
	lib_dir.each do |file|
		name = File.basename(file, '*')
		dest_file = "#{dest_folder}#{name}"
		FileUtils.cp(file, dest_file)
	end
end

if $PROGRAM_NAME == __FILE__
	print "Enter the name of the file including extension appended to it => "
	name = gets.strip.chomp
	if name.include?('.c')
		make_author
		make_makefile
		make_file(name)
		puts "do you have a libft you'd like to include?"
		lib = gets.strip.chomp.downcase
		if lib == 'yes' || lib == 'y'
			make_src
			copy_src
		end
	else
		make_file(name)
	end
	create_ignore
end
