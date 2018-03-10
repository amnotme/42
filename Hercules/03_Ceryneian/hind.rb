require 'oauth2'
 require 'open-uri'
f = File.open("test.txt")
	f.each_with_index do |line|
		puts line
	end
p f

UID = "Your application uid"
SECRET = "Your application secret"
client = OAuth2::Client.new(UID, SECRET, site: "https://api.intra.42.fr")
token = client.client_credentials.get_token

response = token.get("/v2/locations/4")
response.status
# => 200
response.parsed
f.close
