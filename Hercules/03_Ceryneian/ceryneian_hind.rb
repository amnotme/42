require 'oauth2'

client = OAuth2::Client.new(ENV['HID'], ENV['HSECRET'], site: "https://api.intra.42.fr")
token = client.client_credentials.get_token

begin
  f = File.open(ARGV[0])
  arr = []
  f.each do |line|
  	arr << line.tr("\n","") unless line.nil?
  end
  (0...arr.length).each do |i|
    begin
    response = token.get("/v2/users/#{arr[i]}/locations?filter[active]=true")
    puts "\033[0;32m#{arr[i]} \033[0;36m : \033[1;35m #{response.parsed[0]['host']}\033[0m" if response.parsed[0] && response
    puts "\033[0;32m#{arr[i]} \033[0;36m : \033[1;31m The user is not at the lab 🤬" if !response.parsed[0]
    rescue
    puts "\033[0;32m#{arr[i]} \033[0;36m : \033[1;31m The user doesn't exist 🤪"
    end
  end
rescue
	puts "\033[1;32musage: ruby ceryneian_hind.rb \033[1;34m[\033[1;35mfile name\033[1;34m]\033[0m"
end
