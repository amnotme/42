# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mail.rb                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhernand <lhernand@student.42.us.or>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/20 20:35:33 by lhernand          #+#    #+#              #
#    Updated: 2018/04/20 23:38:34 by lhernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Learn about how email works and and can be used in a program.
# For this labour you write a program to send mail via SMTP
# You must use a langauge other than BASH.
#

# using SendGrid's Ruby Library
# https://github.com/sendgrid/sendgrid-ruby
require 'sendgrid-ruby'
include SendGrid

from = Email.new(email: 'leopoldo.hernandez.oliva@gmail.com')
to = Email.new(email: 'leopoldo.hernandez.oliva@gmail.com')
subject = 'Sending with SendGrid is Fun'
content = Content.new(type: 'text/plain', value: 'and easy to do anywhere, even with Ruby')
mail = Mail.new(from, subject, to, content)

sg = SendGrid::API.new(api_key: ENV['SENDGRID_API_KEY'])
response = sg.client.mail._('send').post(request_body: mail.to_json)
puts response.status_code
puts response.body
puts response.headers

